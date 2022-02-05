
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

    int n, q;
    cin >> n >> q;

    set<int> st;

    priority_queue<iii> que;

    auto add = [&](int x){

        st.insert(x);

        auto it = st.upper_bound(x);
        if(it != st.end())
            que.push({*it-x, {x, *it}});

        it = st.lower_bound(x);
        if(it != st.begin()){
            it--;
            que.push({x-*it, {*it, x}});
        }

    };

    auto del = [&](int x){
        st.erase(st.lower_bound(x));
        auto it = st.lower_bound(x);
        if(it != st.begin()){
            it--;
            add(*it);
        }
    };

    auto get = [&](){

        while(!que.empty()){

            if(st.size() <= 2) return lli(0);

            auto tp = que.top();

            if(!st.count(tp.second.first) || (*st.upper_bound(tp.second.first) != tp.second.second)){
                que.pop();
                continue;
            }

            return *st.rbegin() - *st.begin() - tp.first;
        }

        return lli(0);
    };

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        add(x); 
    }

    vpii queries(q);

    for(auto &p : queries) cin >> p.first >> p.second;

    cout << get() << endl;

    for(auto p : queries){

        if(p.first){
            add(p.second);
        }
        else{
            del(p.second);
        }

        cout << get() << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
