#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

const int NMAX = 400 + 10;

int n;
int arr_a[NMAX], arr_p[NMAX];
int arr_b[NMAX], arr_c[NMAX];
int pre_p[NMAX];
int pos[NMAX];
bool vis[NMAX];
pair<int, int> tmp[NMAX];

signed main(){

    cin >> n;
    for(int i = 0; i < n; i++) cin >> tmp[i].first;
    for(int i = 0; i < n; i++) cin >> tmp[i].second;
    for(int i = 0; i < n; i++) cin >> arr_b[i];
    for(int i = 0; i < n; i++) cin >> arr_c[i];

    sort(tmp, tmp+n);
    for(int i = 0; i < n; i++){
        arr_a[i] = tmp[i].first;
        arr_p[i] = tmp[i].second;
    }

    sort(arr_b, arr_b+n);
    sort(arr_c, arr_c+n);

    pre_p[0] = arr_p[0];
    for(int i = 1; i < n; i++){
        pre_p[i] = pre_p[i-1] + arr_p[i];
    }

    vector<int> rem_b(arr_b, arr_b+n);

    random_shuffle(rem_b.begin(), rem_b.end());

    int ans = 0;

    for(int i = n-1; i >= 0; i--){

        int c = arr_c[i];

        if(i==0){
            assert(rem_b.size()==1);
            int p = lower_bound(arr_a, arr_a+n, rem_b[0]+c)-arr_a;
            if(p) ans += pre_p[p-1];
            break;
        }

        int sm_neg = 0;
        for(auto b : rem_b){
            int p0 = lower_bound(arr_a, arr_a+n, b+c)-arr_a;
            int p1 = lower_bound(arr_a, arr_a+n, b+arr_c[i-1])-arr_a;
            int sm = 0;
            if(p0) sm += pre_p[p0-1];
            if(p1) sm -= pre_p[p1-1];
            sm_neg += sm;
        }

        int mx = -1E18;
        int mx_j = -1;

        for(int j = 0; j < rem_b.size(); j++){

            int b = rem_b[j];
            int p0 = lower_bound(arr_a, arr_a+n, b+c)-arr_a;
            int p1 = lower_bound(arr_a, arr_a+n, b+arr_c[i-1])-arr_a;

            int sm0 = 0;
            if(p0) sm0 += pre_p[p0-1];

            int sm1 = sm0;
            if(p1) sm1 -= pre_p[p1-1];

            int cur = sm0 - (sm_neg - sm1);
            if(cur > mx){
                mx = cur;
                mx_j = j;
            }
        }

        assert(mx_j != -1);

        int b = rem_b[mx_j];
        swap(rem_b[mx_j], rem_b.back());
        rem_b.pop_back();

        int p = lower_bound(arr_a, arr_a+n, b+c)-arr_a;
        if(p) ans += pre_p[p-1];
    }

    cout << ans << endl;
}




