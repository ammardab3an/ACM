// Problem: E2. PermuTree (hard version)
// Contest: Codeforces - Codeforces Round 890 (Div. 2) supported by Constructor Institute
// URL: https://codeforces.com/contest/1856/problem/E2
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
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
 
const int NMAX = 1e6 + 10;

int n;
vi adj[NMAX];
int sub[NMAX];
int ans = 0;

template<int len = 1>
int go(const vi &vals, int sm){
	
	if(sm >= len){
		return go<min(len*2, NMAX)>(vals, sm);
	}
	
	bitset<len> bs;
	
	bs[0] = 1;
	for(auto i : vals){
		bs |= bs << i;
	}
	
	return bs._Find_next((sm-1)/2);
}

int calc(vi tmp, int sm){
	
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());
	tmp.push_back(-1);
	
	if(tmp.front()*2 >= sm){
		return tmp.front();
	}
	
	vi ntmp;
	
	int lst = tmp[0];
	int cnt = 1;
	
	for(int i = 1; i < tmp.size(); i++){
	
		if(tmp[i]==lst){
			cnt++;
		}
		else{		
			
			int x = 1;
			while(x < cnt){
				ntmp.push_back({x * lst});
				cnt -= x;
				x *= 2;
			}
			
			ntmp.push_back({cnt * lst});
			
			lst = tmp[i];
			cnt = 1;
		}
	}	
	
	return go(ntmp, sm);
}

void dfs(int u){
	
	sub[u] = 1;
	
	if(adj[u].empty()){
		return;
	}
	
	vi tmp;
	for(auto v : adj[u]){
		dfs(v);
		tmp.push_back(sub[v]);
		sub[u] += sub[v];
	}	
	
	int x = calc(tmp, sub[u]-1);
	ans += x * (sub[u]-1 - x);
}

int32_t main(){
    
    fastIO;
	
	cin >> n;
	for(int i = 1; i < n; i++){
		int p;
		cin >> p;
		p--;
		adj[p].push_back(i);
	}
	
	dfs(0);
	
	cout << ans << endl;
}
