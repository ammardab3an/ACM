// Problem: D. Array Division
// Contest: Codeforces - Educational Codeforces Round 21
// URL: https://codeforces.com/problemset/problem/808/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

const int MAX = 1e5 + 10;

int n;
int arr[MAX];

void solve(){

    cin >> n;

    lli sm = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i], sm += arr[i];

    int ans = false;

    multiset<lli> mst0, mst1(arr, arr+n);

    lli sm0 = 0;
    lli sm1 = sm;
	
    if(sm % 2 == 0) 
    for(int i = 0; i < n; i++){

        if(sm0 == sm1){
            ans = true;
            break;
        }

        if(sm0 < sm1){
            if((sm1 - sm0) % 2LL == 0)
            if(mst1.find((sm1 - sm0)/2LL) != mst1.end()){
                ans = true;
                break;
            }
        }
        else{
            if((sm0 - sm1) % 2LL == 0)
            if(mst0.find((sm0 - sm1)/2LL) != mst0.end()){
                ans = true;
                break;
            }
        }

        sm0 += arr[i];
        sm1 -= arr[i];
        mst0.insert(arr[i]);
        mst1.erase(mst1.find(arr[i]));
    }

    cout << (ans ? "YES" : "NO") << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}