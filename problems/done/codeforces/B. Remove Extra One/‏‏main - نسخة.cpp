// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 10;

int  arr[MAX];
bool rec[MAX];

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int mx = 0;
    for(int i = 0; i < n; i++){
        rec[i] = mx < arr[i];
        mx = max(mx, arr[i]);
    }

    mx = 0;
    int ansNum, ansCnt = -2;
    for(int i = 0; i < n; i++){

        int _mx = mx;
        int cnt = -rec[i];
        for(int j = i+1; j < n; j++){
            if(arr[i] < arr[j]) break;
            if(!rec[j] && (_mx < arr[j])) cnt++;
            _mx = max(_mx, arr[j]);
        }

        if(ansCnt < cnt)
            ansNum = arr[i], ansCnt = cnt;
        else if(ansCnt == cnt)
            ansNum = min(ansNum, arr[i]);

        mx = max(mx, arr[i]);
    }
    cout << ansNum;
}
