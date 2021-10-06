// Problem: D. Love-Hate
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
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
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
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

int n, m, p;
int arr[NMAX];
int tmp[1 << 15];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    cin >> n >> m >> p;
    
    char bi[100];
    
    for(int i = 0; i < n; i++){
        
        int ai = 0;
        cin >> bi;
        
        for(int j = 0; j < m; j++) if(bi[j]=='1'){
            ai |= 1LL << j;
        }
        
        arr[i] = ai;
    }
    
    
    int ans_msk = 0;
    int ans_cnt = 0;
    
    for(int i = 0; i < 50; i++){
        
        int rand_idx = rand(0, n-1);
        
        int cur_msk = arr[rand_idx];
        
        vi bits;
        for(int i = 0; i < m; i++) if((cur_msk>>i)&1)
            bits.push_back(i);
        
        int l = bits.size();
        
        memset(tmp, 0, sizeof tmp);
        
        for(int i = 0; i < n; i++){
            int cur = 0;
            for(int j = 0; j < l; j++) if((arr[i]>>bits[j])&1){
                cur |= 1 << j;
            }
            tmp[cur] += 1;
        }
        
        for(int i = 0; i < l; i++) for(int msk = 0; msk < (1<<l); msk++){
            if((msk>>i)&1){
                tmp[msk^(1<<i)] += tmp[msk];
            }
        }
        
        for(int msk = 0; msk < (1<<l); msk++){
            
            if(tmp[msk] >= (n+1)/2){
            
                int msk_cnt = __builtin_popcount(msk);
            
                if(msk_cnt > ans_cnt){
                    
                    int dec = 0;
                    for(int i = 0; i < l; i++){
                        dec |= ((msk>>i)&1) << bits[i];
                    }
                    
                    ans_msk = dec;
                    ans_cnt = msk_cnt;
                }
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        cout << char('0'+((ans_msk>>i)&1));
    }
}

/*
  arrays sizes 
  INFLL & 1ll]
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
