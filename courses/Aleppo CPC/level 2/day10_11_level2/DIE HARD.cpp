#include<bits/stdc++.h>


using namespace std ;
int mem[3][2000][2000] ;
int dp( int pos, int h, int r )
{

    if( h <= 0 || r <= 0 ) return 0 ;

    if( mem[pos][h][r] != -1 ) return mem[pos][h][r] ;
    int ans1 = 0, ans2 = 0 ;
    if( pos == 0 )
    {
        ans1 = dp( 1, h + 3, r + 2 ) ;
        ans2 = dp( 2, h + 3, r + 2 ) ;
    }

    if( pos == 1 )
    {
        ans1 = dp( 0, h - 5, r - 10 ) ;
        ans2 = dp( 2, h - 5, r - 10 ) ;
    }
    if( pos == 2 )
    {
        ans1 = dp( 0, h - 20,r + 5 ) ;
        ans2 = dp( 1, h - 20,r + 5 ) ;
    }
    return mem[pos][h][r] = 1 + max( ans1, ans2 ) ;
}
int main()
{
    memset( mem, -1, sizeof mem ) ;
    int h, r ;
    int t ;
    cin>>t ;
    while(t--)
    {
        cin>>h>>r ;
        cout<<dp(0,h,r)-1<<endl;
    }
    return 0 ;
}
