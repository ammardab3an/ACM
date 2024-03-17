// Problem: H. Codeforces Scoreboard
// Contest: Codeforces - TypeDB Forces 2023 (Div. 1 + Div. 2, Rated, Prizes!)

#include "bits/stdc++.h"

using namespace std;

struct node{
	
	int size, dp, lazy;
	node *lf, *ri;
	
	~node(){
		delete lf;
		delete ri;
	}
	
	bool is_leaf(){
		assert((lf==0) == (size==1));
		return size==1;
	}
	
	void push(){
		if(!lazy) return;
		dp += lazy;
		if(lf) lf->lazy += lazy;
		if(ri) ri->lazy += lazy;
		lazy = 0;	
	}
	
	void merge(){
		assert(!is_leaf());
		assert(lazy==0);
		size = lf->size + ri->size;
		dp = ri->dp;
	}
	
	bool is_balanced()  {
		assert(!is_leaf());
		int l = lf->size;
		int r = ri->size;
		return (l <= 2*r+5) && (r <= 2*l+5);
	}
	
	void balance(){
		
		assert(!is_leaf());
		if(is_balanced()) return;
		
		vi elements;
		dfs(elements);
		build(elements);
	}
	
	void build(vi elements){
		
		lazy = 0;
		size = elements.size();
		dp = elements.back();
		
		delete lf;
		delete ri;
		
		assert(!elements.empty());
		
		if(elements.size()==1){
			lf = ri = nullptr;
			return;
		}	
		
		lf = new node();
		ri = new node();
		auto mid = elements.begin() + elements.size()/2;
		lf->build(vi(elements.begin(), mid));
		ri->build(vi(mid, elements.end()));
	}
	
	bool wants(int i, int k, int b){
		push();
		int tt = b-(i+size-1)*k;
		return tt > dp;	
	}
	
	void update(int i, int k, int b){
		
		push();
		
		if(is_leaf()){
			build({b-i*k, dp-k});
			return;
		}
		
		if(lf->wants(i, k, b)){
			lf->update(i, k, b);
			ri->lazy -= k;
			ri->push();
		}
		else{
			ri->update(i+lf->size, k, b);
		}
		
		merge();
		balance();
	}
	
	void dfs(vi &elements){
		
		push();
		
		if(is_leaf()){
			elements.push_back(dp);
		}
		else{
			lf->dfs(elements);
			ri->dfs(elements);
		}
	}
};

int32_t main(){
    
    fastIO;
    
    int t; cin >> t; while(t--){

		int n;
		cin >> n;
		
		int sm_a = 0;
		vector<pii> vec(n);
		
		for(auto &[k, b] : vec){
			cin >> k >> b;
			int ai;
			cin >> ai;
			sm_a += ai;
			b -= ai;
		}
		
		sort(vec.rbegin(), vec.rend());
		
		node rt = (node){1, -INFLL, 0, nullptr, nullptr};
		
		for(auto [k, b] : vec){
			rt.update(1, k, b);
		}
		
		vi elements;
		rt.dfs(elements);
		
		int ans = sm_a;
		for(auto e : elements){
			if(e >= 0){
				ans += e;			
			}
		}
		
		cout << ans << endl;
    }	
}
