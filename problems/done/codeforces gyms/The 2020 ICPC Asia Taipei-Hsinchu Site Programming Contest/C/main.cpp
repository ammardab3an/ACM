#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>

using namespace std;

int arr[10010][10010];

int solve(int n, int k){

    memset(arr, 0, sizeof arr);

    arr[0][0] = k;

    int ans_j = 0;

    for(int l = 0; l < n; l++){

        for(int i = l; i >= 0; i--){

            int j = l-i;

            arr[i+1][j] += (arr[i][j]+1)/2;
            arr[i][j+1] += arr[i][j]/2;
        }

        if(l!=n-1 && arr[l-ans_j][ans_j]%2==0){
            ans_j++;
        }

    }

    return ans_j;
}

int main(){

    int t; cin >> t; while(t--){
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}
