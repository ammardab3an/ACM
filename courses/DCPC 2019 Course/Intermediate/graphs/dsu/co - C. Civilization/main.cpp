#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define fr first
#define sc second
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double>
#define mp make_pair
using namespace std;

vector<int>p[300300];
bool v[300300];
int comp[500500];
int len[300300];

pii dfs(int x,int k,bool b,int per =-1){
    v[x] =1 ;
    int diam=0;
    comp[x] = k;
    //c[k].insert(x);
    int maxx[]={0,0,0};
    for(int i=0 ; i<p[x].size() ; i++){
        if(!v[p[x][i]]){
            pii t = dfs(p[x][i],k,0,x);
            maxx[0] = t.sc+1;
            diam = max(diam,t.fr);
        }
        sort(maxx,maxx+3);
    }
    diam = max(diam,maxx[1]+maxx[2]);

    return mp(diam,maxx[2]);
}

int get(int x){
    if(comp[x] == x){
        return x;
    }
    return comp[x] = get(comp[x]);
}

int main(){
    int n,m,q,x,y;
    cin>>n>>m>>q;
    for(int i=0 ; i<m ; i++){
        scanf("%d%d",&x,&y);
        p[x].push_back(y);
        p[y].push_back(x);
    }
    for(int i=1 ; i<=n ; i++){
        if(!v[i]){
            len[i] = dfs(i,i,1).fr;
        }
    }
    int t,r;
    for(int i=0 ; i<q ; i++){
        scanf("%d%d",&t,&x);
        if(t == 1){
            printf("%d\n",len[get(x)]);
        }
        else{
            scanf("%d",&y);
            int h1 = get(x);
            int h2 = get(y);
            if(h1 != h2){
                r = ceil(1.0*len[comp[y]]/2);
                r += ceil(1.0*len[comp[x]]/2);
                r++;
                r = max(len[h1],r);
                r = max(len[h2],r);
                len[h1] = len[h2] = r;
                comp[h1] = h2;
            }
        }
    }

    return 0;
}
