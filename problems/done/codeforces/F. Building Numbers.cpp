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

const int MAX = 1e5 + 10;

lli arr[MAX];
int ans[MAX];

int go(lli num){

    int ans = 0;

    while(num > 1){
        if(num % 2)
            num--;
        else
            num /= 2;
        ans++;
    }

    return ans;
}

void solve(){

    int n, q;
    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++)
        scanf("%I64d", &arr[i]);

    ans[0] = go(arr[0]);
    for(int i = 1; i < n ; i++)
        ans[i] = ans[i-1] + go(arr[i]);

    while(q--){

        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;

        int ANS = ans[r];
        if(l) ANS -= ans[l-1];

        printf("%d\n", ANS);
    }
}

int main(){

	int t = 1; scanf("%d", &t);

	while(t--){
		solve();
	}
}
