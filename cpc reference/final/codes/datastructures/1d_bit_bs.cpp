// bit bs

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

int binaryLifting(int val){

    int ptr = 0;
    int sum = 0;

    for(int i = bitSz/2; i >= 1; i /= 2) {

        if(sum + bit[ptr+i] < val){
            sum += bit[ptr+i];
            ptr += i;
        }
    }

    return ptr+1;
}
