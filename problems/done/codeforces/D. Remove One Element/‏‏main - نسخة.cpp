#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5;

int n;
int arr[MAX];
int mem[MAX][2];

int dp(int pos, bool k){

    int & ret = mem[pos][k];
    if(ret != -1) return ret;

    ret = 1;

    if(     pos+1 < n && arr[pos] < arr[pos+1]) ret = max(ret, 1 + dp(pos+1, k));

    if(k && pos+2 < n && arr[pos] < arr[pos+2]) ret = max(ret, 1 + dp(pos+2, 0));

    return ret;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    memset(mem, -1, sizeof mem);

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp(i, 1));

    cout << ans;
}
