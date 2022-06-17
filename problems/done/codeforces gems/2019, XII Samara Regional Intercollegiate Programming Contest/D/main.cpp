#include<bits/stdc++.h>

using namespace std;

int32_t main(){

    string s;
    cin >> s;

    int n = s.length();
    vector<int> suf[3];
    suf[0].resize(n);
    suf[1] = suf[2] = suf[0];

    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'R') suf[0][i] = 1;
        else if(s[i] == 'G') suf[1][i] = 1;
        else suf[2][i] = 1;
        if(i != n-1){
            suf[0][i] += suf[0][i+1];
            suf[1][i] += suf[1][i+1];
            suf[2][i] += suf[2][i+1];
        }
    }

    bool ok = 0;

    string perm = "RGB";
    vector<int> perm1({0, 1, 2});

    // RGB
    do {

        bool curOk = 1;
        stack<int> s1, s2;
        for(int i = 0; i < n; i++){
            if(s[i] == perm[perm1[0]]){
                if(s1.empty() || s1.top() == perm1[0]) s1.push(perm1[0]);
                else {
                    if(!s2.empty() && s2.top() == perm1[2]){
                        curOk = 0;
                        break;
                    } else {
                        while(!s1.empty() && s1.top() == perm1[1]){
                            s2.push(perm1[1]);
                            s1.pop();
                        }
                    }
                }
            } else if(s[i] == perm[perm1[1]]){
                if(s2.empty() || s2.top() == perm1[1]) s2.push(perm1[1]);
                else s1.push(perm1[1]);
            } else {
                s2.push(perm1[2]);
            }
        }

        ok |= curOk;

    }
    while (next_permutation(perm1.begin(), perm1.end()));

    /*stack<int> s1, s2;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            if(s1.empty() || s1.top() == R) s1.push(R);
            else {
                if(!s2.empty() && s2.top() == B){
                    ok[0] = 0;
                    break;
                } else {
                    while(!s1.empty() && s1.top() == G){
                        s2.push(G);
                        s1.pop();
                    }
                }
            }
        } else if(s[i] == 'G'){
            if(s2.empty() || s2.top() == G) s2.push(G);
            else s1.push(G);
        } else {
            s2.push(B);
        }
    } */

    if(ok) puts("YES");
    else puts("NO");



}
