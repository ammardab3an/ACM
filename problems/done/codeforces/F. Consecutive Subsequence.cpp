// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

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

const int MAX = 2e5 + 10;
int arr[MAX];

int main(){

    int n;
    cin >> n;

    map<int, int> dp;
    int ans = 0, lst;
    vi ansVec;

    for(int i = 0; i < n; i++){

        int & num = arr[i]; cin >> num;

        dp[num] = dp[num-1] +1;

        if(dp[num] > ans)
            ans = dp[num], lst = num;
    }

    int cur = lst;
    for(int i = n-1; i >= 0; i--) if(cur == arr[i]){
        ansVec.push_back(i);
        cur--;
    }

    reverse(ansVec.begin(), ansVec.end());

    cout << ans << endl;
    for(int i : ansVec)
        cout << i+1 << ' ';
}
