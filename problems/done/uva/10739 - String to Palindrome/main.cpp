// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

// Global Variables

const int MAX = 1e3 + 10;

string str;
int mem[MAX][MAX];

int main(){

    int t; cin >> t;

    for(int i = 1; i <= t; i++){

        cin >> str;
        int sz = str.size();

        memset(mem, 0, sizeof mem);

        for(int len = 1; len <= sz; len++){

            for(int i = 0; i+len < sz; i++){

                int j = i + len -1 +1;

                mem[i][j] = min(mem[i+1][j-1] + (str[i] != str[j]), min(mem[i+1][j] +1, mem[i][j-1] +1));
            }
        }

        cout << "Case " << i << ": " << mem[0][sz-1] << endl;
    }
}

/*
6
tanbirahmed
shahriarmanzoor
monirulhasan
syedmonowarhossain
sadrulhabibchowdhury
mohammadsajjadhossain
5 7 6 8 8 8
*/
