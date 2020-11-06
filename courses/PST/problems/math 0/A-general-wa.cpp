
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

int n;
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

vi factors(int n){
	
	vi res;
	for(int i = 0; i < primesSz; i++){
		while(n % primes[i] == 0){
			res.push_back(primes[i]);
			n /= primes[i];
		}
	}
	return res;
}
int go(int pos, int res, int cnt){
	
	if(pos >= primesSz){	
		return cnt == 2;
	}
	
	int sm = 0;
	
	if(cnt > 2) return sm;

	sm += go(pos+1, res, cnt + bool(res%primes[pos] == 0));
	
	if(res*primes[pos] > n) return sm;
	
	sm += go(pos, res*primes[pos], cnt);
	
	return sm;
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	fillPrimesVec();
		
	cin >> n;
	cout << go(0, 1, 0) << endl;	
	
}
