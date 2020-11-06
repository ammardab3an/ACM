
// Problem : I - Simple Equations
// Contest : Virtual Judge - Week # 1.1 [Complete search - Iterative&Recursive]- Easy~Medium
// URL : https://vjudge.net/contest/395176#problem/I
// Memory Limit : 1024 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

typedef long long int       lli;
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

const int MAX = 2e5 + 10;

int a, b, c;
int ansX, ansY, ansZ;

vector<int> vec;
bool go(int pos){
	
	if(pos > 10000) 
		return false;

	vec.push_back(pos);
		
	if(vec.size() == 1){
		if(vec[0] > a || vec[0] > b || vec[0]*vec[0] > c) return false;	
	}
	
	else if(vec.size() == 2){

		int i0 = vec[0] + vec[1];
		int i1 = vec[0] * vec[1];
		int i2 = vec[0]*vec[0] + vec[1]*vec[1];
		
		if(i0 > a || i1 > b || i2 > c) return false;	
	}
	
	else if(vec.size() == 3){
		
		int i0 = vec[0] + vec[1] + vec[2];
		int i1 = vec[0] * vec[1] * vec[2];
		int i2 = vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2];
		
		if(i0 == a && i1 == b && i2 == c){
			ansX = vec[0];
			ansY = vec[1];
			ansZ = vec[2];
			return true;
		}
		else
			return false;
	} 

	if(go(pos+1)) return true;	
	
	vec.pop_back();
	
	if(go(pos+1)) return true;	
	
	return false;
}

int main(){

    fastIO;
	
	int t; cin >> t; while(t--){
		
		cin >> a >> b >> c;
		
		if(go(1)){
			cout << ansX << ' ' << ansY << ' ' << ansZ << endl;
		}
		else{
			cout << "No solution." << endl;
		}
		

	}
	
}
