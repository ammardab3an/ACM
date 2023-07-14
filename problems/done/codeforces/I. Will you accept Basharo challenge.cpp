// Problem: I. Will you accept Basharo challenge?
// Contest: Codeforces - Al-Baath Collegiate Programming Contest 2023
// URL: https://codeforces.com/gym/104447/problem/I
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

// #define int int64_t
// #define ll  int64_t

typedef unsigned int        uint;
typedef long long int       ll;
typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

const int NMAX = 5e4 + 10;
const int AMAX = 5e4 + 10;

int arr[NMAX];
vi adj[NMAX];
int ans[NMAX], cans;
int frq0[AMAX];
int frq1[AMAX];
vi factors[AMAX];
int sub[NMAX];
map<pii, int> edge_id;

vector<int> prime;
bool not_prime[AMAX];
int mob[AMAX];

void mobius(int n = AMAX){
	
	mob[1] = 1;
	
	for(int i = 2; i < n; i++){
		
		if(!not_prime[i]){
			prime.push_back(i);
			mob[i] = -1;
		}
		
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			
			not_prime[i * prime[j]] = true;
			
			if (i % prime[j] == 0){
				mob[i * prime[j]] = 0;
				break;	
			}
			else{
				mob[i * prime[j]] = mob[i] * mob[prime[j]];
			}
		}
	}	
}

void init_factors(){
	for(int i = 1; i < AMAX; i++)
	for(int j = i; j < AMAX; j+=i){
		factors[j].push_back(i);
	}
}

void dfs(int u, int p){
	sub[u] = 1;
	if(p != -1) adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
	for(auto &v : adj[u]) if(v != p){
		dfs(v, u);
		sub[u] += sub[v];
		if(sub[v] > sub[adj[u][0]]){
			swap(v, adj[u][0]);
		}
	}
}

void add(int u, int d){
	for(auto f : factors[arr[u]]){
		cans -= mob[f] * (frq0[f]-frq1[f]) * frq1[f];
		frq1[f] += d;
		cans += mob[f] * (frq0[f]-frq1[f]) * frq1[f];
	}
}

void add(int u, int p, int d){
	add(u, d);
	for(auto v : adj[u]) if(v != p){
		add(v, u, d);
	}	
}

void calc(int u, int p, bool keep){
	
	for(auto v : adj[u]) if(v != p) if(v != adj[u][0]){
		calc(v, u, 0);
	}
	
	if(!adj[u].empty()){
		calc(adj[u][0], u, 1);
	}
	
	for(auto v : adj[u]) if(v != p) if(v != adj[u][0]){
		add(v, u, 1);
	}
	
	add(u, 1);
	if(p != -1) ans[edge_id[{u, p}]] = cans;
	
	if(!keep){
		add(u, p, -1);
	}
}

int32_t main(){
    
    fastIO;
    
	int n;
	cin >> n;
	
	mobius();
	init_factors();
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		for(auto f : factors[arr[i]]){
			frq0[f]++;
		}
	}
	
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edge_id[{u, v}] = edge_id[{v, u}] = i;
	}
	
	if(n==0){
		n = 5e4;
		// fill(arr, arr+n, 1);
		iota(arr, arr+n, 1);
		for(int i = 0; i < n; i++){
			for(auto f : factors[arr[i]]){
				frq0[f]++;
			}
		}
		rng = mt19937(0);
		for(int i = 1; i < n; i++){
			adj[i-1].push_back(i);
			adj[i].push_back(i-1);
			edge_id[{i-1, i}] = edge_id[{i, i-1}] = i;
		}
	}
	
	dfs(0, -1);
	calc(0, -1, 0);
	
	for(int i = 1; i < n; i++){
		cout << ans[i] << ' ';
	}
}
