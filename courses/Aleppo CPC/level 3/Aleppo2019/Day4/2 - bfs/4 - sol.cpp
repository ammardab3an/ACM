#include <bits/stdc++.h>
using namespace std;


bool vis[20020]= {0};
queue< pair<int,string> >Q;

int main()
{

    int t,n;
    scanf("%d",&t);

    while(t--)
    {

        scanf("%d",&n);
        if( n < 2 )
        {
            printf("%d\n",n);
            continue;
        }
        while( !Q.empty())Q.pop();
        memset(vis,0,sizeof vis);

        string s;
        int mod;
        Q.push( {1,"1"} );

        while( 1 )
        {
            s = Q.front().second;
            mod = Q.front().first;
            Q.pop();

            if( mod == 0 )
            {
                printf("%s\n", s.c_str()  );
                break;
            }
            if( vis[mod] )continue;
            vis[mod]=1;

            Q.push( { (mod*10)%n   ,s+"0" } );
            Q.push( { (mod*10 +1)%n,s+"1" } );

        }

    }


    return 0;
}
