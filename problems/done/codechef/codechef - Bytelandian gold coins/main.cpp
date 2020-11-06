#include<bits/stdc++.h>

using namespace std;

map<long long, long long> dp;

long long go(long long n)
{
    if(!n)
        return 0;

    if(dp[n] != 0)
        return dp[n];

    long long tmp = go(n/2) + go(n/3)+ go(n/4);

    return dp[n] = (tmp > n) ? tmp : n;
}

int main()
{
    long long n;
    while(cin >> n)
        cout << go(n) << endl;
}
