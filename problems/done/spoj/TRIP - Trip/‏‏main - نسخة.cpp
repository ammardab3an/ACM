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

int dp(int pos_1, int pos_2){

    if(pos_1 == len_1 || pos_2 == len_2)
        return 0;

    int & ret = mem[pos_1][pos_2];
    if(ret != -1) return ret;

    ret = max(dp(pos_1+1, pos_2), dp(pos_1, pos_2+1));

    if(str_1[pos_1] == str_2[pos_2])
        ret = max(ret, 1 + dp(pos_1+1, pos_2+1));

    return ret;
}

string str;

bool bt(int ans, int pos_1, int pos_2){

    if(pos_1 == len_1 || pos_2 == len_2){
        if(st.size() == 1000)
            return false;
        else{
            st.insert(str);
            return true;
        }
    }

    if(dp(pos_1+1, pos_2) == ans)
        if(!bt(ans, pos_1+1, pos_2)) return false;

    if(dp(pos_1, pos_2+1) == ans)
        if(!bt(ans, pos_1, pos_2+1)) return false;

    if(str_1[pos_1] == str_2[pos_2]) if(dp(pos_1+1, pos_2+1) == ans-1){
        str.push_back(str_1[pos_1]);
        if(!bt(ans-1, pos_1+1, pos_2+1)) return false;
        str.pop_back();
    }

    return true;
}

void solve(){

	cin >> str_1 >> str_2;

	len_1 = strlen(str_1);
	len_2 = strlen(str_2);

	bt(dp(0, 0), 0, 0);

	for(string str : st)
        cout << str << endl;
}

int main(){

    fastIO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){
        st.clear();
        memset(mem, -1, sizeof mem);
        solve();
    }
}
