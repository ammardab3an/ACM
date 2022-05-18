// Problem: H. Happy Bus Trip
// Contest: Codeforces - STAR Contest 2022
// URL: https://starcontest22.contest.codeforces.com/group/ZbfYu7B821/contest/378214/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}
 
const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    int n, m, p;
    cin >> n >> m >> p;
    
    vector<vector<pair<pii, pii> >> tmp(p+1);
    
    int x_ans = 0;
    
    for(int i = 0; i < n; i++){
    	
    	int a, b;
    	cin >> a >> b;
    	
    	int l, r;
    	cin >> l >> r;
    	l--, r--;
    	
    	tmp[l].push_back({{0, i}, {a, b}});
    	tmp[r].push_back({{1, i}, {a, b}});
    }
    
    int ans = 0;
    int cans = 0;
    multiset<pii> used, un_used;
    
    vi is_used(n);
    
	for(int i = 0; i < p; i++){
		
		for(auto p : tmp[i]){
			
			int k = p.first.first;
			int i = p.first.second;
			int a = p.second.first;
			int b = p.second.second;
			
			if(!k){
				
				if(b >= a){
					cans += b;	
				}
				else{
					
					cans += b;
					
					if((int)used.size() == m){
						
						if(used.begin()->first < (a-b)){
							
							pii tmp = *used.begin();
							used.erase(used.begin());
							is_used[tmp.second] = false;							
							un_used.insert(tmp);
							cans -= tmp.first;
							
							used.insert({a-b, i});
							is_used[i] = true;
							cans += a-b;
							
						}
						else{
							un_used.insert({a-b, i});
							is_used[i] = false;
						}
					}
					else{
						used.insert({a-b, i});
						is_used[i] = true;
						cans += a-b;
					}
				}
			}
			else{
				
				if(b >= a){
					cans -= b;	
				}
				else{
					
					cans -= b;
					
					if(is_used[i]){
						
						used.erase(used.find({a-b, i}));
						is_used[i] = false;
						cans -= a-b;
						
						if(un_used.size()){
							pii tmp = *un_used.rbegin();
							un_used.erase(un_used.find(tmp));
							used.insert(tmp);
							is_used[tmp.second] = true;
							cans += tmp.first;
						}
					}
					else{
						un_used.erase(un_used.find({a-b, i}));
						is_used[i] = false;
					}
				}
			}
			
		}
// 		
		// for(auto p : used){
			// cout << "u " << p.first << ' ' << p.second << endl;
		// }
		// for(auto p : un_used){
			// cout << "n " << p.first << ' ' << p.second << endl;
		// }
		// cout << cans << endl;
		
		ans += cans;
	}   
	
	cout << ans << endl;
}
