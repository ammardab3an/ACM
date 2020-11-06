#include <bits/stdc++.h>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair

using namespace std;

const int N = 1e5+10;
vector<pii>p[N];
bool vis[N];
int sz[N];
int per[N];
set<pii>del;

void dfs(int x,int pp = 0){
    sz[x] = 1;
    per[x] = pp;
    for(int i=0 ;i <p[x].size() ; i++){
        int ch = p[x][i].fr;
        int val = p[x][i].sc;
        if(pp == ch)continue;
        dfs(ch,x);

        sz[x] += sz[ch];

        if(val){
            del.insert({sz[ch],ch});
        }
    }
}

void delet(int x,int pp){

    vis[x] = 1;
    for(int i=0 ;i <p[x].size() ;i ++){
        int ch = p[x][i].fr;
        int val = p[x][i].sc;
        if(pp == ch)continue;
        if(vis[ch])continue;
        delet(ch,x);

        if(val){
            del.erase({sz[ch],ch});
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    k = n-k;
    int a,b,c;
    for(int i=0 ;i <n-1; i++){
        scanf("%d%d%d",&a,&b,&c);
        p[a].push_back({b,c});
        p[b].push_back({a,c});
    }

    dfs(1);
    int res =0;
    while(!del.empty() && k > 0){
        a = (--del.end())->sc;
        k -= (--del.end())->fr;
        del.erase(--del.end());
        delet(a,per[a]);
        res++;
    }
    if(k > 0)res = -1;
    cout<<res<<endl;
    return 0;
}
