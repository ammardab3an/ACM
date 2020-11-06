
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

//#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

int n;
int solve();
int main(){
	while(cin >> n) solve();
}

int solve(){

	if(false){
		int n = ::n;		    
		vi vec(n);
		for(int i = 0; i < n; i++) vec[i] = i+1;
		
		int mx = -1;
		vi tmp;
		
		do{
			
			int sm = 0;
			for(int i = 1; i < n; i++) sm += abs(vec[i] - vec[i-1]);
			if(sm > mx){
				mx = sm;
				tmp = vi(vec.begin(), vec.end());
			}
			
		}while(next_permutation(vec.begin(), vec.end()));
		
		cout << mx << endl;
	//	for(int i = 0; i < n; i++) cout << tmp[i] << ' '; cout << endl;
	
	}
	

	{
		int n = ::n;
		deque<int> que;
		que.push_back(1);
	
		int i = 2, j = n;
		
		while(true){
			
			if(j < i) break;
			
			que.push_back(j--);
			
			if(j < i) break;
			
			que.push_front(j--);
			
			if(j < i) break;
				
			que.push_back(i++);
			
			if(j < i) break;
			
			que.push_front(i++);
			
		}
		
		vi tmp_2;
		for(auto i : que) tmp_2.push_back(i);
		
		int sm = 0;
		for(int i = 1; i < n; i++) sm += abs(tmp_2[i] - tmp_2[i-1]);
		cout << sm << endl;
		//for(int i = 0; i < n; i++) cout << tmp_2[i] << ' '; cout << endl;
	}
		
	
}
