// By AmmarDab3na - Aleppo University

#include<bits/stdc++.h>

using namespace std;

void solve(){

    long long x, y, a, b;

    cin >> x >> y >> a >> b;

    b = min(b, 2*a);

    cout << abs(x - y) * a + min(x, y) * b << endl;
}
int main(){
    int t = 1; if(true) cin >> t; while(t--) solve();
}
