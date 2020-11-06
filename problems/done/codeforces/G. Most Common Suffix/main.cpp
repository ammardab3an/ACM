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

const int nMAX = 1e4 + 10;
const int lMAX = 1e5 + 10;

int ans[lMAX];

struct node{

    int cnt;
    node * nxt[26];

    node(){
        cnt = 0;
        for(int i = 0; i < 26; i++)
            nxt[i] = nullptr;
    }
};

void add(node & nd, char * str){

    node * cur = & nd;

    for(int i = 0, sz = strlen(str); i < sz; i++){

        int j = str[i] - 'a';

        if(!cur -> nxt[j])
            cur -> nxt[j] = new node();

        cur = cur -> nxt[j];
        cur -> cnt++;

        ans[i+1] = max(ans[i+1], cur -> cnt);
    }
}

void solve(){

    int n, q;
    scanf("%d %d", &n, &q);

    node root = node();

    char str[lMAX];

    for(int i = 0; i < n; i++){
        scanf("%s", str);
        reverse(str, str + strlen(str));
        add(root, str);
    }

    while(q--){
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }

}

int main(){

	int t = 1; if(true) scanf("%d", &t);

	while(t--){
        memset(ans, 0, sizeof ans);
		solve();
	}
}
