// Problem: C. Random Events
// Contest: Codeforces - Codeforces Round #689 (Div. 2, based on Zed Code Competition)
// URL: http://codeforces.com/contest/1461/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t

typedef unsigned int		uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int NMAX = 1e5 + 10;

int n, m, lstpos;

int arr[NMAX];
pair<double, double> com[NMAX];
vector<pair<double, double> > ncom;

double mem[NMAX];
bool  done[NMAX];

double go(int i){
	
	if(i == nm) return 0;
	
	double & ret = mem[i];
	if(done[i]) return ret;
	
	double ans = 0;
	
	ans += ncom[i].second;
	ans += go(i+1) * (double(1) - ncom[i].second);
	
	done[i] = true;
	return ret = ans;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
		
		cin >> n >> m;;
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		for(int i = 0; i < m; i++)
			cin >> com[i].first >> com[i].second;
		
		
		lstpos = n;
		while(lstpos >=1 && arr[lstpos-1] == lstpos) lstpos--;
		
		if(lstpos == 0){
			cout << fixed << setprecision(6) << 1.0 << endl;
			continue;
		}
				
		ncom.clear();
		
		for(int i = 0; i < m; i++){
			if(com[i].first >= lstpos){
				ncom.push_back(com[i]);
			}
		}
		
		nm = ncom.size();
		
		memset(done, 0, sizeof done);
		
		cout << fixed << setprecision(6) << go(0) << endl;
    }	
}
