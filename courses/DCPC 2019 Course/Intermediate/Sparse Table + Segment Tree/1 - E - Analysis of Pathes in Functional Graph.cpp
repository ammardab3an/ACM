#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100100

ll n, k;
ll parent[N][40];
ll sum[N][40];
ll mn[N][40];
ll p[N];
ll w[N];

void buildParent(){
	for (int j = 0; j < 40; j++){
		for (int i = 0; i < n; i++){
			if (!j){
				parent[i][j] = p[i];
				continue;
			}
			int jParent = parent[i][j - 1];
			parent[i][j] = parent[jParent][j - 1];
		}
	}
}

void buildSum(){
	for (int j = 0; j < 40; j++){
		for (int i = 0; i < n; i++){
			if (!j){
				sum[i][j] = w[i];
				continue;
			}
			int jParent = parent[i][j - 1];
			sum[i][j] = sum[i][j - 1] + sum[jParent][j - 1];
		}
	}
}

ll querySum(int v){
	ll len = k, i = 0;
	ll ans = 0;
	while (len){
		if (len % 2){
			ans += sum[v][i];
			v = parent[v][i];
		}
		len /= 2;
		i++;
	}
	return ans;
}

void buildMin(){
	for (int j = 0; j < 40; j++){
		for (int i = 0; i < n; i++){
			if (!j){
				mn[i][j] = w[i];
				continue;
			}
			int jParent = parent[i][j - 1];
			mn[i][j] = min(mn[i][j - 1], mn[jParent][j - 1]);
		}
	}
}

ll queryMin(int v){
	ll len = k, i = 0;
	ll ans = 1e18;
	while (len){
		if (len % 2){
			ans = min(ans, mn[v][i]);
			v = parent[v][i];
		}
		len /= 2;
		i++;
	}
	return ans;
}

int main(){
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> w[i];

	buildParent();
	buildSum();
	buildMin();
	for (int i = 0; i < n; i++){
		ll s = querySum(i);
		ll m = queryMin(i);
		cout << s << " " << m << endl;
	}

	return 0;
}