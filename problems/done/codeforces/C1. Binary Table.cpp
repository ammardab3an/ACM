// Problem: C1. Binary Table (Easy Version)
// Contest: Codeforces - Codeforces Round #684 (Div. 2)
// URL: http://codeforces.com/contest/1440/problem/C1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long  ull;
typedef long long int       ll;
typedef long double         ld;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<ll, ll>        pll;
typedef pair<ll, pll>       lll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<pii>         vpii;

const int OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int pi = acos(-1);
const double EPS = 1e-9;

const int MAX = 2e5 + 10;

bool grid[110][110];
int mem[2][2][2][2][5];
vector< array<int, 2> > go_ret;

int dp(int a0, int a1, int a2, int a3, int cnt){

	if(cnt == 5) return 10;

    if(!a0 && !a1 && !a2 && !a3) return 0;	
	
    int & ret = mem[a0][a1][a2][a3][cnt];
    if(ret != -1) return ret;

	cnt++;
    int stPath = dp(!a0, !a1, !a2, a3, cnt);
    int ndPath = dp(a0, !a1, !a2, !a3, cnt);
    int rdPath = dp(!a0, a1, !a2, !a3, cnt);
    int thPath = dp(!a0, !a1, a2, !a3, cnt);
    
    return ret = min({stPath, ndPath, rdPath, thPath}) + 1;
}

void go(int a0, int a1, int a2, int a3, int cnt){
	
    if(!a0 && !a1 && !a2 && !a3) return;

    int ans = dp(a0, a1, a2, a3, cnt);
	
	cnt++;
    int stPath = dp(!a0, !a1, !a2, a3, cnt);
    int ndPath = dp(a0, !a1, !a2, !a3, cnt);
    int rdPath = dp(!a0, a1, !a2, !a3, cnt);
    int thPath = dp(!a0, !a1, a2, !a3, cnt);

	ans--;
    if(ans == stPath){
        go_ret.push_back({0, 0});
        go_ret.push_back({0, 1});
        go_ret.push_back({1, 1});
        go(!a0, !a1, !a2, a3, cnt);
    }

    else if(ans == ndPath){
        go_ret.push_back({1, 0});
        go_ret.push_back({0, 1});
        go_ret.push_back({1, 1});
        go(a0, !a1, !a2, !a3, cnt);
    }

    else if(ans == rdPath){
        go_ret.push_back({0, 0});
        go_ret.push_back({1, 0});
        go_ret.push_back({1, 1});
        go(!a0, a1, !a2, !a3, cnt);
    }

    else if(ans == thPath){
        go_ret.push_back({0, 0});
        go_ret.push_back({0, 1});
        go_ret.push_back({1, 0});
        go(!a0, !a1, a2, !a3, cnt);
    }

}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int t; cin >> t; while(t--){
		
		int n, m;
        cin >> n >> m;
        
        for(int i = 0; i < n; i++){
            string str; cin >> str;
            for(int j = 0; j < m; j++) grid[i][j] = str[j] == '1';
        }

        vector< array<int, 2> > ans;
        
        memset(mem, -1, sizeof mem);	

        for(int i = 0; i < n; i+=2){

            for(int j = 0; j < m; j+=2){

                if(i+1 == n) i--;
                if(j+1 == m) j--;

                int a0 = grid[i][j];
                int a1 = grid[i][j+1];
                int a2 = grid[i+1][j+1];
                int a3 = grid[i+1][j];

                go_ret.clear();
                go(a0, a1, a2, a3, 0);

                for(auto a : go_ret){
                    ans.push_back({a[0]+i, a[1]+j});
                    grid[a[0]+i][a[1]+j] = !grid[a[0]+i][a[1]+j];
                }
            }
        }

		int ans_sz = ans.size();
        cout << ans_sz/3 << endl;;
        for(int i = 0; i < ans_sz; i++){
            cout << ans[i][0]+1 << ' ' << ans[i][1]+1 << " \n"[(i+1)%3 == 0];
        }
    }

}
