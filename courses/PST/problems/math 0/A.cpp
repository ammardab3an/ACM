
// Problem : A - Almost Prime
// Contest : Virtual Judge - Week #3.1 [Number Theory] - Easy ~ Medium
// URL : https://vjudge.net/contest/398278#problem/A
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

bitset<4000> bs;
vector<int> primes;
int primesSz;

void fillPrimesVec(){
	
	bs.reset(); bs.flip();
	bs.set(0, false);
	bs.set(1, false);
	for(int i = 2; i < 4000; i++) if(bs.test(i)){
		for(int j = i*i; j < 4000; j+=i)
			bs.set(j, false);
		primes.push_back(i);
	}
	
	primesSz = primes.size();
}

int main(){
    
    fastIO;
    
	fillPrimesVec();
		
	int n; cin >> n;
	
	int ans = 0;
	
	for(int i = 2; i <= n; i++){
		
		int m = i;
		int cntOfFac = 0;
		
		for(int i = 0; i < primesSz; i++) if(m % primes[i] == 0){
			while(m % primes[i] == 0) m /= primes[i];
			cntOfFac++;
		}
		
		ans += cntOfFac == 2;
	}
	
	cout << ans << endl;
}
