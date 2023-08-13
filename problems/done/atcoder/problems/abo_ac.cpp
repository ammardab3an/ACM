
// By AmmarDab3an 

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define ll  int64_t

// typedef unsigned int        uint;
// typedef long long int       ll;
// typedef unsigned long long  ull;
typedef pair<int, int>    pii;
typedef pair<ll, ll>      pll;
typedef pair<int, pii>    iii;
typedef pair<ll, pll>     lll;
typedef vector<int>       vi;
typedef vector<ll>        vl;
typedef vector<pii>       vpii;
typedef vector<pll>       vpll;

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int NMAX = 1e5 + 10;

string pat;
int mem[NMAX][26];
int vis[NMAX][26], vid;
int pat_pre[NMAX];

int nxtL(int i, char c){
	
	int &ret = mem[i][c-'a'];
	int &vis = ::vis[i][c-'a'];
	if(vis==vid) return ret;
	vis = vid;
	
	while(i && pat[i] != c) i = pat_pre[i-1];
	if(pat[i] == c) i++;
	
	return ret = i;
}

void computePrefix(){
	pat_pre[0] = 0;
	for(int i = 1; i < pat.size(); i++){
		pat_pre[i] = nxtL(pat_pre[i-1], pat[i]);
	}
}

int calc_bf(const string &a, const string &b, const string &str){
	
	int ret = 0;
	string tt = a + b;
	int l = (int)a.size() - (int)str.size() + 1;
	int r = a.size();
	
	for(int i = l; i < r; i++){
		ret += tt.substr(i, str.size()) == str;
	}
	
	return ret;
}


int32_t main(){
    
    fastIO;
    
    int t;
    cin >> t;
    
    for(int tt = 1; tt <= t; tt++){

		string str;
		cin >> str;
		
		int n = str.size();
		
		::pat = str;
		vid++;
		computePrefix();
		
		auto calc = [&](const string &a, const string &b)->int{
			
			// return calc_bf(a, b, str);
			
			int ret = 0;
			
			string tt = a + b;
			int l = (int)a.size() - n + 1;
			int r = a.size() + n - 1;
			
			int j = 0;
			for(int i = l; i < r; i++){
				j = nxtL(j, tt[i]);
				if(j==n) ret++;
			}
			
			return ret;
		};
		
		vector<pair<string, string>> tmp;
		vector<int> tmp_ans;
		
		int ans = 0;
		deque<char> pre, suf;
		
		int q; 
		cin >> q; 
		while(q--){
			
			int k;
			cin >> k;
			
			if(k==1){
				char c;
				cin >> c;
				suf.push_back(c);
				if((int)suf.size() > n){
					suf.pop_front();
				}
				if((int)pre.size() < n){
					pre.push_back(c);
				}
				if((int)suf.size() == n){
					string s_suf(suf.begin(), suf.end());
					if(s_suf==str) ans = (ans+1)%MOD;
				}
			}
			else if(k==2){
				char c;
				cin >> c;
				pre.push_front(c);
				if((int)pre.size() > n){
					pre.pop_back();
				}
				if((int)suf.size() < n){
					suf.push_front(c);
				}
				if((int)pre.size() == n){
					string s_pre(pre.begin(), pre.end());
					if(s_pre==str) ans = (ans+1)%MOD;
				}
			}
			else if(k==3){
				
				int i;
				cin >> i;
				
				string s = tmp[i-1].second;
				ans = (ans + tmp_ans[i-1])%MOD;
				
				if((int)s.size() == n){
					string s_suf = string(suf.begin(), suf.end()) ;
					int cans = calc(s_suf, tmp[i-1].first);
					ans = (ans + cans)%MOD;
					suf = deque<char>(s.begin(), s.end());
				}
				else{
					for(auto c : s){
						suf.push_back(c);
						if((int)suf.size() > n){
							suf.pop_front();
						}
						if((int)pre.size() < n){
							pre.push_back(c);
						}
						if((int)suf.size() == n){
							string s_suf(suf.begin(), suf.end());					
							if(s_suf==str) ans = (ans+1)%MOD;
						}
					}
				}
			}
			else{
				
				int i;
				cin >> i;
				
				string s = tmp[i-1].first;
				ans = (ans + tmp_ans[i-1])%MOD;
				
				if((int)s.size() == n){
					string s_pre = string(pre.begin(), pre.end());
					int cans = calc(tmp[i-1].second, s_pre);
					ans = (ans + cans)%MOD;
					pre = deque<char>(s.begin(), s.end());
				}
				else{
					reverse(s.begin(), s.end());
					for(auto c : s){
						pre.push_front(c);
						if((int)pre.size() > n){
							pre.pop_back();
						}
						if((int)suf.size() < n){
							suf.push_front(c);
						}
						if((int)pre.size() == n){
							string s_pre(pre.begin(), pre.end());					
							if(s_pre==str) ans = (ans+1)%MOD;
						}
					}
				}
			}
			
			string s_pre(pre.begin(), pre.end());
			string s_suf(suf.begin(), suf.end());
			tmp.push_back({s_pre, s_suf});
			tmp_ans.push_back(ans);
			
			cout << ans << endl;
		}
    }
}
