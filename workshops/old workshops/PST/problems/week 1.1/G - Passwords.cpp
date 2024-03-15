
// Problem : G - Passwords
// Contest : Virtual Judge - Week # 1.1 [Complete search - Iterative&Recursive]- Easy~Medium
// URL : https://vjudge.net/contest/395176#problem/G
// Memory Limit : 1024 MB
// Time Limit : 3000 ms
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

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int MAX = 2e5 + 10;

int szRule;
string rule;
vector<string> words;

string str[300];
void go(int pos){
	
	if(pos == szRule){
		for(int i = 0; i < szRule; i++)
			cout << str[i];
		cout << endl;
	}
	
	else if(rule[pos] == '#'){
		for(string word : words){
			str[pos] = word;
			go(pos+1);
		}
	}
	else{
		for(char num = '0'; num <= '9'; num++){
			str[pos] = string(1, num);
			go(pos+1);
		}
	}
}

int main(){

    fastIO;
	
	int n, m;
	while(cin >> n){
		
		cout << "--" << endl;
		
		words.clear();
		words.resize(n);
		for(int i = 0; i < n; i++) cin >> words[i];
		
		cin >> m;
		while(m--){
			cin >> rule;
			szRule = rule.size();
			go(0);
		}
	}
}
