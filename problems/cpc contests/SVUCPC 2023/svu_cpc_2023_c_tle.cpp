#include<bits/stdc++.h>

// #define int int64_t
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;

const int NMAX = 2e6 + 100;
const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;

int n;
int arr_h[NMAX];
int arr_s[NMAX];
int rem_h[NMAX];

int vals[NMAX];
pii tree[NMAX << 2];
int lazy[NMAX << 2];

#define assert bool

pii merge(const pii &a, const pii &b){
	assert(a.first == INFLL || a.second < b.second);
	return min(a, b); 
}

void push(int nd, int l, int r){
	
	if(!lazy[nd]){
		return;
	}
	
	tree[nd].first += lazy[nd];
	
	if(l != r){
		lazy[nd*2] += lazy[nd];
		lazy[nd*2+1] += lazy[nd];
	}
	
	lazy[nd] = 0;
}

void build(int nd, int l, int r){
	
	lazy[nd] = 0;
	
	if(l==r){
		tree[nd] = {vals[l], l};
		return;
	}
	
	int mid = (l+r)/2;
	build(nd*2, l, mid);
	build(nd*2+1, mid+1, r);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update(int nd, int l, int r, int q_l, int q_r, int val){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return;
	}
	
	if(q_l <= l && r <= q_r){
		lazy[nd] += val;
		push(nd, l, r);
		return;
	}
	
	int mid = (l+r)/2;
	update(nd*2, l, mid, q_l, q_r, val);
	update(nd*2+1, mid+1, r, q_l, q_r, val);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

void update_p(int nd, int l, int r, int p, int val){
	
	push(nd, l, r);
	
	if(p < l || r < p){
		return;
	}
	
	if(l==r){
		tree[nd] = {val, l};
		return;
	}
	
	int mid = (l+r)/2;
	update_p(nd*2, l, mid, p, val);
	update_p(nd*2+1, mid+1, r, p, val);
	
	tree[nd] = merge(tree[nd*2], tree[nd*2+1]);
}

pii query(int nd, int l, int r, int q_l, int q_r){
	
	push(nd, l, r);
	
	if(r < q_l || q_r < l){
		return {INFLL, INFLL};
	}
	
	if(q_l <= l && r <= q_r){
		return tree[nd];
	}
	
	int mid = (l+r)/2;
	pii st_path = query(nd*2, l, mid, q_l, q_r);
	pii nd_path = query(nd*2+1, mid+1, r, q_l, q_r);
	
	return merge(st_path, nd_path);
}

int query_p(int nd, int l, int r, int p){
	
	push(nd, l, r);
	
	if(l==r){
		return tree[nd].first;
	}
	
	int mid = (l+r)/2;
	
	if(p <= mid){
		return query_p(nd*2, l, mid, p);
	}
	else{
		return query_p(nd*2+1, mid+1, r, p);
	}
}

void solve(){
	
	deque<pair<int, pair<int, int>>> v;
	
	for(int i = 0; i < n; i++){
		v.push_back({arr_h[i], {arr_s[i], i+1}});
	}	
		
	while(v.size() > 1){
		v[1].first -= v[0].second.first;
		if(v.front().first > 0){
			v.push_back(v.front());
		}
		else{
			cout << v.front().second.second << ' ';
		}
		v.pop_front();
	}
	
	cout << v.front().second.second << endl;
}

signed main(){
	
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t; while(t--){
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> arr_h[i];
			rem_h[i]=rem_h[i+n] = arr_h[i];
		}
		
		for(int i = 0; i < n; i++){
			cin >> arr_s[i];
		}
		
		for(int i = 0; i < n; i++){
			int h = arr_h[i];
			int s = arr_s[(i-1+n)%n];
			vals[i] = vals[i+n] = (h+s-1)/s;
		}
		
		// solve();
		
		int m = n*2;
		build(1, 0, m-1);
		
		set<int> idxs;
		
		for(int i = 0; i < n; i++){
			idxs.insert(i);
			idxs.insert(i+n);
		}
		
		int p = 1;
		vector<int> ans;
		
		while(!idxs.empty()){
			
			auto [val, pos] = query(1, 0, m-1, p, m-1);
			
			vector<int> del;
			auto it = idxs.find(pos);
			assert(it != idxs.end());
			
			int l = *it;
			int r = l;
			
			while(it != idxs.end()){
				int cval = query_p(1, 0, m-1, *it);
				if(cval != val) break;
				r = *it;
				del.push_back(*it);
				del.push_back(((*it)+n)%m);
				ans.push_back((*it)%n);
				it++;
			}
			
			for(auto i : del){
				idxs.erase(i);
				update_p(1, 0, m-1, i, INFLL);
			}
			
			assert(p <= l);
			assert(p <= l && l <= r && r < m);
			// assert(val > 0)
			
			if(val > 1){
				update(1, 0, m-1, 0, m-1, -(val-1));
			}
			
			if(r < n){
				int ql = p;
				int qr = l-1;
				update(1, 0, m-1, ql, qr, -1);
				update(1, 0, m-1, ql+n, qr+n, -1);
			}
			else if(l >= n){
				assert(l-n < p);
				{
					int ql = p;
					int qr = n-1;
					update(1, 0, m-1, ql, qr, -1);
					update(1, 0, m-1, ql+n, qr+n, -1);
				}
				{
					int ql = 0;
					int qr = (l-n)-1;
					update(1, 0, m-1, ql, qr, -1);
					update(1, 0, m-1, ql+n, qr+n, -1);
				}
			}
			else if(l < n){
				assert(r >= n);
				int ql = p;
				int qr = l-1;
				update(1, 0, m-1, ql, qr, -1);
				update(1, 0, m-1, ql+n, qr+n, -1);
			}
			else{
				assert(false);
			}
			
			if(idxs.size() <= 2){
				for(auto i : idxs) ans.push_back(i%n);
				idxs.clear();
				break;
			}
			
			{
				auto it = idxs.upper_bound(r%n);
				assert(it != idxs.end());
				
				p = *it;
				if(p > n) p -= n;
				
				rem_h[p] -= (vals[p] - query_p(1, 0, m-1, p) + 1) * arr_s[r%n];
				rem_h[p] = max(rem_h[p], int(0));
				
				int q = -1;
				if(it != idxs.begin()){
					q = *(--it);
				}
				else{
					q = *idxs.rbegin();
				}
				
				if(q > n) q -= n;
				
				int h = rem_h[p];
				int s = arr_s[q];
				
				vals[p] = vals[p+n] = (h+s-1)/s;
				
				update_p(1, 0, m-1, p, vals[p]);
				update_p(1, 0, m-1, p+n, vals[p+n]);
				
				if(!vals[p]) it = idxs.lower_bound(p);
				else it = idxs.upper_bound(p);
				
				assert(it != idxs.end());
				
				p = *it;
				if(p > n) p -= n;
			}
		}
		
		vector<bool> vis(n);
		for(auto e : ans) if(!vis[e]){
			vis[e] = true;
			cout << e+1 << ' ';
		}
		cout << endl;
	}
}