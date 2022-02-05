// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

// Global Variables

const int MAX = 1500 + 10;

int arr[MAX];

int main(){

    int n;
    scanf("%d", &n);

    for(int i =  0; i < n; i++)
        scanf("%d", &arr[i]);

    map<int, vpii> m;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            m[sum].push_back({j, i});
        }
    }

    int ans = 0, cur;
    for(auto &it : m) {

        sort(it.se.begin(), it.se.end());

        int x, cnt = 0;

        for(int i = 0; i < it.se.size(); i++){
            if(i == 0){
                x = it.se[i].fi;
                cnt++;
            }
            else if(it.se[i].se > x){
                x = it.se[i].fi;
                cnt++;
            }
        }

        if(cnt > ans){
            ans = cnt;
            cur = it.fi;
        }
    }

    cout << ans << endl;
    int x;
    for(int i = 0; i < m[cur].size(); i++){
        if(i == 0){
            cout << m[cur][i].se+1 << " " << m[cur][i].fi+1 << endl;
            x = m[cur][i].fi;
        }
        else if(m[cur][i].se > x){
            cout << m[cur][i].se+1 << " " << m[cur][i].fi+1 << endl;
            x = m[cur][i].fi;
        }
    }
}
