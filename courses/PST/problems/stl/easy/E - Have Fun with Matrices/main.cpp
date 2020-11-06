
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

//#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MAX = 2e5 + 10;

char grid[11][11];

int mod(int a, int b){
    if(a < 0) return (a % b) + b;
    if(a >= b) return a % b;
    return a;
}

int main(){

    fastIO;

	int T; cin >> T;
	for(int t = 1; t <= T; t++){

        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> grid[i];

        int add(0);

        int m; cin >> m; while(m--){

            string fn; cin >> fn;

            if(fn == "row"){
                int a, b;
                cin >> a >> b; a--; b--;

                for(int i = 0; i < n; i++) swap(grid[a][i], grid[b][i]);
            }

            else if(fn == "col"){
                int a, b;
                cin >> a >> b; a--; b--;

                for(int i = 0; i < n; i++) swap(grid[i][a], grid[i][b]);
            }

            else if(fn == "inc"){
                add++;
            }

            else if(fn == "dec"){
                add--;
            }

            else{
                for(int i = 0; i < n; i++)
                for(int j = i; j < n; j++) swap(grid[i][j], grid[j][i]);
            }
        }

        if(add){
            for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) grid[i][j] = '0' + mod(grid[i][j] - '0' + add, 10);
        }

        cout << "Case #" << t << endl;

        for(int i = 0; i < n; i++)
            cout << grid[i] << endl;

        cout << endl;
	}
}
