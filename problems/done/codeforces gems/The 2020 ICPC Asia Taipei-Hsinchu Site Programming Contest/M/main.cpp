#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;cin >> t;while(t--){

        int n, m;
        cin >> n >> m;

        int x;
        int tn = n;
        int tm = m;
        while(tn--) cin >> x;
        while(tm--) cin >> x;

        if(n == 1 || m==1){
            cout << 1 << endl;
        }
        else{
            cout << 7 << endl;
        }
    }
}
