#include<bits/stdc++.h>

using namespace std ;
int n ;
string s ;
int mem[2000][2020] ;
int dp( int l , int r ){
if( l >= r ) return 0 ;
if( mem[l][r] != -1 ) return mem[l][r] ;
if( s[l] == s[r] ) return mem[l][r] = dp( l+1 , r-1 ) ;
return mem[l][r] = 1+min( dp(l+1 , r) , dp( l , r-1 ) ) ;
}
int main(){
memset( mem , -1 , sizeof mem ) ;
cin>>s ;
cout<<dp( 0 , s.length() - 1 )<<endl;
return 0 ;
}
