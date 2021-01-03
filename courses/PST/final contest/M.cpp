// Problem: M - 13
// Contest: Virtual Judge - Level 3 - Graduation Contest
// URL: https://vjudge.net/contest/414878#problem/M
// Memory Limit: 262 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include "bits/stdc++.h"

using namespace std;

#define int int64_t

#define endl '\n'
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin);
#define freopenO freopen("output.txt", "w", stdout);

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double  PI = acos(-1);

const int  MAX = 2e5 + 10;
const int NMAX = 2e5 + 10;
const int MMAX = 2e5 + 10;

int n;
int arr[NMAX];
int seg[NMAX << 2];
int lazy[NMAX << 2];

void build(int nd, int L, int R){
    
    if(L == R){
        seg[nd] = arr[L];
        return;
    }

    int mid = (L + R) >> 1;
    build(nd << 1, L, mid);
    build(nd << 1 | 1, mid+1, R);
    
    seg[nd] = min(seg[nd << 1], seg[nd << 1 | 1]);
}

void update(int nd, int L, int R, int from, int to, int val){

	if(lazy[nd]){
		seg[nd] += lazy[nd];
		if(L != R){
			lazy[nd*2] += lazy[nd];
			lazy[nd*2+1] += lazy[nd];
		}
		lazy[nd] = 0;
	}

    if(to < L || R < from)
        return;
                	
	if(from <= L && R <= to){
		seg[nd] += val;
		if(L != R){
			lazy[nd*2] += val;
			lazy[nd*2+1] += val;
		}
		return;
	}

    int mid = (L + R) >> 1;
    update(nd << 1, L, mid, from, to, val);
    update(nd << 1 | 1, mid+1, R, from, to, val);
    
    seg[nd] = min(seg[nd << 1], seg[nd << 1 | 1]);
}

int query(int nd, int L, int R, int from, int to){

	if(lazy[nd]){
		seg[nd] += lazy[nd];
		if(L != R){
			lazy[nd*2] += lazy[nd];
			lazy[nd*2+1] += lazy[nd];
		}
		lazy[nd] = 0;
	}
		    
    if(to < L || R < from)
        return INT_MAX;
        
    if(from <= L && R <= to)
        return seg[nd];

    int mid = (L + R) >> 1;
    int leftAns = query(nd << 1, L, mid, from, to);
    int rightAns = query(nd << 1 | 1, mid+1, R, from, to);
	
	return min(leftAns, rightAns);
}



int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

	{
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> arr[i];
		build(1, 1, n);
		
		
		int q; cin >> q; cin.ignore(); while(q--){
			
			string inputLine;
			getline(cin, inputLine);
			stringstream ss(inputLine);
			
			int l, r, v;
			bool b = 0;
			
			ss >> l >> r;
			if(ss >> v) b = 1;
			
			int ll, rr;
			bool bb = 0;
			
			if(l > r){
				
				bb = 1;
				
				ll = l;
				rr = n-1;
				
				l = 0;
				r = r;
			}
			
			if(b){
				update(1, 1, n, l+1, r+1, v);
				if(bb) update(1, 1, n, ll+1, rr+1, v);
			}
			else{
				int ans = query(1, 1, n, l+1, r+1);
				if(bb) ans = min(ans, query(1, 1, n, ll+1, rr+1));
				cout << ans << endl;
			}
		}
    }	
}
