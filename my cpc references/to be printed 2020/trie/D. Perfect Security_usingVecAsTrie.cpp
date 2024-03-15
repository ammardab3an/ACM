//بسم الله الرحمن الرحيم
#include <math.h>

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
//#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define F first
#define S second
#define pb(x) push_back(x)
#define E end()
#define B begin()
#define mk(x, z) make_pair(x, z)
#define fo(i, n) for (int i = 1; i <= n; i++)
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;

ll n, m, x, a[300001];
vector<vector<ll> > v;
vector<ll> cn;

void calc(ll zz) {
	
  int cur = 0;

  for (int i = 30; i >= 0; i--) {
  	
    bool bit = zz & (1 << i);

    if (v[cur][bit] == -1) {
      v[cur][bit] = v.size();
      v.push_back(vector<ll>(2, -1));
      cn.pb(0);
    }
    cur = v[cur][bit];
    cn[cur]++;
  }
}

ll fun(ll xx) {
	
  ll su = 0, cur = 0;
  
  for (int i = 30; i >= 0; i--) {
  	
    bool bit = xx & (1 << i);
    
    if (bit) {
    	
      if (v[cur][1] == -1) {
        su += 1 << i;
        cur = v[cur][0];
        cn[cur]--;
        
      } 
      
      else {
        if (cn[v[cur][1]] < 1) {
			su += 1 << i;
			cur = v[cur][0];
			cn[cur]--;
        }
        else{
	        cur = v[cur][bit];
	        cn[cur]--;
        }
      }
    } 
    
    else {
      
      if (v[cur][0] == -1) {
        su += 1 << i;
        cur = v[cur][1];
        cn[cur]--;
      }
      
      else {
      	
        if (cn[v[cur][0]] < 1) {
			su += 1 << i;
			cur = v[cur][1];
			cn[cur]--;
        }
        else{
	        cur = v[cur][bit];
	        cn[cur]--;
        }
      }
    }
    
    
  }
  
  return su;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  fo(i, n) cin >> a[i];

  v.resize(1);
  v[0].resize(2, -1);
  cn.pb(0);

  fo(i, n) {
    cin >> x;
    calc(x);
  }

  fo(i, n) { cout << fun(a[i]) << " "; }
}