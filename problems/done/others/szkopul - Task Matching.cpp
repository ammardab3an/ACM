// Task Matching (mat)
// https://szkopul.edu.pl/problemset/problem/6b-q_dPI_KRHD3VArapVq7EP/site/?key=statement

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
 
const int NMAX = 1e6 + 10;

int n, m;
int arr[NMAX];
int pat[NMAX];
int pat_f[NMAX];
pii tmp[NMAX];
int pos[NMAX];
int nxt[NMAX][2];

void init(){
	
	for(int i = 0; i < m; i++){
		pos[pat[i]] = i;
	}
	
	for(int i = 0; i < m; i++){
		nxt[i][0] = (pat[i]==0)   ? -1 : pos[pat[i]-1];
		nxt[i][1] = (pat[i]==m-1) ? -1 : pos[pat[i]+1];
	}
	
	for(int i = m-1; i >= 0; i--){
		
		tmp[i].first = nxt[i][0];
		tmp[i].second = nxt[i][1];
		
		if(nxt[i][0] != -1){
			nxt[nxt[i][0]][1] = nxt[i][1];
		}
		
		if(nxt[i][1] != -1){
			nxt[nxt[i][1]][0] = nxt[i][0];
		}
	}
}

int calc_nxt(int i, int arr[], int p){
	
	while(i){
	
		int q = p-i;
		auto [l, r] = tmp[i];
		bool b0 = (l==-1) || (arr[q+l] < arr[p]);
		bool b1 = (r==-1) || (arr[q+r] > arr[p]);
		
		if(b0&&b1) break;
		
		i = pat_f[i-1];
	}	
	
	{	
		int q = p-i;
		auto [l, r] = tmp[i];
		bool b0 = (l==-1) || (arr[q+l] < arr[p]);
		bool b1 = (r==-1) || (arr[q+r] > arr[p]);
		
		if(b0&&b1) i++;
	}
	
	return i;
}

void computer_prefix(){
	for(int i = 1; i < m; i++){
		pat_f[i] = calc_nxt(pat_f[i-1], pat, i);
	}
}

int32_t main(){
    
    fastIO;
    
    cin >> m >> n;
    
    {
	    vi tmp_pat(m);
	    for(auto &i : tmp_pat) cin >> i, --i;
		
	    for(int i = 0; i < m; i++){
	    	pat[tmp_pat[i]] = i;
	    }
    }
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
	
	if(n==0){
		// n = 2e4;
		n = 1e6;
		vi vec = vi(n);
		srand(123);
		iota(vec.begin(), vec.end(), 1);
		random_shuffle(vec.begin(), vec.end());
		for(int i = 0; i < n; i++) arr[i] = vec[i];
	}
    
    init();
    computer_prefix();
    
    vi ans;
    
    int j = 0;
    for(int i = 0; i < n; i++){
    	j = calc_nxt(j, arr, i);
    	if(j==m) ans.push_back(i-m+2);
    }
    
    cout << ans.size() << endl;
    for(auto e : ans) cout << e << ' '; cout << endl;
}
