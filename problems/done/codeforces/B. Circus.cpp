// Problem: B. Circus
// Contest: Codeforces - Codeforces Round #545 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1138/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>
#define  endl "\n"
using namespace std ;
typedef long long ll;
typedef long double ld ;
const int N=2e7;
const ll inf=1e18 ;
const ll mod = 1e9 + 7 ;
ll mypower(ll x, ll y){
    if(y == 0) return 1 ;
    if(y == 1) return x ;
    ll ret = mypower(x , y / 2);
    ret = (ret * ret) % mod;
    if(y % 2) ret = ( ret * x ) % mod ;
    return ret ;
}
ll n ;
string s , m ;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n ;
    cin >> s >> m ;
    bool is = 0 ;
    ll cnt = 0 , cnt2 = 0 , cnt3 = 0 , cnt4 = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '1' && m[i] == '1')
            cnt4++ ;
        if(s[i] == '0' && m[i] == '0')
            cnt++ ;
        if(s[i] == '1' && m[i] == '0')
            cnt3++ ;
        if(s[i] == '0' && m[i] == '1'){
            cnt2++ ;
        }
    }
    ll ans[] = {0 , 0 , 0 , 0} ;
    
    for(int i = 0 ; i <= cnt3 ; i++){
        for(int j = 0 ; j <= cnt4 ; j++){
            
            ll q = i + j ;
            ll q2 = cnt4 - j;
            ll b = cnt2 - (q - q2);
            ll q3 = (n / 2) - i - j - b ;
            if((q3 + i + j + b == n / 2) && cnt >= q3 && q3 >= 0 && i >= 0  && j >= 0 && cnt2 >= b && b >= 0){
                ans[0] = q3 , ans[1] = b , ans[2] = i , ans[3] = j  ;
                is = 1 ;
            }
        }
    }
//    for(int i = 0 ; i < 4 ; i++){
//        cout << ans[i] << endl ;
//    }
    if(!is){
        cout << -1 << endl ;
        return 0  ;
    }
    for(int i = 0 ; i < n ; i++){
        if(s[i] == '1' && m[i] == '1' && ans[3]){
            ans[3] -- ;
            cout << i + 1 << " " ;
        }
        if(s[i] == '0' && m[i] == '0' && ans[0]){
            ans[0] -- ;
            cout << i + 1 << " " ;
        }
        if(s[i] == '1' && m[i] == '0' && ans[2]){
            ans[2]-- ;
            cout << i + 1 << " " ;
        }
        if(s[i] == '0' && m[i] == '1' && ans[1]){
            ans[1]-- ;
            cout << i + 1 << " " ;
        }
    }
    return 0 ;
}