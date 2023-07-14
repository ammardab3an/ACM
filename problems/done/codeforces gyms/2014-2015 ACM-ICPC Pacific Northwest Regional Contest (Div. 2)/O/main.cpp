#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int NMAX = 200 + 10;

int n;
pair<int, int> arr[NMAX];
int mem[NMAX][NMAX];

int go(int i, int lst){

    if(i==n){
        return 0;
    }

    int &ret = mem[i][lst+1];
    if(ret+1) return ret;

    int st_path = go(i+1, lst);
    int nd_path = 0;

    if(lst==-1 ||
       ((arr[i].first > arr[lst].first) && (arr[i].second < arr[lst].second))){
        nd_path = 1 + go(i+1, i);
    }

    int ans = max(st_path, nd_path);
    return ret = ans;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t; while(t--){

        cin >> n;
        for(int i = 0; i < n; i++){
            double a, b;
            cin >> a >> b;
            arr[i] = {a*10, b*10};
        }

        memset(mem, -1, sizeof mem);

        int ans = go(0, -1);
        cout << ans << endl;
    }
}
