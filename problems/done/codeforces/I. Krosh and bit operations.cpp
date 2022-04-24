// Problem: I. Krosh and bit operations
// Contest: Codeforces - Krosh Kaliningrad Contest 2
// URL: https://codeforces.com/gym/103451/problem/I
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll power(ll x, ll y){
    ll res = 1;
    while(y){
        if(y%2) res = (res * x)%mod;
        y /= 2;
        x = (x*x)%mod;
    }
    return res;
}

int main()
{

    ll n;
    cin >> n;

    string and1, or1, xor1;
    cin >> and1 >> or1 >> xor1;

    bool ok = 1;

    ll ans = 1, temp = power(2, n-1);
    int len = and1.length();
    for(int i = 0; i < len; i++){

        if(and1[i] == '1'){

            if(or1[i] != '1') ok = 0;

            if(xor1[i]-'0' != n%2) ok = 0;

        } else {

            if(or1[i] == '0'){
            	
                if(xor1[i] != '0') ok = 0;
                
            } else {
            	
            	bool b0 = (xor1[i]-'0') == n%2;
            	bool b1 = xor1[i]=='0';
				
				if(b0&&b1){
					ans = (ans*(temp-2))%mod;
				}
				else if(b0||b1){
					ans = (ans*(temp-1))%mod;
				}
				else{
					ans = (ans*temp)%mod;
				}
				
				ans = (ans+mod)%mod;
            }

        }

    }

    if(!ok) ans = 0;
    cout << ans << endl;

}
