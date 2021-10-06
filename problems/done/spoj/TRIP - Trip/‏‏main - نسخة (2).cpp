// In the name of God, the Most Gracious, the Most Merciful.

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

set<string> st;
int mem[MAX][MAX];

int dp(){

    for(int i = 1; i <= len_1; i++)
    for(int j = 1; j <= len_2; j++){

        if(str_1[i-1] == str_2[j-1])
            mem[i][j] = mem[i-1][j-1] + 1;

        else
            mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
    }

    return mem[len_1][len_2];
}

void bt(int ans, string str, int pos_1, int pos_2){

    if(!pos_1 || !pos_2){
        st.insert(str);
        return;
    }

    if(str_1[pos_1-1] == str_2[pos_2-1])

        bt(ans-1, string(1, str_1[pos_1-1]) + str, pos_1-1, pos_2-1);

    else{

        if(mem[pos_1-1][pos_2] == ans)
            bt(ans, str, pos_1-1, pos_2);

        if(mem[pos_1][pos_2-1] == ans)
            bt(ans, str, pos_1, pos_2-1);
    }

}

void solve(){

	cin >> str_1 >> str_2;

	len_1 = strlen(str_1);
	len_2 = strlen(str_2);

    st.clear();
	bt(dp(), "", len_1, len_2);

	for(string str : st)
        cout << str << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){
        solve();
    }
}
