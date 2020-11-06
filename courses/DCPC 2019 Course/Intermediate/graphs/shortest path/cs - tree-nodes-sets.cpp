#include <bits/stdc++.h>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair

using namespace std;

const int N = 1e5+10;
vector<int>p[N];
vector<int>pro[N];
int res[N];
int sz =0 ;
int rep[N];

void dfs(int x){
    vector<pii>del;
    for(int i=0 ;i <pro[x].size() ;i ++){
        int val = pro[x][i];
        if(val > 0){
            if(!rep[val])
                sz++;
            rep[val]++;
        }
        else{
            val *= -1;
            if(!rep[val])continue;
            sz--;
            del.push_back({val,rep[val]});
            rep[val] = 0;
        }
    }

    res[x] = sz;

    for(int i=0 ;i <p[x].size() ;i ++){
        dfs(p[x][i]);
    }

    for(int i=0 ;i <del.size() ; i++){
        rep[del[i].fr] = del[i].sc;
        sz++;
    }

    for(int i=0 ;i <pro[x].size() ;i ++){
        int val = pro[x][i];
        if(val > 0){
            rep[val]--;
            if(!rep[val])
                sz--;
        }
    }
}

int main(){

    int n;
    cin>>n;

    int per;
    for(int i=2 ;i <=n; i ++){
        scanf("%d",&per);
        p[per].push_back(i);
    }
    int k,x;
    for(int i=1; i<=n ; i++){
        scanf("%d",&k);
        for(int j=0 ;j <k ; j++){
            scanf("%d",&x);
            pro[i].push_back(x);
        }
    }

    dfs(1);

    for(int i=1 ; i <=n ;i++){
        printf("%d\n",res[i]);
    }

    return 0;
}
