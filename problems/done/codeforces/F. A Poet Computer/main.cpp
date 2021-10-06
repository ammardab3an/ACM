// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

int ansLen, ansCnt;

struct node{

    int cnt;
    node * nxt[26];

    node(){
        cnt = 0;
        for(int i = 0; i < 26; i++)
            nxt[i] = nullptr;
    }
};

void insertTree(node & root, string & str){

    node * cur = & root;

    for(int i = 0; i < str.size(); i++){

        int j = tolower(str[i]) - 'a';

        if(!cur -> nxt[j])
            cur -> nxt[j] = new node();

        cur = cur -> nxt[j];
        cur -> cnt++;

        if(i+1 > ansLen && cur -> cnt > 2){
            ansLen = i+1;
            ansCnt = cur -> cnt;
        }
        else if(i+1 == ansLen)
            ansCnt = max(ansCnt, cur -> cnt);
    }
}


int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for(int TT = 1; TT <= T; TT++){

        int n;
        cin >> n;

        vector<string> vec(n);
        for(int i = 0; i < n; i++){
            cin >> vec[i];
            reverse(vec[i].begin(), vec[i].end());
        }

        node root = node();
        ansLen = ansCnt = 1;

        for(int i = 0; i < n; i++)
            insertTree(root, vec[i]);

        cout << "Case " << TT << ":\n";
        cout << ansLen << ' ' << ansCnt << endl;
    }
}
