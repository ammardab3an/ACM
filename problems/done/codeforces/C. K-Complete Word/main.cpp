// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

const int MAX = 2e5;

int main(){

    int t; cin >> t; while(t--){

        int n, m;
        cin >> n >> m;

        string str;
        cin >> str;

        int ans = 0;

        for(int j = 0; j < m/2; j++){

            int arr[26]({});

            for(int k = 0; k < n/m; k++){
                arr[str[k*m + j]     - 'a']++;
                arr[str[k*m + m-j-1] - 'a']++;
            }

            ans += n*2/m - *max_element(arr, arr+26);
        }

        if(m % 2){

            int arr[26]({});

            int j = m/2;
            for(int k = 0; k < n/m; k++)
                arr[str[k*m +j] - 'a']++;

            ans += n/m - *max_element(arr, arr+26);
        }

        cout << ans << endl;
    }
}
