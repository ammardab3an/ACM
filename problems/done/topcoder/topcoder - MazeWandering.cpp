// Problem: MazeWandering
// Contest: Virtual Judge - TopCoder
// URL: https://vjudge.net/problem/TopCoder-10005
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

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
const double EPS = 1e-15;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int mul(int a, int b){
	return (1ll * (a%MOD) * (b%MOD)) % MOD;
}
 
int add(int a, int b){
	return (1ll * (a%MOD) + (b%MOD) + MOD + MOD) % MOD;
}
 
int pow_exp(int n, int p){
	if(!p) return 1;
	if(p&1) return mul(n, pow_exp(n, p-1));
	int tmp = pow_exp(n, p/2);
	return mul(tmp, tmp);
}

const int NMAX = 50 + 10;

int cell_id[NMAX][NMAX];

int cmp(double x, double y = 0.0){
    
    if(fabs(x-y) < EPS){
        return 0;
    }
    else{
        return (x > y) * 2 -1;
    }
}

bool make_nonZero(vector<valarray<double>> &eq, int i){
    
    int n = eq.size();
    
    for(int j = i+1; j < n; j++){
        if(cmp(eq[j][i]) != 0){
            swap(eq[i], eq[j]);
            return true;
        }
    }
    
    return false;
}

bool solve(vector<valarray<double>> &eq){
    
    int n = eq.size();
    int m = eq.front().size();
    
    for(int i = 0; i < n; i++){
        
        if(cmp(eq[i][i]) == 0){
            if(!make_nonZero(eq, i)){
                return false;
            }
        }   
        
        double cur = eq[i][i];
        eq[i] /= cur;
        
        for(int j = 0; j < n; j++){
            
            if(i == j || cmp(eq[j][i]) == 0){
                continue;
            }
            
            cur = eq[j][i];
            eq[j] += -cur * eq[i];
        }
        
    }
    
    return true;
}

class MazeWandering{
    
public:
    
    double expectedTime(vector<string> input){
        
        int gi, gj;        
        int cnt = 0;
        
        int n = input.size();
        int m = input.front().size();
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(input[i][j] != 'X'){
                cell_id[i][j] = cnt++;
            }
            if(input[i][j] == '*'){
                gi = i, gj = j;
            }
        }
        
        vector<valarray<double>> eq(cnt, valarray<double>(0.0, cnt+1));
        
        for(int i = 0; i < n; i++)   
        for(int j = 0; j < m; j++){
            
            if(input[i][j] == 'X' || input[i][j] == '*'){
                continue;
            }   
            
            vector<int> tmp;
            
            for(auto p : (vpii){{0, -1}, {-1, 0}, {0, 1}, {1, 0}}){
                
                int ni = i + p.first;
                int nj = j + p.second;
                
                if(0 <= ni && 0 <= nj && ni < n && nj < m && input[ni][nj] != 'X'){
                    tmp.push_back(cell_id[ni][nj]);
                }
            }
            
            int x = cell_id[i][j];
            eq[x][x] = -1;
            eq[x][cnt] = -1;
            
            for(auto i : tmp){
                eq[x][i] = 1.0 / tmp.size();
            }
        }
        
        eq[cell_id[gi][gj]][cell_id[gi][gj]] = 1;
        
        assert(solve(eq));
        
        double ret = 0.0;
        
        for(auto &e : eq){
            ret += e[cnt];
        }
        
        ret /= cnt;
        
        return ret;
    }    
};

// int32_t main(){
//     
    // fastIO;
//     
// #ifdef LOCAL
    // freopenI;
    // freopenO;
// #endif
// 
    // // freopen("name.in", "r", stdin);
//     
    // MazeWandering obj;
    // cout << fixed << setprecision(10) << obj.expectedTime(
            // {"*........",
             // "XXX.XXXX.",
             // ".XX.X....",
             // ".....XX.X"});
// }
// 