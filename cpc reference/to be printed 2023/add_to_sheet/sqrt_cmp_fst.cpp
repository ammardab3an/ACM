// sqrt cmp fst
// Problem: D. ! Divisible
// Contest: Codeforces - ACPC 2022

const int AMAX = 1e6 + 1e4;

const int NMAX = 2e5 + 10;
const int BLOCK = 650;
const int LOG_MAX = ceil(log2(double(NMAX)));

const int PMAX = 1e5 + 10;
const int PBLOCK = 300;
const int PMX = PMAX/PBLOCK + 1;

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct query{
	
	int order;
	int l, r, fix, idx;
	
	bool operator < (const query &other){
		return order < other.order;
	}
};

vi adj[NMAX];
int val[NMAX];
vi primes;
bool not_prime[AMAX];
int prime_pos[AMAX];
int tin[NMAX], tout[NMAX], tim;
int arr[2*NMAX];

bool vis[NMAX];
int pcnt[PMAX];
int blk_sz[PMX];
int blk_osz[PMX];

int depth[NMAX];
int par[NMAX][LOG_MAX];

query queries[NMAX];
int ans[NMAX];

void init_sieve(){
		
	for(ll i = 2; i < AMAX; i++) if(!not_prime[i]){
		prime_pos[i] = primes.size();
		primes.push_back(i);
		for(ll j = i*i; j < AMAX; j+=i){
			not_prime[j] = true;
		}
	}
	
	for(int i = 0; i < primes.size(); i++){
		blk_osz[i/PBLOCK]++;
	}
}

void dfs(int u, int p){
	
	tin[u] = tim;
	arr[tim] = u;
	tim++;
	
	for(auto v : adj[u]) if(v != p){
		
		depth[v] = depth[u]+1;
		
		par[v][0] = u;
		for(int i = 1; i < LOG_MAX; i++){
			par[v][i] = par[par[v][i-1]][i-1];
		}
		
		dfs(v, u);
	}	
	
	tout[u] = tim;
	arr[tim] = u;
	tim++;
}

int lca(int u, int v){
	
	if(depth[u] < depth[v]){
		swap(u, v);
	}
	
	int dif = depth[u] - depth[v];
	
	for(int i = 0; i < LOG_MAX; i++) if((dif>>i)&1){
		u = par[u][i];
	}
	
	if(u==v) return u;
	
	for(int i = LOG_MAX-1; i >= 0; i--) if(par[u][i] != par[v][i]){
		u = par[u][i];
		v = par[v][i];
	}
	
	return par[u][0];
}

void update(int f, int d){
	
	pcnt[f] += d;
	
	if(pcnt[f]==1){
		blk_sz[f/PBLOCK] += 1;
	}
	else if(pcnt[f]==0){
		blk_sz[f/PBLOCK] -= 1;
	}
}

void add(int i){
	
	int u = arr[i];
	if(val[u]==-1) return;
	
	vis[u] ^= 1;
	update(val[u], vis[u] ? +1 : -1);
}

void rem(int i){
	add(i);
}

int get_ans(){
	
	for(int i = 0; i < PMX; i++) if(blk_sz[i] != blk_osz[i]){
		
		assert(blk_sz[i] < blk_osz[i]);
		
		int lo = i*PBLOCK;
		int hi = (i+1)*PBLOCK;
		
		for(int j = lo; j < hi; j++){
			
			assert(j < PMAX);
			
			if(pcnt[j]==0){
				return primes[j];
			}
		}
	}
	
	assert(false);
}

int32_t main(){
    
    fastIO;
	
	init_sieve();
	
	int t; cin >> t; while(t--){
		
		int n;
		cin >> n;
		
		{
			tim = 0;	
			for(int i = 0; i < n; i++){
				adj[i].clear();
			}	
		}
		
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			val[i] = !not_prime[x] ? prime_pos[x] : -1;
		}
		
		for(int i = 1; i < n; i++){
			
			int u, v;
			cin >> u >> v;
			u--, v--;
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		dfs(0, -1);
		
		int q;
		cin >> q;
		
		for(int i = 0; i < q; i++){
			
			int u, v;
			cin >> u >> v;
			u--, v--;
			
			if(depth[u] > depth[v]){
				swap(u, v);
			}
			
			int p = lca(u, v);
			
			if(u==p){
				queries[i] = {0, tin[u], tin[v], -1, i};		
			}
			else{
				queries[i] = {0, tout[u], tin[v], tin[p], i};
			}
		}
		
		for(int i = 0; i < q; i++){
			int l = queries[i].l;
			int r = queries[i].r;
			queries[i].order = hilbertOrder(l, r, 20, 0);
		}
		
		sort(queries, queries+q);
		
		int l = 1, r = 0;
		
		for(int i = 0; i < q; i++){
			
			auto [co, cl, cr, fix, idx] = queries[i];
			
			while(cl < l) add(--l);
			while(r < cr) add(++r);
			while(l < cl) rem(l++);
			while(cr < r) rem(r--);
			
			if(fix != -1){
				add(fix);
			}
			
			ans[idx] = get_ans();
			
			if(fix != -1){
				rem(fix);
			}
		}
		
		while(r >= l){
			rem(r--);
		}
		
		for(int i = 0; i < q; i++){
			cout << ans[i] << endl;
		}
	}
}
