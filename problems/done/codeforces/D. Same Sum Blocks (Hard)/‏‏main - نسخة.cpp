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
typedef pair< int, vector<pii> > piv;
// Global Variables

const int MAX = 1500 + 10;

int n;
int arr[MAX];

int SUM;
piv mem[MAX];

piv dp(int pos){

    if(pos == n) return {0, {}};

    piv & ret = mem[pos];
    if(ret.first != -1) return ret;

    ret.first = 0;

    for(int i = pos; i < n; i++)
    for(int j =  i ; j < n; j++){

        int cSum = arr[j];
        if(i) cSum -= arr[i-1];


        if(cSum == SUM){
            piv cAns = dp(j+1);
            if(1 + cAns.first > ret.first){
                ret = cAns;
                ret.first++;
                ret.second.insert(ret.second.begin(), {i, j});
            }
        }

    }

    return ret;
}

void solve(){

    cin >> n;

    cin >> arr[0];
    for(int i =  1; i < n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    piv ans;
    set<int> st;

    for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++){

        SUM = arr[j];
        if(i) SUM -= arr[i-1];

        if(st.count(SUM))
            continue;
        else
            st.insert(SUM);

        for(int k = 0; k < n; k++)
            mem[k] = {-1, {}};

        piv cAns = dp(j+1);

        if(1 + cAns.first > ans.first){
            ans = cAns;
            ans.first++;
            ans.second.insert(ans.second.begin(), {i, j});
        }
    }

    cout << ans.first << endl;
    for(pii p : ans.second)
        cout << p.first +1 << ' ' << p.second +1 << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
