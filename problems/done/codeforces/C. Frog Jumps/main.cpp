// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

int strSz;
string str;

bool can(int mx){

    for(int i = -1;;){

        if(i+mx >= strSz)
            return true;

        bool found = false;

        for(int j = 1; j <= mx; j++) if(str[i+j] == 'R'){
            i += j;
            found = true;
            break;
        }

        if(!found) return false;
    }
}

void solve(){

    cin >> str;
    strSz = str.size();

    int l = 1, r = strSz +1;

    while(l < r){

        int mid = (l + r) /2;

        if(can(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

	while(t--){
		solve();
	}
}
