#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N = 100100 , L= 19;
int n , q ;
int  in[N] ,  out[N], timer ;
int dep[N] , p[N][L];
ll a[N] , seg[N<<3] , lzy[N<<3];
vector<int>adj[N];

void dfs(int u,int pr){
    p[u][0]=pr;
    in[u]=++timer;
    for(auto v:adj[u])if( v != pr ){
            dep[v]=1+dep[u];
            dfs(v,u);
        }
    out[u]=timer;
}

int jump(int u,int k){
    for(int i=0; i<L; i++)
        if( k&(1<<i) )
            u=p[u][i];
    return u;
}

int LCA(int u,int v){
    if( u == v )return u;
    if( dep[u] < dep[v] )swap(u,v);
    int k = dep[u]-dep[v];
    for(int i=0; i<L; i++)
        if( k&(1<<i) )
            u=p[u][i];
    if( u == v )return u;
    for(int i=L-1; i>=0; i--)
        if( p[u][i] != p[v][i] )
            u=p[u][i],v=p[v][i];
    return p[u][0];
}

void push(int nd,int L,int R){
    if(!lzy[nd])return;
    seg[nd]+=1ll*(R-L+1)*lzy[nd];
    if(L!=R){
        lzy[nd<<1  ]+=lzy[nd];
        lzy[nd<<1|1]+=lzy[nd];
    }
    lzy[nd]=0;
}

void update(int nd,int L,int R,int from,int to,ll val){
    push(nd,L,R);
    if( from > R || L > to )return;
    if( from <= L && R <= to )
    {
        lzy[nd]+=val;
        push(nd,L,R);
        return;
    }
    int mid = L+R >>1;
    update(nd<<1  , L,mid ,from,to,val);
    update(nd<<1|1,mid+1,R,from,to,val);
    seg[nd]=seg[nd<<1]+seg[nd<<1|1];
}

ll query(int nd,int L,int R,int from,int to){
    push(nd,L,R);
    if( from > R || L > to )return 0ll;
    if( from <= L && R <= to )return seg[nd];
    int mid = L+R >>1;
    ll ret=0ll;
    ret+=query(nd<<1  , L,mid ,from,to);
    ret+=query(nd<<1|1,mid+1,R,from,to);
    return ret;
}


int main(){

    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++)scanf("%lld",a+i);
    for(int i=1; i<n; i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);

    for(int j=1; j<L; j++)
        for(int u=1; u<=n; u++)
            p[u][j]=p[ p[u][j-1] ][j-1];

    for(int i=1; i<=n; i++)
        update(1,1,n,in[i],in[i],a[i]);

    int u,v,t,lca,root=1;
    ll x;
    while( q-- )
    {
        scanf("%d",&t);
        if( t == 1 )
        {

            scanf("%d",&u);
            root=u;

        }else
        if( t == 2 ){

            scanf("%d %d %lld",&u,&v,&x);
            lca = LCA(u,v);

            if( in[root]<in[lca]||out[lca]<in[root] ){

                update(1,1,n,in[lca],out[lca],+x);

            }else{

                int t1 = LCA(u,root) , t2 = LCA(v,root);
                if( t1 == lca  )swap(t1,t2);
                if( t1 != root ){
                t1 = jump(root,dep[root]-dep[t1]-1);
                update(1,1,n,1,n,+x);
                update(1,1,n,in[t1],out[t1],-x);
                }else
                update(1,1,n,1,n,+x);
            }


        }else{

            scanf("%d",&u);

            if( in[u] > in[root]||in[root]> out[u] )
                printf("%lld\n",query(1,1,n,in[u],out[u]));
            else
            {
                if( root != u ){

                int t1 = jump(root,dep[root]-dep[u]-1);
                ll ans = query(1,1,n,1,n) - query(1,1,n,in[t1],out[t1]) ;
                printf("%lld\n",ans);
                }else{
                printf("%lld\n",query(1,1,n,1,n));
                }
            }
        }
    }

    return 0;
}