
// Problem : D. Changing a String
// Contest : Codeforces - Codeforces Beta Round #52 (Div. 2)
// URL : https://codeforces.com/problemset/problem/56/D
// Memory Limit : 256 MB
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MAX = 1000 + 10;

string str0, str1;
int sz0, sz1;
int mem[MAX][MAX];

int go(int i, int j){
	
	if(i >= sz0 || j >= sz1){
		return max(sz0-i, sz1-j);
	}	
	
	int & ret = mem[i][j];
	if(~ret) return ret;
	
	if(str0[i] == str1[j]) 
		return go(i+1, j+1);

	int stPath = go(i, j+1) + 1;	// ins
	int ndPath = go(i+1, j) + 1;	// del
	int rdPath = go(i+1, j+1) + 1;	// rep
	
	return ret = min({stPath, ndPath, rdPath});
}

int n;
void build(int i, int j){
	
	if(i == sz0 && j == sz1){
		return;
	}
	
	if(i == sz0 || j == sz1){
		if(i == sz0){
			cout << "INSERT " << n++ + i+1 << ' ' << str1[j] << endl;
			build(i, j+1);
			return;
		}
		else{
			cout << "DELETE " << n-- + i+1 << endl;
			build(i+1, j);
			return;			
		}
	}
	
	if(str0[i] == str1[j]){
		build(i+1, j+1);
		return;
	}
	
	int ret = go(i, j);

	int stPath = go(i, j+1) + 1;
	
	if(stPath == ret){
		cout << "INSERT " << n++ + i+1 << ' ' << str1[j] << endl;
		build(i, j+1);
		return;
	}
	
	int ndPath = go(i+1, j) + 1;
	
	if(ndPath == ret){
		cout << "DELETE " << n-- + i+1 << endl;
		build(i+1, j);
		return;
	}
	
	int rdPath = go(i+1, j+1) + 1;
	
	if(rdPath == ret){
		cout << "REPLACE " << n + i+1 << ' ' << str1[j] << endl;
		build(i+1, j+1);
		return;
	}
}
	
int main(){
    
    fastIO;
    
#ifdef LOCAL_PROJECT
    freopenI;
    freopenO;
#endif // LOCAL
    
	cin >> str0 >> str1;
	sz0 = str0.size();
	sz1 = str1.size();
	memset(mem, -1, sizeof mem);
	cout << go(0, 0) << endl;

	build(0, 0);
	
}
