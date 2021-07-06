// Problem: I. Binary string
// Contest: Codeforces - ACPC Kickoff 2021
// URL: https://codeforces.com/gym/103158/problem/I
// Memory Limit: 64 MB
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
	return (1ll * a * b) % MOD;
}
 
int add(int a, int b){
	return (1ll * a + b + MOD + MOD) % MOD;
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

int m, k;
pii arr[2020];
bitset<2020> bs;

bool go(){
    
    bs.reset();
    bs.set(0, 1);
    
    for(int i = 0; i < m; i++){
        bs = (bs << arr[i].first) | (bs << arr[i].second);
    }
    
    return bs.test(k);
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    freopen("binary.in", "r", stdin);
    
    int n;
    cin >> n >> k;
    
    string str;
    cin >> str;
    
    int ans = -1;
    
    for(int l = 1; l < n; l++){
        
        vector<vi> tmp(2, vi(l));
        vi cnt(l);
        
        for(int i = 0; i < n; i++) {
            tmp[str[i]-'0'][i%l]++;
            cnt[i%l]++;            
        }
        
        m = l;
        for(int i = 0; i < m; i++){
            arr[i] = {cnt[i] - tmp[0][i], cnt[i] - tmp[1][i]};    
        }
        
        if(go()){
            ans = l;
            break;
        }
    }
    
    cout << ans << endl;
}

