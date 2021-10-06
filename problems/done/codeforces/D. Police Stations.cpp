#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second

//#define int int64_t
//#define ll int64_t

using namespace std;

typedef unsigned long long  ull;
typedef long long int       ll;
typedef long double         ld;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<ll, ll>        pll;
typedef pair<ll, pll>       lll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<pii>         vpii;

const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const double EPS = 1e-9;

const int MAX = 3e5 + 10;
const int NMAX = 3e5 + 10;

int n, k, d;
vpii adj[NMAX];
bool vist[NMAX];
bool del[NMAX];
queue<pii> que;

int32_t main()
{
   
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> k >> d;
    
    while(k--){
    	int nd; cin >> nd; nd--;
    	que.push({nd, -1});
    }
    
    for(int i = 0; i < n-1; i++){
    	int u, v;
    	cin >> u >> v; u--, v--;
    	adj[u].push_back({v, i});
    	adj[v].push_back({u, i});
    }
    
    while(!que.empty()){
    	
    	auto fr = que.front(); que.pop();

    	int curNd = fr.first;
    	int preNd = fr.second;
    	
    	if(vist[curNd]) continue;
    	
    	vist[curNd] = true;
    	
    	for(auto nxt : adj[curNd]){
    		
    		int nxtNd = nxt.first;
    		int edgId = nxt.second;
    		
    		if(nxtNd == preNd) continue;
    		
    		if(vist[nxtNd]){
    			del[edgId] = 1;
    		}
    		else{
    			que.push({nxtNd, curNd});
    		}
    	}
    }
    
    vi ansVec;
    for(int i = 0; i < n-1; i++) if(del[i]) ansVec.push_back(i+1);
    
    cout << ansVec.size() << endl;
    for(auto nd : ansVec) cout << nd << ' ';
}