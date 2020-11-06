#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500500;

int n , q , a[N] ;
int to[N] , idx[N];
int ans[N] ;
pair<int,int> seg[N<<2];

vector< pair<int,int> >qry[N];

void upd(int i,int l,int r,int j,int val,int who){
if( j < l || j > r )return;
if( l == r ){
    seg[i]={val,who};
    return;
}
int m = l+r>>1;
upd(i<<1,l,m,j,val,who);
upd(i<<1|1,m+1,r,j,val,who);
seg[i]=max(seg[i<<1],seg[i<<1|1]);
}

pair<int,int> get(int i,int l,int r,int from,int to){
if( r<from || to<l )return {-1,-1};
if( from<=l&&r<=to )return seg[i];
int m =l+r>>1;
return max( get(i<<1,l,m,from,to) , get(i<<1|1,m+1,r,from,to) );
}

int main(){

scanf("%d",&n);
for(int i=1;i<=n;i++)scanf("%d",a+i);
scanf("%d",&q);
for(int i=1;i<=q;i++){
    int l,r;scanf("%d %d",&l,&r);
    qry[l].push_back( { r , i } );
}

for(int i=1;i<N;i++)idx[i]=N+99;

for(int i=n;i;i--){
    to[i]=idx[a[i]];
    idx[a[i]]=i;
}

for(int i=0;i<4*N;i++)seg[i]={-1,-1};

for(int i=n;i;i--){

    if( to[i] <=n )
    upd(1,1,n,to[i],  -1 ,-1);
    upd(1,1,n,  i  ,to[i],a[i]);

    for(auto p:qry[i]){
        int j = p.first;
        int k = p.second;
        auto x = get(1,1,n,i,j);
        ans[k]=x.second*( x.first>j&&x.second!=-1 );
    }

}
for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
return 0;
}