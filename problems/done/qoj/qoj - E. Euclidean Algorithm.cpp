// E. Euclidean Algorithm
// https://qoj.ac/contest/1103/problem/5503

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

long long solve(long long n) 
{
    long long s = sqrtl(n);
    long long ret = 0;
    for (int i = 1; i <= s; ++ i)
    {
        ret += n / i;
    }
    ret *= 2; 
    ret -= s * s; 
    return ret;
}

int brute_force(int n){
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++)
	for(int g = 1; g <= n; g++){
		
		if(g*i > (n-g)) break;
		
		// g*(k*i+1) <= n
		// k*i+1 <= n/g
		// k*i <= n/g -1
		// k <= (n/g -1) / i
		// k <= (n-g)/(g*i)
		
		ans += (n-g) / (g*i);
		
		// for(int k = 1; g*(k*i+1) <= n; k++){
			// ans++;
		// }
	}
		
	return ans;
}

int32_t main(){
    
    fastIO;
	
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		int ans = 0;
		int cur = n;
		int pst = 0;
		
		while(cur >= 1){
			int cnt = n/cur - pst;
			ans += cnt * solve(cur-1);
			pst = n/cur;
			cur = n/(n/cur + 1);
		}
		
		// cout << brute_force(n) << endl;
		cout << ans << endl;
    }	
}

/*

AmmarDab3an, [8/13/2023 11:36 PM]
a % (b-a) = g

AmmarDab3an, [8/13/2023 11:36 PM]
b-g %(b-a) = 0

AmmarDab3an, [8/13/2023 11:36 PM]
b-g = k * (b-a)

AmmarDab3an, [8/13/2023 11:36 PM]
b-a = i

AmmarDab3an, [8/13/2023 11:36 PM]
b-g = k*i
b%i = g%i

b = y * g

AmmarDab3an, [8/13/2023 11:36 PM]
b=g*k
k=yi+1

AmmarDab3an, [8/13/2023 11:36 PM]
y = k*i + 1

AmmarDab3an, [8/13/2023 11:36 PM]
g * (k*i + 1) = b

AmmarDab3an, [8/13/2023 11:36 PM]
g * (k*i+1) <= n

AmmarDab3an, [8/13/2023 11:36 PM]
k*i + 1 <= n/g

AmmarDab3an, [8/13/2023 11:36 PM]
k*i <= n/g - 1

AmmarDab3an, [8/13/2023 11:36 PM]
k*i < n/g

*/