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

#define multiCases false
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Global Variables

const int MAX = 1 << int(1 + log2(1e6));

int bitSz;
int bit[MAX + 10];

void bitWrite(int pos, int val){
    for(int i = pos; i <= bitSz; i += i & (-i))
        bit[i] += val;
}

int bitRead(int pos){
    int sum = 0;
    for(int i = pos; i >= 1; i -= i & (-i))
        sum += bit[i];
    return sum;
}

int bitSearch(int x){

    int ptr = 0;
    for(int i = bitSz/2; i >= 1; i /= 2){
        if(bit[ptr + i] < x){
            x -= bit[ptr + i];
            ptr += i;
        }
    }

    return ptr+1;
}

int binarySearch(int val){

    int l = 1;
    int r = bitSz;

    while(l < r){

        int mid = (l + r)/2;

        if(bitRead(mid) < val)
            l = mid+1;
        else
            r = mid;
    }

    return r;
}

void solve(){

    int n, m;
    cin >> n >> m;

    bitSz = 1 << int(1 + log2(n));

    for(int i = 1; i <= n; i++){
        int val; cin >> val;
        bitWrite(val, 1);
    }


    int cnt = n;

    while(m--){

        int val;
        cin >> val;

        if(val > 0){
            bitWrite(val, 1); cnt++;
        }
        else{
            int ptr = binarySearch(-val);
            bitWrite(ptr, -1); cnt--;
        }
    }


    cout << (cnt ? binarySearch(1) : 0) << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
