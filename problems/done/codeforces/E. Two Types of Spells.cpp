// Problem: E. Two Types of Spells
// Contest: Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1398/problem/E
// Memory Limit: 256 MB
// Time Limit: 3500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define lli int64_t

// typedef unsigned int        uint;
// typedef long long int       lli;
// typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

// #define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rand(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif
    
    int n;
    cin >> n;
    
    multiset<pii> st_mx;
    multiset<pii> st_mn;
    multiset<int> st_li;
    
    int cnt_li = 0;
    int cnt_fi = 0;
    
    int sum_mx = 0;
    int sum_mn = 0;
    
    while(n--){
        
        int tp, d;
        cin >> tp >> d;
        
        if(d > 0){
            
            if(tp == 0) cnt_fi++;
            else cnt_li++, st_li.insert(d);
            
            st_mn.insert({d, tp});
            sum_mn += d;
            
            if((!st_mn.empty()) && (st_mx.size() < cnt_li)){
                
                pii tmp = *st_mn.rbegin();
                st_mn.erase(st_mn.find(tmp));
                sum_mn -= tmp.first;
                
                st_mx.insert(tmp);
                sum_mx += tmp.first;
            }
            
            if((st_mn.size() && st_mx.size()) && ((st_mx.begin()->first) < (st_mn.rbegin()->first))){
                
                pii tmp = *st_mx.begin();
                st_mx.erase(st_mx.begin());
                sum_mx -= tmp.first;
                
                st_mn.insert(tmp);
                sum_mn += tmp.first;
                
                tmp = *st_mn.rbegin();
                st_mn.erase(st_mn.find(tmp));
                sum_mn -= tmp.first;
                
                st_mx.insert(tmp);
                sum_mx += tmp.first;
            }
        }    
        else{
            
            d *= -1;
            
            if(tp == 0) cnt_fi--;
            else cnt_li--, st_li.erase(st_li.find(d));
            
            if(st_mn.find({d, tp}) != st_mn.end()){
                sum_mn -= d;    
                st_mn.erase(st_mn.find({d, tp}));
            }
            else{
                sum_mx -= d;
                st_mx.erase(st_mx.find({d, tp}));
            }
            
            if(st_mx.size() > cnt_li){
                
                pii tmp = *st_mx.begin();
                st_mx.erase(st_mx.begin());
                sum_mx -= tmp.first;
                st_mn.insert(tmp);
                sum_mn += tmp.first;
            }
            else if(st_mx.size() < cnt_li){
                
                pii tmp = *st_mn.rbegin();
                st_mn.erase(st_mn.find(tmp));
                sum_mn -= tmp.first;
                st_mx.insert(tmp);
                sum_mx += tmp.first;
            }
            
        }
        
        int cans = sum_mn + 2 * sum_mx;
        
        if((cnt_li > 0) && ((*st_li.begin()) >= (st_mx.begin()->first))){
            cans -= *st_li.begin();
            if(!st_mn.empty())
                cans += st_mn.rbegin()->first;
        }
        
        cout << cans << endl;
    }
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
