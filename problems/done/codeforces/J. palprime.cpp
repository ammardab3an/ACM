
// Problem : J. palprime
// Contest : Codeforces - 2015 Damascus Collegiate Programming Contest (DCPC 2015)
// URL : https://codeforces.com/gym/100883/problem/J
// Memory Limit : 24 MB
// Time Limit : 4000 ms
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

const int INF = 0x3f3f3f3f;
const int MAX = 1 << 21;

bitset<MAX + 10> bs;
vector<int> primesVec(long long sieveSz = MAX)
{
    bs.reset(); bs.flip();
    bs.set(0, false); bs.set(1, false);

    vector<int> primes;
    sieveSz++;

    for(long long i = 2; i <= sieveSz; i++) if(bs.test(i))
    {
        for(long long j = i*i; j <= sieveSz; j += i)
            bs.set(j, false);
        
        int a = 30, b = 0;
        while(!(i & (1 << a))) a--;
        
        bool bl = true;
        while(a > b){
        	if(bool(i & (1 << a)) != bool(i & (1 << b))){
        		bl = false;
        		break;
        	}
        	a--; b++;
        }
        
        if(bl) primes.push_back(i);
    }
    return primes;
}


int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif
    
    vi vec = primesVec();
    set<int> st(vec.begin(), vec.end());
	string i_bin; while(cin >> i_bin){
		
		int sz = i_bin.size();
		
		int i = 0;
		for(int j = 0; j < sz; j++){
			if(i_bin[sz - j -1] == '1') i ^= 1 << j;
		}
		
		int ans = *st.lower_bound(i);

		int a = 30;
		
		while(!(ans & (1 << a))) a--;
		
		for(; a >= 0; a--) cout << bool(ans & (1 << a)); cout << endl;
	}
	
}
