#include <bits/stdc++.h>
using namespace std;

struct node{
    
}
short seg[1073741824];

void add(int x, int sign){
    int curIdx = 1;
    for(int i = 30; i >= 0; i--){        
        seg[curIdx] += sign;
        curIdx *= 2;
        curIdx += bool(x & (1 << i));
    }
}

int query(int x){

    int ans = 0;

    int curIdx = 1;

    for(int i = 30; i >= 0; i--){
    
        curIdx *= 2;

        if(x & (1 << i)){
            if(seg[curIdx] == 0)
                curIdx += 1;
        }
        else {
            if(seg[curIdx + 1]){
                curIdx += 1;
                ans |= 1 << i;
            }
        }
    }
    return ans;
}

int main(){

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int k;
    for(cin >> k; k--;){
        cout << k << endl;
        char fn; int x;
        cin >> fn >> x;

        switch(fn){

            case '+':
                add(x, +1);
                break;

            case '-':
                add(x, -1);
                break;

            case '?':
                cout << query(x) << endl;
                break;
        }
    }
}