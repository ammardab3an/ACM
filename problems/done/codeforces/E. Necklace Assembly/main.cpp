
// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define endl '\n'
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 2e5 + 10;

void solve(){

	int n, k;
	cin >> n >> k;

	string str;
	cin >> str;

	vector<int> cnt(26);
	for(char c : str) cnt[c - 'a']++;

	for(int m = n; m >= 1; m--){

        vector<int> cycles;
        vector<bool> used(m);

        for(int i = 0; i < m; i++){

            if(used[i]) continue;

            cycles.push_back(0);

            int j = i;
            while(!used[j]){
            	used[j] = true;
                cycles.back()++;
                j = (j + k) % m;
            }
        }

        bool can_fill = true;

        vector<int> cur_cnt(cnt);
        sort(cur_cnt.begin(), cur_cnt.end());

        while(!cycles.empty()){
            if(cur_cnt.back() < cycles.back()){
                can_fill = false;
                break;
            }
            else{
                cur_cnt.back() -= cycles.back();
                cycles.pop_back();
                sort(cur_cnt.begin(), cur_cnt.end());
            }
        }

        if(can_fill){
            cout << m << endl;
            break;
        }
	}
}

int main(){

    fastIO;

    int t = 1; cin >> t; while(t--) solve();
}
