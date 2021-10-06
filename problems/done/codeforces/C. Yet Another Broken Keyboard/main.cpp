#include<bits/stdc++.h>

using namespace std;


int main()
{
    char c;
    int n, k;
    bool can[26];
    char str[202020];

    memset(can, false, sizeof can);

    cin >> n >> k >> str;

    while(k--)
    {
        cin >> c;
        can[c - 'a'] = true;
    }

    int l = -1;
    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(!can[str[i] - 'a'])
        {
            sum += (long long)(i-1 -l)*(i-1 -l +1)/2;
            l = i;
        }
    }

    sum += (long long)(n-1 - l)*(n-1 -l +1)/2;

    cout << sum;
}
