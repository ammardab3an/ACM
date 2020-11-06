#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007

using namespace std;

const int N = 1e3+10;
const int INF = 1e9;

int n,m;
string s[N];
ll dist[3][N][N];

int a[]={0,0,-1,1};
int b[]={1,-1,0,0};

void dik(int id){
    priority_queue<pair<int,pii> , vector<pair<int,pii> > , greater<pair<int,pii> > >q;
    for(int i=0 ; i<n ;i ++){
        for(int j=0 ; j<m ; j++){
            if(s[i][j] == id+'1'){
                dist[id][i][j] = 0;
                q.push(mp(0,mp(i,j)));
            }
            else
                dist[id][i][j] = INF;
        }
    }

    while(!q.empty()){
        pair<int,pii> t = q.top();
        q.pop();
        if(t.fr > dist[id][t.sc.fr][t.sc.sc])
            continue;
        for(int k=0 ; k<4  ;k++){
            int x = t.sc.fr + a[k];
            int y = t.sc.sc + b[k];
            if(x <0 || x >= n)
                continue;
            if(y <0 || y >= m)
                continue;
            if(s[x][y] == '#')
                continue;
            if(dist[id][x][y] <=  t.fr+(s[x][y] == '.') )
                continue;
            dist[id][x][y] = t.fr+(s[x][y] == '.') ;
            q.push(mp(dist[id][x][y],mp(x,y)));
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i =0 ;i<n ; i++){
        cin>>s[i];
    }
    ll mn = INF;

    for(int i=0 ; i<3 ;i ++)
        dik(i);
    for(int i=0 ; i<n ;i ++){
        for(int j=0 ; j<m ;j ++){
            if(s[i][j] != '#'){
                mn = min(dist[0][i][j] + dist[1][i][j]+dist[2][i][j]-2*(s[i][j] == '.'),mn);
            }
        }
    }
    if(mn >= INF)
        mn = -1;
    cout<<mn<<endl;
    return 0;
}
