
// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

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

//#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MAX = 2e5 + 10;

int main(){

    fastIO;

	int n, m;
	while(cin >> n >> m){

        if(!n && !m) break;

        vector<int> vec_n(n), vec_m(m);

        for(int i = 0; i < n; i++) cin >> vec_n[i];
        for(int i = 0; i < m; i++) cin >> vec_m[i];

        int cnt = 0;

        int i(0), j(0);

        while(i != n && j != m){
            if(vec_n[i] == vec_m[j]){
                i++; j++; cnt++;
            }
            else if(vec_n[i] < vec_m[j]){
                i++;
            }
            else{
                j++;
            }
        }

        cout << cnt << endl;
	}
}
