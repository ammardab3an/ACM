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

const int MAX = 2e5 + 10;

void solve(){

    int n;
    cin >> n;
    n *= 2;

    int cnt = 0;
    int lst = 0;
    stack<int> st;

    while(n--){

        string cmd; cin >> cmd;

        if(cmd == "add"){
            int i; cin >> i;
            st.push(i);
        }
        else{
            if(!st.empty()){
                if(st.top() == lst+1){
                    st.pop();
                }
                else{
                    while(!st.empty()) st.pop();
                    cnt++;
                }
            }
            lst++;
        }
    }
    cout << cnt;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(false) cin >> t;

	while(t--){
		solve();
	}
}
