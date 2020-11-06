#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100100 , M = 26 , inf = 1e9;
char s[N] , t[N];

int dis[M][M];
int n,m;


int main(){

for(int i=0;i<M;i++)
    for(int j=0;j<M;j++)
        dis[i][j]=( (i==j) ? 0 : inf );

scanf("%s",s);
scanf("%s",t);
scanf("%d",&m);
while( m-- ){

        char a[2],b[2];
        int c;
        scanf("%s %s %d",a,b,&c);
        dis[a[0]-'a'][b[0]-'a']=min(dis[a[0]-'a'][b[0]-'a'],c);

    }

for(int k=0;k<M;k++)
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
            dis[i][j]=min( dis[i][j] , dis[i][k]+dis[k][j] );

n = strlen(s);
m = strlen(t);
if( n != m ){
    printf("-1\n");
    return 0;
}

int total=0;
for(int i=0;i<n;i++){

    int k=-1,mn=inf;
    for(int j=0;j<M;j++)
        if( dis[s[i]-'a'][j]+dis[t[i]-'a'][j] < mn ){
            mn = dis[s[i]-'a'][j]+dis[t[i]-'a'][j];
            k = j;
        }
    if( k == -1 ){
        printf("-1\n");
        return 0;
    }

    total += mn;
    s[i]=t[i]=(k+'a');
}

printf("%d\n",total);
printf("%s\n",s);
return 0;
}
