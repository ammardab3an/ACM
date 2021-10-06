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

#define multiCases false
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)


struct node{

    char val;
    node * ptr;

    node(){
        val = '*';
        ptr = nullptr;
    }
};

string getStr(node & root){

    string str = "";

    node * tmp = &root;

    while(tmp -> ptr){
        if(tmp -> val != '*')
            str.push_back(tmp -> val);
        tmp = tmp -> ptr;
    }

    return str;
}

void solve(){

	string str;
	while(cin >> str){

        vector< pair< char, pair<node *, node *> > > vec;

        char fn = ']';
        node * root = new node();
        node * rootEnd = root;

        int strSz = str.size();
        for(int i = 0; i < strSz; i++){

            if(str[i] != '[' && str[i] != ']'){
                rootEnd -> val = str[i];
                rootEnd -> ptr = new node();
                rootEnd = rootEnd -> ptr;

            }

            else{
                vec.push_back({fn, {root, rootEnd}});

                root = new node();
                rootEnd = root;

                fn = str[i];
            }
        }

        vec.push_back({fn, {root, rootEnd}});

        node * ans = new node();
        node * ansEnd = ans;

        int vecSz = vec.size();
        for(int i = 0; i < vecSz; i++){

            if(vec[i].first == ']'){
                ansEnd -> ptr = vec[i].second.first;
                ansEnd = vec[i].second.second;
            }

            else{
                node * tmp1 = ans;
                node * tmp2 = ansEnd;

                ans = vec[i].second.first;
                ansEnd = vec[i].second.second;

                ansEnd -> ptr = tmp1;
                ansEnd = tmp2;

            }

        }

        cout << getStr(*ans) << endl;
	}
}

int main(){

    fastIO; //freopenI; freopenO;

    int t = 1; if(multiCases) cin >> t;

    while(t--){

        solve();
    }
}
