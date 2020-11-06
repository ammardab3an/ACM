// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

// Global Variables

const int MAX = 1e3 + 10;

string str;
int mem[MAX][MAX];

int best(int i, int j){

    if(i >= j)
        return 0;

    int & ret = mem[i][j];
    if(ret != -1) return ret;

    ret = best(i+1, j-1) + (str[i] != str[j]);
    ret = min(ret, best(i+1, j) + 1);
    ret = min(ret, best(i, j-1) + 1);

    return ret;
}

int main(){

    freopen("output.txt", "w", stdout);

    int t; cin >> t;

    for(int i = 1; i <= t; i++){

        cin >> str;
        memset(mem, -1, sizeof mem);
        cout << "Case " << i << ": " << best(0, str.size()-1) << endl;
    }
}
