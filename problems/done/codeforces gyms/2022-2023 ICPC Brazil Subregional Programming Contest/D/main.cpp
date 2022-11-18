#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    int cnt0 = 0;
    int cnt1 = 0;

    while((x&1)==0) cnt0++, x >>= 1;
    while((y&1)==0) cnt1++, y >>= 1;

    int mn = min(cnt0, cnt1);
    int ans = n-mn-1;
    cout << ans << endl;
}
