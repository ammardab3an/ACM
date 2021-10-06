#include <bits/stdc++.h>
#define    ll    long long
#define    ld    long double
#define    pb    push_back
#define    F     first
#define    S     second
 
using namespace std ;

const ll MAX = 1e4 + 10 , OO = 1e9 +10 , MOD = 1e9+7;
const ld pi = acos(-1) ;

int t , x1 , x2 , ans ;

int szi, szj;
int mem[MAX][MAX];


int main()
{
	
	for(int i = 0; i < MAX; i++) mem[i][0] = mem[0][i] = 1;
		
	for(int i = 1; i < MAX; i++){
		for(int j = 1; j < MAX; j++){
			
//			if(!i || !j){mem[i][j] = 1; continue;}   # look at line num22

			mem[i][j] += mem[i-1][j] + mem[i][j-1];
			
			if(mem[i][j] >= MOD) mem[i][j] -= MOD;
		}
	}

    int t; cin >> t; while(t--){
		cin >> szi >> szj;
		cout << mem[szi][szj] << endl;
	}
               
}