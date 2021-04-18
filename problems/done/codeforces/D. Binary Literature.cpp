// Problem: D. Binary Literature
// Contest: Codeforces - Codeforces Round #715 (Div. 2)
// URL: https://codeforces.com/contest/1509/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

//#define int int64_t
//#define lli int64_t

typedef unsigned int        uint;
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const lli INFLL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
string tmp[3];
string str[2];

string go(int s0, int s1){
    
    
    {
        string str_0;
    
        int i = 0;
        int j = 0;
        
        while((i < 2*n) && (j < 2*n)){
            
            bool b0 = str[s0][i] == '1';
            bool b1 = str[s1][j] == '1';
            
            if(b0 == b1){
                str_0.push_back(str[s0][i]);
                i++, j++;
            }
            else if(b0 && !b1){
                str_0.push_back('1');
                i++;
            }
            else{
                str_0.push_back('1');
                j++;
            }
            
        }
        
        while(i < 2*n) str_0.push_back(str[s0][i++]);
        while(j < 2*n) str_0.push_back(str[s1][j++]);
        
        if(str_0.size() <= 3*n) return str_0;
    }
    
    {
        string str_0;
    
        int i = 0;
        int j = 0;
        
        while((i < 2*n) && (j < 2*n)){
            
            bool b0 = str[s0][i] == '1';
            bool b1 = str[s1][j] == '1';
            
            if(b0 == b1){
                str_0.push_back(str[s0][i]);
                i++, j++;
            }
            else if(b0 && !b1){
                str_0.push_back('0');
                j++;
            }
            else{
                str_0.push_back('0');
                i++;
            }

        }
        
        while(i < 2*n) str_0.push_back(str[s0][i++]);
        while(j < 2*n) str_0.push_back(str[s1][j++]);
        
        return str_0;
    }
}

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        cin >> n;        
        for(int i = 0; i < 3; i++) cin >> tmp[i];
        
        bool found = false;
        
        for(int i = 0; i < 3; i++){
            
            str[0] = tmp[i];
            str[1] = tmp[(i+1)%3];
            
            string tmp = go(0, 1);
            
            if(tmp.size() <= 3*n){
                cout << tmp << endl;
                found = true; 
                break;
            }
            
            tmp = go(1, 0);
            
            if(tmp.size() <= 3*n){
                cout << tmp << endl;
                found = true; 
                break;
            }
        }
        
        if(!found) cout << "-1" << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
