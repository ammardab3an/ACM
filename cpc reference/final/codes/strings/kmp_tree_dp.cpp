// kmp tree dp

int numNode;
int child[NMAX][128];
int childChars[NMAX][128], sz[NMAX];
int fail[NMAX], nxt[NMAX];
int patId[NMAX];

int n;
char ch[128];
double pro[128];

double mem[111][444];
int vis[111][444], vid;

int addNode(){
	memset(child[numNode], -1, sizeof child[numNode]);
	patId[numNode] = -1;
	sz[numNode] = 0;
	return numNode++;
}

void init(){
	numNode = 0;
	addNode();
}

int insert(const string &pat, int id){
	int cur = 0 ;
	for(auto c : pat){
		
		int &nd = child[cur][c];
		
		if(nd==-1){
			nd = addNode();
			childChars[cur][sz[cur]++] = c;
		}
		
		cur = nd;
	}
	return patId[cur]!=-1 ? patId[cur] : (patId[cur] = id);
}

int nxtF(int u, char c){
	
	while(child[u][c]==-1){
		u = fail[u];
	}	
	
	return child[u][c];
}

int get_nxt(int u){
	if(!u) return u;
	int v = nxt[u];
	return nxt[u] = patId[v]!=-1 ? v : get_nxt(v);
}

void computeFail(){
	
	queue<int> que;
	
	for(int i = 0; i < 128; i++){
		int &u = child[0][i];
		if(u != -1){
			nxt[u] = fail[u] = 0;
			que.push(u);
		}
		else{
			u = 0;
		}
	}
	
	while(!que.empty()){
		
		int u = que.front();
		que.pop();
		
		for(int i = 0; i < sz[u]; i++){
			char c = childChars[u][i];
			int v = child[u][c];
			nxt[v] = fail[v] = nxtF(fail[u], c);
			que.push(v);		
		}
	}
}

double go(int rm, int id){
	
	for(int p = id; p; p = get_nxt(p)){
		if(patId[p]!=-1){
			return 0;
		}
	}
	
	if(rm==0){
		return 1;
	}	
	
	if(vis[rm][id]==vid){
		return mem[rm][id];
	}
	else{
		vis[rm][id] = vid;
	}
	
	double ans = 0;
	
	for(int i = 0; i < n; i++){
		
		char c = ch[i];
		double p = pro[i];
		
		ans += p * go(rm-1, nxtF(id, c));
	}
	
	return mem[rm][id] = ans;
}

int32_t main(){
    
    
    int tt = 1;
    int t; cin >> t; while(t--){

		int m;
		cin >> m;
		
		init();
		
		vi names(m);
		
		for(int i = 0; i < m; i++){
			string pat;
			cin >> pat;
			names[i] = insert(pat, i);
		}
		
		computeFail();
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> ch[i] >> pro[i];
		}
		
		int l;
		cin >> l;
		
		vid++;
		
		double ans = go(l, 0);
		cout << "Case #" << tt++ << ": ";
		cout << fixed << setprecision(6) << ans << endl;
    }	
}
