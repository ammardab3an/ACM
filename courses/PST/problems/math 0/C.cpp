
// Problem : C - T-primes
// Contest : Virtual Judge - Week #3.1 [Number Theory] - Easy ~ Medium
// URL : https://vjudge.net/contest/398278#problem/C
// Memory Limit : 262 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


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

const int MAX = 2e5 + 10;
const int sieveMx = 1e6;

vi primes;
bitset<sieveMx +10> bs;

void fillPrimesVec(int mx){
	
	bs.reset(); bs.flip();
	
	for(lli i = 2; i <= mx; i++) if(bs.test(i)){
		for(lli j = i*i; j <= mx; j += i) bs.set(j, false);
		primes.push_back(i);
	}
	
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
    fillPrimesVec(sieveMx);
    
	set<int> st;
	for(int p : primes) st.insert(p);
	
	int n; cin >> n; while(n--){
		
		int i; cin >> i; 
		int j = sqrt(i);
		
		if(j*j == i && st.lower_bound(j) != st.end()) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
}
