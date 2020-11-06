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

// Global Variables

const int MAX = 1e4 + 10;

int n, k;
int arr[MAX][4];
lli mem[MAX][101];
bool Can[MAX][MAX][2];

bool can(int pos, int nxt){

    if(Can[pos][nxt][0])
        return Can[pos][nxt][1];

    Can[pos][nxt][0] = true;

    return Can[pos][nxt][1] =   (arr[pos][0] + arr[pos][1] < arr[nxt][0] - arr[nxt][1]) &&

                                (abs(arr[pos][2] - arr[nxt][2]) >= arr[nxt][3]);
}

lli dp(int pos, int cnt){

    if(cnt == k) return 0;

    lli & ret = mem[pos][cnt];
    if(ret != -1) return ret;

    ret = 0;

    for(int nxt = pos+1; nxt < n; nxt++) if(can(pos, nxt))
            ret = max(ret, dp(nxt, cnt+1));

    return ret += arr[pos][2];
}

void solve(){

    scanf("%d%d", &n, &k);

    for(int j = 0; j < 4; j++)
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i][j]);
        Can[i][j][0] = false;
    }

    memset(mem, -1, sizeof mem);

    lli ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp(i, 0));
    printf("%I64d\n", ans);
}

int main(){


	int t = 1; if(true) scanf("%d", &t);

	while(t--){
		solve();
	}
}
