#include<bits/stdc++.h>

using namespace std ;

const int NMAX = 2e5 + 10;
const int MAX = 1 << int(ceil(log2(double(NMAX))));

int bitSz;
int bit[MAX];

void bitUpdate(int idx, int val){

    // use (i <= bitSz), NOT (i <= n), unless if (bitSz == n);

    for(int i = idx; i <= bitSz; i += i & (-i))
        bit[i] += val;
}

int bitQuery(int idx){
    int res = 0;
    for(int i = idx; i >= 1; i -= i & (-i))
        res += bit[i];
    return res;
}

int bsBit(int val){

    int l = 1;
    int r = bitSz;
    int ans = -1;

    while(l <= r){

        int mid = (l + r)/2;

        if(bitQuery(mid) < val){
            l = mid+1;
        }
        else{
            ans = mid;
            r = mid-1;
        }

    }

    return ans;
}

int bsBit2(int val){

    int l = 1;
    int r = bitSz;

    while(l < r){
        int mid = (l + r)/2;
        if(bitQuery(mid) < val)
            l = mid+1;
        else
            r = mid;
    }

    return r;
}

int binaryLifting(int val){

    int ptr = 0;
    int sum = 0;

    for(int i = bitSz/2; i >= 1; i /= 2) {

        if(sum + bit[i] < val){
            sum += bit[i];
            ptr += i;
        }
    }

    return ptr+1;
}

int main()
{
    int n, q;
    cin >> n >> q ;

    // in order to do fast binary search on bit, the size of the tree must be a power of two
    bitSz = 1 << int(ceil(log2(double(n)));
    cout << bitSz << endl;

    // note that in binary-indexed-tree (i) start from 1, NOT 0;

    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        bitUpdate(i, val);
    }

    while( q-- )
    {
        int fn;
        cin >> fn;

        if( fn < 3 )
        {
            int idx, val;
            cin >> idx >> val ;

            if( fn == 1 )
                bitUpdate( idx, +val ) ;
            else
                bitUpdate( idx, -val ) ;
        }
        else if(fn == 3)
        {
            int l, r;
            cin >> l >> r ;

            int ans = bitQuery(r);
            // not necessary because bit[0] = 0;
            if(l) ans -= bitQuery(l-1);

            cout << ans << endl ;
        }
        else{
            int val;
            cin >> val;
            cout << bsBit(val) << endl;
            cout << bsBit2(val) << endl;
            cout << binaryLifting(val) << endl;
        }
    }

}
