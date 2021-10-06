#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long fac[200020] , sum = 0;
long long t , n , arr[200020] , fre[35];
int main ()
{
    fac[0] = 1;
    for (int i = 1 ; i <= 200002 ; i++)
        fac[i] = ((fac[i-1]%mod) * ((i)%mod))%mod;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum = 0;
        memset(fre , 0 , sizeof fre);
        map<long long,long long>m;
        for (int i = 0 ; i < n ;i++)
        {
            scanf("%lld" , arr+i);
            m[arr[i]]++;
            for (int j = 0 ; j < 31 ; j++)
                if ((arr[i] >> j) & 1)fre[j]++;
        }
        for (int i = 0 ; i < n ; i++)
        {
            long long num = m[arr[i]];
            for (int j = 0 ; j < 31 ; j++)
            {
                if ((arr[i] >> j) & 1)
                {
                    if (fre[j] != n)
                        goto ss;
                }
            }
            sum += (((num-1)%mod) * (fac[n-2])%mod)%mod , sum %= mod;
            ss:;
        }
        cout << sum << endl;
    }
return 0;
}