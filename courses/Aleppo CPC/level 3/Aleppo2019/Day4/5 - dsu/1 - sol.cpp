#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100100;
int n ;
int par[N] , sz[N];

int getPar(int x){
    if( x == par[x] )return x;
    else      return par[x]=getPar(par[x]);
}

bool mrg(int x,int y){
x = getPar(x);
y = getPar(y);
if( x == y )return 0;
if( sz[x] < sz[y] )swap(x,y);
par[y]=x;
sz[x]+=sz[y];
return 1;
}

int main(){

int t;
scanf("%d",&t);
while( t-- ){

        scanf("%d",&n);
        for(int i=0;i<=n;i++){
                par[i]=i;
                sz[i]=1;
        }

        // let's assume we are given # of queries
        int A=0,B=0;
        int q;
        scanf("%d",&q);
        while( q-- ){

            char c[2];
            int x,y;
            scanf("%s %d %d",c,&x,&y);
            if( c[0] == 'c' )
                mrg(x,y);
            else{
                if( getPar(x) == getPar(y) )
                    A++;
                else
                    B++;
            }

        }
        printf("%d,%d\n",A,B);
}


return 0;
}


/*

2

10
7
c 1 5
c 2 7
q 7 1
c 3 9
q 9 6
c 2 5
q 7 5

1
3
q 1 1
c 1 1
q 1 1


*/
