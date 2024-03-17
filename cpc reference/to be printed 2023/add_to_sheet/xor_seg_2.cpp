// xor segment tree v2 (queries with bs)
// Problem: F. Minimal String Xoration

// By AmmarDab3an 

const int  MAX = 2e5 + 10;
const int NMAX = (1<<18) + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
string str;

array<int, 2> p, m;
vector<array<int, 2>> pow_m;

bool is_prime(int x){
	for(ll i = 2; i*i <= x; i++) if(x%i==0){
		return false;
	}
	return true;
}

void init_hash(){
	
	p = {rand(1e4, 5e4), rand(6e4, 9e4)};
	m = {53, 79};
	
	while(!is_prime(p[0])) p[0]++;
	while(!is_prime(p[1])) p[1]++;
	
	pow_m.resize(NMAX);	
		
	pow_m[0][0] = pow_m[0][1] = 1;
	
	for(int i = 1; i < NMAX; i++)
	for(int j = 0; j < 2; j++){
		pow_m[i][j] = (pow_m[i-1][j] * m[j])%p[j];
	}
}

vector<array<int, 2>> tree[NMAX << 2];

void build(int nd, int l, int r, int p){
	
	if(l==r){
		array<int, 2> cur;
		cur[0] = cur[1] = str[l]-'a'+1;
		tree[nd].push_back(cur);
		return;
	}	
	
	int mid = (l+r)/2;
	build(nd*2, l, mid, p-1);
	build(nd*2+1, mid+1, r, p-1);
	
	for(int i = 0; i < (1<<(p-1)); i++){
		
		array<int, 2> a = tree[nd*2][i];
		array<int, 2> b = tree[nd*2+1][i];
		
		array<int, 2> cur;
		for(int j = 0; j < 2; j++){
			cur[j] = (a[j] * pow_m[1<<(p-1)][j] + b[j]) % ::p[j];
		}
		tree[nd].push_back(cur);
	}
	
	for(int i = 0; i < (1<<(p-1)); i++){
		
		array<int, 2> a = tree[nd*2][i];
		array<int, 2> b = tree[nd*2+1][i];
		
		array<int, 2> cur;
		for(int j = 0; j < 2; j++){
			cur[j] = (b[j] * pow_m[1<<(p-1)][j] + a[j]) % ::p[j];
		}
		tree[nd].push_back(cur);
	}
}

array<int, 2> query(int nd, int l, int r, int p, int x, int q_l, int q_r){
	
	
	if(r < q_l || q_r < l){
		return (array<int, 2>){0, 0};
	}
	
	if(q_l <= l && r <= q_r){
		
		array<int, 2> cur = tree[nd][x];
		
		for(int j = 0; j < 2; j++){
			cur[j] = (cur[j] * pow_m[q_r-r][j]) % ::p[j];
		}
		
		return cur;
	}
	
	int mid = (l+r)/2;
	array<int, 2> st_path, nd_path;
	
	if((x>>(p-1))&1){
		x ^= (1<<(p-1));
		st_path = query(nd*2+1, l, mid, p-1, x, q_l, q_r);
		nd_path = query(nd*2, mid+1, r, p-1, x, q_l, q_r);
	}
	else{
		st_path = query(nd*2, l, mid, p-1, x, q_l, q_r);
		nd_path = query(nd*2+1, mid+1, r, p-1, x, q_l, q_r);
	}
	
	array<int, 2> cur;
	for(int j = 0; j < 2; j++){
		cur[j] = (st_path[j] + nd_path[j]) % ::p[j];
	}
	
	return cur;
}

int query_bs(int nd_a, int nd_b, int l, int r, int a, int b, int p){
	
	if(l==r){
		if(tree[nd_a][0]!=tree[nd_b][0]){
			return l;
		}
		else{
			return l+1;
		}
	}	
	
	int mid = (l+r)/2;
	int nd_lf_a = nd_a*2;
	int nd_lf_b = nd_b*2;
	
	if((a>>(p-1))&1) a ^= 1<<(p-1), nd_lf_a ^= 1;
	if((b>>(p-1))&1) b ^= 1<<(p-1), nd_lf_b ^= 1;
	
	if(tree[nd_lf_a][a] != tree[nd_lf_b][b]){
		return query_bs(nd_lf_a, nd_lf_b, l, mid, a, b, p-1);
	}
	else{
		return query_bs(nd_lf_a^1, nd_lf_b^1, mid+1, r, a, b, p-1);
	}
}

bool comp(int a, int b){
	
	int l = 0;
	int r = (1<<n)-1;
	
	// int ans = -1;
	
	// while(l <= r){
// 		
		// int mid = (l+r)/2;
// 		
		// array<int, 2> hash_a = query(1, 0, (1<<n)-1, n, a, 0, mid);
		// array<int, 2> hash_b = query(1, 0, (1<<n)-1, n, b, 0, mid);
// 		
		// if(hash_a==hash_b){
			// ans = mid;
			// l = mid+1;
		// }
		// else{
			// r = mid-1;
		// }
// 		
	// }	
	
	int ans = query_bs(1, 1, 0, (1<<n)-1, a, b, n) -1;
	
	if(ans+1==(1<<n)){
		return false;
	}
	
	char ch_a = str[(ans+1)^a];
	char ch_b = str[(ans+1)^b];
	
	return ch_a < ch_b;
}

int32_t main(){
	
	cin >> n;
	cin >> str;
	
	init_hash();
	
	build(1, 0, (1<<n)-1, n);
	
	int ans = 0;
	for(int i = 1; i < (1<<n); i++){
		if(comp(i, ans)){
			ans = i;
		}
	}
	
	string ans_str(1<<n, '.');
	for(int i = 0; i < (1<<n); i++){
		ans_str[i] = str[i^ans];
	}
	
	cout << ans_str << endl;
}
