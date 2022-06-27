// Problem: C. Pyramid
// Contest: Codeforces - The 2020 ICPC Asia Taipei-Hsinchu Site Programming Contest
// URL: https://codeforces.com/gym/102835/problem/C
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 


#include<bits/stdc++.h>

using namespace std;

const int NMAX = 1E4 + 10;

int arr[NMAX][NMAX];
int tmp[NMAX][2], sz;

int solve(int n, int k){

	for(int l = 0; l < n; l++){
		memset(arr[l], 0, (l+1) * sizeof(arr[l][0]));
	}
	
    arr[0][0] = k;

    int ans_j = 0;

	for(int i = 0; i < n; i++){
		
		for(int j = 0; j <= i; j++) if(arr[i][j]){
			arr[i+1][j] += (arr[i][j]+1)/2;
			arr[i+1][j+1] += arr[i][j]/2;
		}
		
		if(i != n-1 && arr[i][ans_j]%2==0){
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
