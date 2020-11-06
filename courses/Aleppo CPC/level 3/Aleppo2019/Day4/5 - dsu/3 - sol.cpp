#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010;
int n , m , par[N] , price ;
vector< pair< int , pair< int,int> > >edges;

int get(int x){
if( par[x]==x )return x;
par[x]=get( par[x] );
return par[x];
}

bool join(int x,int y){
x=get(x);
y=get(y);
if( x == y )return 0;
if( rand()&1 )swap(x,y);
par[x] = par[y];
return 1;
}

void solve(){

edges.clear();
for(int i=0;i<N;i++)par[i]=i;

scanf("%d",&price);
scanf("%d",&n);
scanf("%d",&m);

while( m-- ){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    edges.push_back( {c,{a,b}} );
}
sort(edges.begin(),edges.end());

int sum =0;
for(auto e:edges){
    int c = e.first;
    int a = e.second.first;
    int b = e.second.second;
    if( join(a,b) )
        sum += c;
}
printf("%d\n",price*sum);
}


int main(){

int t;
scanf("%d",&t);
while( t-- )solve();


return 0;
}
