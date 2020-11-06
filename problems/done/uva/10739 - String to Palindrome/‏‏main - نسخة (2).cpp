// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

// Global Variables

const int MAX = 1e3 + 10;

string str;
int mem[MAX][MAX];

struct state{
    int i, j;
    bool isProcessed;
    state(int i, int j) : i(i), j(j), isProcessed(0) {}
};

int best(int i, int j){

    stack<state> st;
    state cur = state(i, j);
    st.push(cur);

    while(!st.empty()){

        cur = st.top(), i = cur.i, j = cur.j; st.pop();

        if(mem[i][j] == -1){

            if(i >= j)
                mem[i][j] = 0;

            else if(!cur.isProcessed){

                cur.isProcessed = true;
                st.push(cur);

                st.push(state(i+1, j-1));
                st.push(state(i+1, j));
                st.push(state(i, j-1));
            }
            else
                mem[i][j] = min(mem[i+1][j-1] + (str[i] != str[j]), min(mem[i+1][j] +1, mem[i][j-1] +1));
        }
    }

    return mem[cur.i][cur.j];
}

int main(){

    int t; cin >> t;

    for(int i = 1; i <= t; i++){

        cin >> str;
        memset(mem, -1, sizeof mem);
        cout << "Case " << i << ": " << best(0, str.size()-1) << endl;
    }
}
