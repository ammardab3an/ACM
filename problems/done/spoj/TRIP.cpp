// In the name of God, the Most Gracious, the Most Merciful.
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

#define multiCases true
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 80 + 10;

char str_1[MAX];
char str_2[MAX];
int len_1, len_2;

void dp(){

    int mem[MAX][MAX];
    set<string> st[MAX][MAX];

    for(int i = 0; i <= len_1; i++)
    for(int j = 0; j <= len_2; j++){

        if(!i || !j){
            mem[i][j] = 0;
            st[i][j].insert("");
            continue;
        }

        if(str_1[i-1] == str_2[j-1]){

            mem[i][j] = mem[i-1][j-1] + 1;

            for(string str : st[i-1][j-1])
                st[i][j].insert(str + str_1[i-1]);
        }

        else{

            if(mem[i-1][j] >= mem[i][j-1]){

                mem[i][j] = mem[i-1][j];

                for(string str : st[i-1][j])
                    st[i][j].insert(str);
            }

            if(mem[i-1][j] <= mem[i][j-1]){

                mem[i][j] = mem[i][j-1];

                for(string str : st[i][j-1])
                    st[i][j].insert(str);
            }
        }
    }

    for(string str : st[len_1][len_2])
        cout << str << endl;
}

void solve(){

	cin >> str_1 >> str_2;

	len_1 = strlen(str_1);
	len_2 = strlen(str_2);

	dp();
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){
        solve();
    }
}
