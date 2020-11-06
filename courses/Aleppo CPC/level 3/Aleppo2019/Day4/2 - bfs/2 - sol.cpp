#include <bits/stdc++.h>

using namespace std;

int dis[10][10] , inf = 1000000 ;
int dx[]= {2,2,  -1,1 , -2,-2,  -1,1 , };
int dy[]= {1,-1,  2,2 ,  1,-1,  -2,-2 ,};


bool inside(int i,int j)
{
    return 1<=i && i<=8 && 1<=j && j<=8 ;
}


void bfs(int xs,int ys)
{

    for(int i=1; i<=8; i++)
        for(int j=1; j<=8; j++)
            dis[i][j]=inf;

    dis[xs][ys]=0;

    queue< pair<int,int>  >q;
    q.push( make_pair(xs,ys) );


    while( ! q.empty() )
    {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k=0; k<8; k++)
        {

            int nx=x+dx[k] , ny=y+dy[k] ;

            if( inside(nx,ny) && dis[nx][ny]==inf )
            {

                dis[nx][ny]=1+dis[x][y] ;
                q.push( make_pair(nx,ny) );

            }
        }
    }
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {

        string a, b ;
        int xs , xd , ys , yd ;
        cin>>a>>b;
        xs=a[0]-'a'+1 ;
        ys=a[1]-'0'   ;
        xd=b[0]-'a'+1 ;
        yd=b[1]-'0'   ;

        bfs(xs,ys);
        cout<<dis[xd][yd]<<endl;

    }
    return 0;
}
