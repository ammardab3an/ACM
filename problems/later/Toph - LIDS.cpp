// Problem: LIDS
// Contest: Toph
// URL: https://toph.co/p/lids
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef unsigned int		uint;
typedef long long int       lli;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

//#define int int64_t

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

vi cur_num_a, cur_num_b;
int mem[15][15][15][2];
bool debug = true;
string tmp;
int go(int pos, int mn_dig, int cnt, bool b_h, vi & cur_num, int sz){
	
//	if(debug) cout << tmp << endl;
	if(debug)if(pos == sz) if(!cnt) cout << " - " << tmp << endl;	
	if(pos == sz) return !cnt;
	
	int & ret = mem[pos][mn_dig][cnt][b_h];
	if(ret + 1) return ret;
	
	int ans = 0;
	
	int mx = b_h ? 9 : cur_num[pos];
	
	for(int i = 0; i < min(mn_dig, mx); i++){
		
		//tmp.push_back('0' + i);
		tmp.push_back('#');
		ans += go(pos+1, mn_dig, cnt, b_h || (i < cur_num[pos]), cur_num, sz);
		tmp.pop_back();
		
		break;
	}
	
	for(int i = mn_dig; i <= mx; i++){
		
		tmp.push_back('0' + i);
		ans += go(pos+1, i+1, cnt-1, b_h || (i < cur_num[pos]), cur_num, sz);
		tmp.pop_back();
		
	}
	
	
	return ans;
	return ret = ans;
}

int32_t main(){
    
    fastIO;		
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
	int tc; cin >> tc;
	
	for(int t = 1; t <= tc; t++){
		
		int a, b; cin >> a >> b;
		
		a--;
		
		cur_num_a.clear();
		cur_num_b.clear();
		
		while(a){cur_num_a.push_back(a%10); a/=10;};
		while(b){cur_num_b.push_back(b%10); b/=10;};

		reverse(cur_num_a.begin(), cur_num_a.end());
		reverse(cur_num_b.begin(), cur_num_b.end());
		
		
		if(debug && false){
			memset(mem, -1, sizeof mem);
			go(0, 1, 3, 0, cur_num_b, cur_num_b.size());
			break;
		}
		
		int ans_len = 0;
		int ans_cnt = 0;
		
		int l = 1;
		int h = cur_num_b.size();
		
		while(l <= h){
			
			int m = (l + h)/2;
			
			int cur_ans_cnt = 0;
			memset(mem, -1, sizeof mem);
			cur_ans_cnt += go(0, 1, m, 0, cur_num_b, cur_num_b.size());
			memset(mem, -1, sizeof mem);
			cur_ans_cnt -= go(0, 1, m, 0, cur_num_a, cur_num_a.size());
			
			if(cur_ans_cnt){
				ans_len = m;
				ans_cnt = cur_ans_cnt;
				l = m+1;
			}
			
			else{
				h = m-1;
			}
		}
		
			
		cout << "Case " << t << ": " << ans_len << " " << ans_cnt << endl;
	}	
	
	
}
