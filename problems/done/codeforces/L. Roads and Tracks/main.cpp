// By AmmarDab3an - Aleppo University


#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;
typedef pair<lli, pii>      lii;
// Global Variables

const int NMAX = 25000 + 10;
const int MMAX = 25;
const lli OO   = 1e18;

int arr[NMAX][MMAX];
int swt[NMAX][MMAX];
pll dis[NMAX][MMAX];

bool operator > (const pll & p1, const pll & p2){
    if(p1.first > p2.first)
        return true;
    if(p1.first == p2.first)
        return p1.second > p2.second;
    return false;
}

bool operator < (const pll & p1, const pll & p2){
    if(p1.first < p2.first)
        return true;
    if(p1.first == p2.first)
        return p1.second < p2.second;
    return false;
}

void solve(){

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        scanf("%d", &arr[i][j]);

    for(int i = 0; i < n  ; i++)
    for(int j = 0; j < m-1; j++)
        scanf("%d", &swt[i][j]);

    for(int i = 0; i <= n; i++)
    for(int j = 0; j <  m; j++)
        dis[i][j].first = OO;

    pll ans = {OO, 0};
    priority_queue< lii, vector<lii>, greater<lii> > que;
    que.push({0, {0, 0}});
    dis[0][0] = {0, 0};

    while(!que.empty()){

        lii cur = que.top(); que.pop();

        lli cc = cur.first;
        int ci = cur.second.first;
        int cj = cur.second.second;
        lli ct = dis[ci][cj].second;

        if(dis[ci][cj].first < cc)
            continue;

        if(ci == n){
            if(ans > dis[ci][cj])
               ans = dis[ci][cj];
            continue;
        }

        if(dis[ci+1][cj] > (pll){cc + arr[ci][cj], ct}){
            dis[ci+1][cj] = {cc + arr[ci][cj], ct};
            que.push({dis[ci+1][cj].first, {ci+1, cj}});
        }

        if(cj){
            if(dis[ci][cj-1] > (pll){cc, ct + swt[ci][cj-1]}){
                dis[ci][cj-1] = {cc, ct + swt[ci][cj-1]};
                que.push({dis[ci][cj-1].first, {ci, cj-1}});
            }
        }

        if(cj+1 < m){
            if(dis[ci][cj+1] > (pll){cc, ct + swt[ci][cj]}){
                dis[ci][cj+1] = {cc, ct + swt[ci][cj]};
                que.push({dis[ci][cj+1].first, {ci, cj+1}});
            }
        }
    }

    printf("%I64d %I64d\n", ans.first, ans.second);
}

int main(){

	int t; scanf("%d", &t); while(t--){
		solve();
	}
}
