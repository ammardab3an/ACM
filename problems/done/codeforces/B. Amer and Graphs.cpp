// Problem: B. Amer and Graphs
// Contest: Codeforces - ACM International Collegiate Programming Contest, Damascus University Collegiate Programming Contest(2018)
// URL: https://codeforces.com/gym/101808/problem/B
// Memory Limit: 256 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
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
const int MOD0 = 1e9 + 7;
const int MOD1 = 1e9 + 9;

const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b, int MOD){
	return (1ll * a * b) % MOD;
}

int add(int a, int b, int MOD){
	return (1ll * a + b + MOD + MOD) % MOD;
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e3 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

int n;
pii arr[NMAX];
int tmp[NMAX];
pii comp[NMAX]; int comp_sz;

int po0[NMAX*2];
int po1[NMAX*2];

void compress(){

    sort(comp, comp+comp_sz);
    comp_sz = unique(comp, comp+comp_sz) - comp;

    for(int i = 0; i < n; i++){
        tmp[i] = lower_bound(comp, comp+comp_sz, arr[i]) - comp;
    }
}

void init(){

    int p0 = 4007;
    int p1 = 4007;

    po0[0] = 1;
    for(int i = 1; i < NMAX*2; i++){
        po0[i] = mul(po0[i-1], p0, MOD0);
    }

    po1[0] = 1;
    for(int i = 1; i < NMAX*2; i++){
        po1[i] = mul(po1[i-1], p1, MOD1);
    }
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    init();

    int t; cin >> t; while(t--){

        comp_sz = 0;

        cin >> n;
        for(int i = 0; i < n; i++){

            cin >> arr[i].first >> arr[i].second;
            if(arr[i].first > arr[i].second){
                swap(arr[i].first, arr[i].second);
            }

            comp[comp_sz++] = arr[i];
        }

        compress();

        map<pair<int, int>, int> mp;

        int ans = 0;

        for(int l = 0; l < n; l++){

            int cur0 = 0;
            int cur1 = 0;

            for(int r = l; r < n; r++){

                cur0 = add(cur0, po0[tmp[r]], MOD0);
                cur1 = add(cur1, po1[tmp[r]], MOD1);

                ans += mp[{cur0, cur1}];

                mp[{cur0, cur1}] ++;
            }
        }

        cout << ans << endl;
    }
}

/*
  arrays sizes
  INFLL & 1ll
  if its an interactive problem : #define endl '\n'

  notes :


*/