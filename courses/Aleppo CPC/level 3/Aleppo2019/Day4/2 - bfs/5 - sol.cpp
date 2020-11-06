#include <bits/stdc++.h>

using namespace std;

bool prime[10009];
vector< int > next[10009];
int dis[10009];
bool vis[10009];
int a , b ;
const int INF =1e9;


void seive(){
memset(prime,1,sizeof (prime) );
prime[0]=prime[1]=0;
for(int i=2;i*i<=10000;i++)
    if(prime[i])
    for(int j=i*i;j<=10000;j+=i)
    prime[j]=0;
return;
}
void generate_adj(int x){
int n=x;
n/=10; n*=10;
for(int i=1;i<=9;i+=2)if( prime[n+i] )next[x].push_back(n+i);

n=x;  n/=100;  n*=100;  n+=(x%10);
for(int i=0;i<=9;i++) if( prime[n+(10*i)] ) next[x].push_back(n+(i*10));

n=x;  n/=1000;  n*=1000;  n+=(x%100);
for(int i=0;i<=9;i++) if( prime[n+(100*i)] ) next[x].push_back(n+(i*100));

n=x%1000;
for(int i=1;i<=9;i++) if( prime[n+(1000*i)] ) next[x].push_back(n+(i*1000));

}
void f(){
     for(int i=1001;i<=10000;i+=2)  if( prime[i] )  generate_adj(i);
     }
void bfs(){
queue<int>q;
q.push(a);
dis[a]=0;
vis[a]=1;
int x;
while( ! q.empty() ){
x=q.front(); q.pop();

if( x==b ){cout<<dis[b]<<endl;  return ;}
for(unsigned int i=0;i< next[x].size();i++)
if( vis[ next[x][i] ]==0 ){
    q.push( next[x][i] );
    dis[ next[x][i] ]=1+dis[x];
    vis[ next[x][i] ]=1;
}
}
cout<<"Impossible"<<endl;
}


int main()
{
 seive();   f();    int t;  scanf("%d",&t);
while(t--){  scanf("%d %d",&a,&b);   memset(vis,0,sizeof vis );  bfs();  }
    return 0;
}
