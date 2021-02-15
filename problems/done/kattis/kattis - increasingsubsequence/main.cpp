
#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
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

int n;
int arr[222];
int mem[222][222];

int go(int pos, int lst){

    if(pos == n) return 0;

    int & ret = mem[pos][lst];
    if(~ret) return ret;

    int ans = go(pos+1, lst);
    if(arr[lst] < arr[pos])
        ans = max(ans, go(pos+1, pos) + 1);

    return ret = ans;
}

vi ans, tmp;

bool cmp(vi v0, vi v1){

    if(v0.size() != v1.size())
        return v0.size() > v1.size();

    int sz = v0.size();

    for(int i = 0; i < sz; i++){
        if(v0[i] != v1[i]){
            return v0[i] < v1[i];
        }
    }

    return true;
}

void calc(int pos, int lst){

    if(pos == n){
        if(cmp(tmp, ans)){
            ans = tmp;
        }
        return;
    }

    int curAns = go(pos, lst);

    {
        int stPath = go(pos+1, lst);
        if(curAns == stPath){
            calc(pos+1, lst);
        }
    }

    if(arr[lst] < arr[pos]) {
        int ndPath = go(pos+1, pos) + 1;
        if(curAns == ndPath){
            tmp.push_back(arr[pos]);
            calc(pos+1, pos);
            tmp.pop_back();
        }
    }
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    while(cin >> n, n){

        n++;
        for(int i = 1; i < n; i++) cin >> arr[i];

        arr[0] = -1;
        memset(mem, -1, n * sizeof(mem[0]));
        ans.clear();

        cout << go(1, 0) << ' ';

        calc(1, 0);

        for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' '; cout << endl;
    }
}
