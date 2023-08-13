
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

int32_t main(){
    
    fastIO;
    
    int t;
    cin >> t;
    
    for(int tt = 1; tt <= t; tt++){

		string str;
		cin >> str;
		
		int n = str.size();
		
		vector<pair<string, string>> tmp;
		vector<int> tmp_ans;
		
		int ans = 0;
		deque<char> pre, suf;
		
		bool _print = false && tt==36;
		
		int q; 
		cin >> q; 
		
		if(_print){
			cout << str << endl;
			cout << q << endl;
		}
		
		while(q--){
			
			if(_print){
				string a, b;
				cin >> a >> b;
				cout << a << ' ' << b << endl;
				continue;
			}
			
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
					
					int tans = 0;
					string s_suf = string(suf.begin(), suf.end()) ;
					string tt = s_suf + tmp[i-1].first;
					int l = int(s_suf.size()) - n + 1;
					int r = s_suf.size();
					for(int i = l; i < r; i++){
						string cc = tt.substr(i, n);
						tans += cc == str;
					}
					
					// cout << s_suf << ' ' << tmp[i-1].first << ' ' << tans << endl;
					ans = (ans + tans)%MOD;
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
					
					int tans = 0;
					string s_pre = string(pre.begin(), pre.end());
					string tt = tmp[i-1].second + s_pre;
					int l = int(tmp[i-1].second.size()) - n + 1;
					int r = tmp[i-1].second.size();
					for(int i = l; i < r; i++){
						string cc = tt.substr(i, n);
						tans += cc == str;
					}
					
					// cout << tmp[i-1].second << ' ' << s_pre << ' ' << tans << endl;
					ans = (ans + tans)%MOD;
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
			
			cout << ans << endl;
			
			string s_pre(pre.begin(), pre.end());
			string s_suf(suf.begin(), suf.end());
			// cout << s_pre << ' ' << s_suf << endl;
			
			tmp.push_back({s_pre, s_suf});
			tmp_ans.push_back(ans);
		}
    }	
}
