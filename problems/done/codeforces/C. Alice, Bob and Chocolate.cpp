// Problem: C. Alice, Bob and Chocolate
// Contest: Codeforces - Codeforces Beta Round 6 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/6/C
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

int n , a[100009] , l , r , sum1 , sum2;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
        
    r = n - 1;
    while(l <= r)
    {
        if(sum1 + a[l] <= sum2 + a[r])
        {
            sum1 += a[l];
            l++;
        }
        else
        {
            sum2 += a[r];
            r--;
        }
    }
	
	cout << l << ' ' << n-l << endl;
}