
// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

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
#define multiCases false
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 100 + 10;

int arr[MAX][MAX];
int rows[MAX], cols[MAX];

int main(){

    int n;
    while(cin >> n){

        if(!n) break;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

        memset(rows, 0, sizeof rows);
        memset(cols, 0, sizeof cols);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                rows[i] += arr[i][j];
                cols[j] += arr[i][j];
            }
        }

        vector<int> vec_r, vec_c;

        for(int i = 0; i < n; i++){
            if(rows[i] % 2) vec_r.push_back(i);
            if(cols[i] % 2) vec_c.push_back(i);
        }

        if(vec_r.empty() && vec_c.empty()){
            cout << "OK" << endl;
        }
        else if(vec_r.size() == 1 && vec_c.size() == 1){
            cout << "Change bit (" << vec_r.back()+1 << "," << vec_c.back()+1 << ")" << endl;
        }
        else{
            cout << "Corrupt" << endl;
        }
    }
}
