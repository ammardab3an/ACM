#include "bits/stdc++.h"

using namespace std;

void count_sort(vector<int> &p, vector<int> &c){

    int n = p.size();
	
	vector<int> cnt(n), pos(n), p_new(n);
	
	for(auto i : c) {
		cnt[i]++;	
	}
	
    pos[0] = 0;
    for(int i = 1; i < n; i++){
    	pos[i] = pos[i-1] + cnt[i-1];
    }
    
	for(auto x : p){
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}
	
    p = p_new;

}

void suffix(string str){

    str += "$";
    int n = str.size();

    vector<int> p(n), c(n);

    {
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
        	a[i] = {str[i], i};        	
        }

        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++){
        	p[i] = a[i].second;        	
        }

        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]] +1;

        }
    }

    for(int k = 0; (1 << k) < n; k++){

        for(int i = 0; i < n; i++){
        	p[i] = (p[i] - (1 << k) + n) % n;
        }
        
		count_sort(p, c);
		
		vector<int> c_new(n);
		
        c_new[p[0]] = 0;
        for(int i = 1; i < n; i++){
            
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
            pair<int, int> now  = {c[p[ i ]], c[(p[ i ] + (1 << k)) % n]};

            if(now == prev)
                c_new[p[i]] = c_new[p[i-1]];
            else
                c_new[p[i]] = c_new[p[i-1]] +1;

        }
        
        c = c_new;
    }

    for(int i = 0; i < n; i++)
        cout << p[i] << ' ';
}

int main(){

    string str;
    cin >> str;
    suffix(str);
}
