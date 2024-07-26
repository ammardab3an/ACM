// Problem: 1521. War Games 2
// Contest: Timus Online Judge - Timus Top Coders: Third Challenge
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1521
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an 

#include<bits/stdc++.h>

using namespace std;

struct FenwickTree{
	
	int n;
	int sz;
	int lg_n;
	vector<int> bit;
	
	FenwickTree(){
		assert(false);
	}
	
	FenwickTree(int n) : n(n){
		lg_n = int(ceil(log2(double(n))));
		sz = 1 << lg_n;
		bit.resize(sz, 0);
	}
	
	FenwickTree(const vector<int> &vec) : FenwickTree(vec.size()){
		
		for(int i = 0; i < n; i++){
			bit[i] += vec[i];
		}
		
		for(int i = 0; i < sz; i++){
			int r = i | (i+1);
			if(r < sz) bit[r] += bit[i];
		}
	}
	
	int query(int i){
		int ret = 0;
		while(i >= 0){
			ret += bit[i];
			i = (i&(i+1))-1;
		}
		return ret;
	}
	
	int query(int l, int r){
		int ret = query(r) - query(l-1);
		return ret;
	}
	
	void update(int i, int d){
		while(i < sz){
			bit[i] += d;
			i |= i+1;
		}
	}
	
	int lower_bound(int val){
		int ptr = 0;
		for(int i = lg_n-1; i >= 0; i--){
			if(val-bit[ptr+(1<<i)-1] > 0){	
				val -= bit[ptr+(1<<i)-1];
				ptr += (1<<i);
			}
		}
		return ptr;
	}
};

int main(){
	
	int n, k;
	cin >> n >> k;
	
	FenwickTree st(vector<int>(2*n, 1));
	
	vector<int> ans;
	
	int lst = k-1;
	st.update(lst, -1);
	st.update(n+lst, -1);
	ans.push_back(lst);
	
	for(int i = 1; i < n; i++){

		int rm = n-i;
		int cur = (st.query(lst)+k-1)%(2*rm)+1;
		int p = st.lower_bound(cur)%n;
		
		st.update(p, -1);
		st.update(n+p, -1);
		ans.push_back(p);
		
		lst = p;
	}
	
	for(auto e : ans) cout << e+1 << ' ';
	cout << endl;
}