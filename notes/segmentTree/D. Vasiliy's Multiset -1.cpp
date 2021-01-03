#include <bits/stdc++.h>

using namespace std;

struct trieNode{
    int cnt;
    trieNode * nxt[2];

    trieNode(){
        cnt = 0;
        nxt[0] = nxt[1] = nullptr;
    }
};

void trieInsDel(trieNode & root, int num, int val){
    
    trieNode * cur = & root;

    for(int i = 31; i >= 0; i--){

        bool b = num & (1 << i);

        if(!cur -> nxt[b])
            cur -> nxt[b] = new trieNode();

        cur = cur -> nxt[b];
        cur -> cnt += val;
    }
}

int findMxXor(trieNode & root, int num){

    int ans = 0;

    trieNode * cur = & root;

    for(int i = 31; i >= 0; i--){

        bool b = num & (1 << i);
        trieNode * node_1 = cur -> nxt[!b];
        trieNode * node_2 = cur -> nxt[ b];

        if(node_1 && (node_1 -> cnt)){
            ans ^= !b << i;
            cur = node_1;
        }
        else{
            ans ^= b << i;
            cur = node_2;
        }
    }
    return ans;
}

int main(){

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    trieNode root = trieNode();
    trieInsDel(root, 0, +1);

    int k;
    for(cin >> k; k--;){
        
        char c; int num;
        cin >> c >> num;

        switch(c){
            case '+':
                trieInsDel(root, num, +1); break;
            case '-':
                trieInsDel(root, num, -1); break;
            case '?':
                cout << (num ^ findMxXor(root, num)) << endl;
        }
    }
}
