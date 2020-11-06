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

// Global Variables

const int MAX = 2e5 + 10;

int smArr0[MAX];
int smArr1[MAX];

void solve(){

    int n;
    cin >> n;

    string str;
    cin >> str;

    int strSz = str.size();

    smArr0[0] = 0;
    smArr1[0] = 0;

    for(int i = 1; i <= strSz; i++){

        char c = str[i-1];

        smArr0[i] = smArr0[i-1];
        smArr1[i] = smArr1[i-1];

        if(c == 'R')
            smArr0[i]++;
        else if(c == 'L')
            smArr0[i]--;
        else if(c == 'U')
            smArr1[i]++;
        else
            smArr1[i]--;
    }

    for(int i = 0; i <= strSz; i++)
        cout << smArr0[i] << ' ';
    cout << endl;
    for(int i = 0; i <= strSz; i++)
        cout << smArr1[i] << ' ';
    cout << endl;

    for(int ln = 2; ln <= strSz; ln++)
    for(int  i = 1, j = i+ln-1; j <= strSz; i++, j = i+ln-1){

        int sm0 = smArr0[j] - smArr0[i-1];
        int sm1 = smArr1[j] - smArr1[i-1];

        if(!sm0 && !sm1){
            cout << i << ' ' << j << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
