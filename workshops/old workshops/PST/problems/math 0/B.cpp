
// Problem : B - Easy Number Challenge
// Contest : Virtual Judge - Week #3.1 [Number Theory] - Easy ~ Medium
// URL : https://vjudge.net/contest/398278#problem/B
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

const int MAX = 1e6 + 10;
const int MOD = 2e30;

vi facArr(int n){
	vi ret;
	for(int i = 2; n > 1; i++) if(n%i == 0){
		int cnt = 0;
		while(n%i == 0){
			n /= i;
			cnt++;
		}		
		ret.push_back(cnt);
	}	
	return ret;
}

vi vec;
// vi mem;
int calc(int pos){
	
	int ans = 1;
	for(int i : vec) ans *= i+1;
	return ans;
	
	/*
	if(pos == vec.size())
		return 1;
		
	int & ret = mem[pos];
	if(ret != -1) return ret;
	
	int stPath = calc(pos+1);
	int ndPath = calc(pos+1) * vec[pos];
	
	return ret = stPath + ndPath;
	*/
}

int tmp[MAX];
int go(int n){
	if(tmp[n] != 0) return tmp[n];
	vec = facArr(n);
	//mem = vi(vec.size(), -1);
	return tmp[n] = calc(0);
	
}

int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	int a, b, c;
	cin >> a >> b >> c;
	
	int ans = 0;
	
	for(int i = 1; i <= a; i++)
	for(int j = 1; j <= b; j++)
	for(int k = 1; k <= c; k++)
		ans = (ans + (go(i*j*k)) % MOD) % MOD;
		
	cout << ans << endl;
	
}
