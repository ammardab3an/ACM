// Problem: D - Circumferences
// Contest: AtCoder - AtCoder Beginner Contest 259
// URL: https://atcoder.jp/contests/abc259/tasks/abc259_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


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

int mul(int a, int b){
	int ret = (1ll * (a%MOD) * (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int add(int a, int b){
	int ret = (1ll * (a%MOD) + (b%MOD)) % MOD;
	return (ret+MOD)%MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));
const int BLOCK = ceil(sqrt(double(NMAX)));

#define double long double

typedef complex<double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-12
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine

bool circleCircleIntersection(const point &c1, const double&r1,
	const point &c2, const double&r2) {
		
	double len = length(vec(c1,c2));
	
	if (len > r1 + r2 || len < fabs(r1 - r2))
		return false;
		
	return true;
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    struct cir{
    	point p;
    	double r;
    };
    
    auto intersect = [](const cir &a, const cir &b){
    	return circleCircleIntersection(a.p, a.r, b.p, b.r);
    };
    
    int n;
    cin >> n;
    
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    cir c0 = (cir){(point){x0, y0}, 0};
    cir c1 = (cir){(point){x1, y1}, 0};
    
    vector<cir> v(n);
    for(auto &c : v){
    	int x, y, r;
    	cin >> x >> y >> r;
    	c = (cir){(point){x, y}, r};
    }
    
    vector<bool> vis(n);
    
    int p = -1;
    for(int i = 0; i < n; i++){
    	if(intersect(v[i], c0)){
    		p = i;
    		break;
    	}
    }
    
    if(p==-1){
    	cout << "No" << endl;
    	return 0;
    }
    
	queue<int> que;
	que.push(p);
	
	while(!que.empty()){
		
		int p = que.front();
		que.pop();
		
		if(vis[p]) continue;
		vis[p] = true;
		
		for(int i = 0; i < n; i++) if(!vis[i]){
			if(intersect(v[p], v[i])){
				que.push(i);
			}
		}
	}
	
	bool ans = false;
	for(int i = 0; i < n; i++) if(vis[i]){
		if(intersect(v[i], c1)){
			ans = true;
			break;
		}
	}
	
	cout << (ans ? "Yes" : "No") << endl;
}
