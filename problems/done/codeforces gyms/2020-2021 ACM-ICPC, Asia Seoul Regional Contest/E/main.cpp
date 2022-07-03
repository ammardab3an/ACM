#include<bits/stdc++.h>

//#define int int64_t
#define endl '\n'

using namespace std;

const int NMAX = 1e6 + 10;

int n;
int arr[NMAX];

int32_t main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    bool bad = false;

    int64_t sum = 0;

    int sz;
    cin >> sz;

    for(int i = 0; i < sz; i++){

        int ai;
        cin >> ai;
        if(ai==0) continue;

        if(ai > 2) bad = true;

        arr[n++] = ai;
        sum += ai;
    }

    if(bad || (sum > (((sz+1)/2)*2)) || (sum%2)){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}
