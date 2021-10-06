// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

//typedef unsigned int        uint;
//typedef long long int       lli;
//typedef unsigned long long  ull;
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

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        int n;
        cin >> n;

        vi vec(n);
        for(auto &i : vec) cin >> i;

        if(n == 1){
            cout << 0 << endl;
            continue;
        }

        set<int> st;

        int s = vec[0];
        for(int i = 1; i < n; i++){
            int c = vec[i] - vec[i-1];
            st.insert(c);
        }

        if(st.size() < 2){
            cout << 0 << endl;
            continue;
        }
        
        if(st.size() > 2){
            cout << -1 << endl;
            continue;
        }

        vi nums;
        for(auto i : st) nums.push_back(i);

        int mx = nums[0];
        for(auto i : nums) mx = max(mx, i);

        int sm = 0;
        for(auto i : nums) sm += abs(i);
        
        int m = sm;
        int c = mx;
        
        bool flag = vec[0] < m;
        
        int pst = vec[0];
        for(int i = 1 ; i < n; i++){
            int ne = (pst + c) % m;
            if(ne != vec[i]){
                flag = false;
                break;
            }
            pst = ne;
        }
        
        if(!flag){
            cout << -1 << endl;
        }
        else{
            cout << sm << ' ' << mx << endl;        
        }
    }	
}