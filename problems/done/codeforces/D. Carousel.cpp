// Problem: D. Carousel
// Contest: Codeforces - Codeforces Round #629 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1328/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int n;
int arr[NMAX];
bool mem[NMAX][2];
int vis[NMAX][2], vid;

bool go(int i, int lst){
    
    if(i == n-1){
        
        if(arr[0] == arr[n-1]){
            return 1;
        }
        else{
            if(arr[n-2] != arr[n-1])
                return lst == 0;
            else
                return 1;
        }
    }    
    
    if(vis[i][lst] == vid) 
        return mem[i][lst];
    vis[i][lst] = vid;
    
    bool ans = false;
    
    if(arr[i-1] == arr[i]){
        ans = go(i+1, lst) || go(i+1, !lst);
    }
    else{
        ans = go(i+1, !lst);
    }
    
    return mem[i][lst] = ans;
}

void calc(int i, int lst){
    
    if(i == n-1){
        
        if(arr[0] == arr[n-1]){
            cout << !lst + 1 << ' ';
        }
        else{
            if(arr[n-2] != arr[n-1])
                cout << !lst +1 << ' ';
            else
                cout << 2 << ' ';
        }
        
        return;
    }   
    
    if(arr[i-1] == arr[i]){
        
        if(go(i+1, lst)){
            cout << lst+1 << ' ';
            calc(i+1, lst);
        }
        else{
            cout << !lst+1 << ' ';
            calc(i+1, !lst);
        }
    }
    else{
        cout << !lst+1 << ' ';
        calc(i+1, !lst);
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){
        
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        vi ans(n);
        int cnt = 1;
        
        ans[0] = 0;
        for(int i = 1; i < n; i++){
            
            if(arr[i-1] == arr[i]){
                ans[i] = ans[i-1];
            }
            else{
                ans[i] = !ans[i-1];    
                cnt = 2;    
            }
        }
        
        if((arr[0] != arr[n-1]) && (ans[0] == ans[n-1])){
            cnt++;
            ans[n-1] = 2;
        }
        
        vid++;
        if(cnt < 3 || !go(1, 0)){
            cout << cnt << endl;
            for(int i = 0; i < n; i++) cout << ans[i]+1 << ' ' ; cout << endl;
        }
        else{
            cout << 2 << endl;
            cout << 1 << ' ';
            calc(1, 0);    
        }
        
    }	
}

/*
  arrays sizes 
  INFLL & 1ll]
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
