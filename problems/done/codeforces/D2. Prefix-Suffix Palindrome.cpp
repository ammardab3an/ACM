// Problem: D2. Prefix-Suffix Palindrome (Hard version)
// Contest: Codeforces - Codeforces Global Round 7
// URL: https://codeforces.com/contest/1326/problem/D2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

string LongestPalindromicPrefix(string str)
{
  
    // Create temporary string
    string temp = str + '?';
  
    // Reverse the string str
    reverse(str.begin(), str.end());
  
    // Append string str to temp
    temp += str;
  
    // Find the length of string temp
    int n = temp.length();
  
    // lps[] array for string temp
    int lps[n];
  
    // Intialise every value with zero
    fill(lps, lps + n, 0);
  
    // Iterate the string temp
    for (int i = 1; i < n; i++) {
  
        // Length of longest prefix
        // till less than i
        int len = lps[i - 1];
  
        // Calculate length for i+1
        while (len > 0 && temp[len] != temp[i]) {
            len = lps[len - 1];
        }
  
        // If character at current index
        // len are same then increament
        // length by 1
        if (temp[i] == temp[len]) {
            len++;
        }
  
        // Update the length at current
        // index to len
        lps[i] = len;
    }
  
    return temp.substr(0, lps[n-1]);
}
 
int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    int t; cin >> t; while(t--){

        string str;
        cin >> str;
        
        int n = str.size();
        
        int i = 0;
        int j = n-1;
        int len = 0;
        while((i < j) && (str[i] == str[j])){
            i++, j--, len++;
        }
        
        string nstr = str.substr(len, n - 2*len);
        
        string a = LongestPalindromicPrefix(nstr);
        reverse(nstr.begin(), nstr.end());
        string b = LongestPalindromicPrefix(nstr);
        
        string ans = str.substr(0, len) + (a.size() > b.size() ? a : b) + str.substr(n-len);
        
        cout << ans << endl;
    }	
}

/*
  arrays sizes 
  INFLL & 1ll
  there is something called long long.
  if its an interactive problem : #define endl '\n'
  
  
  notes : 
  
  
*/    
