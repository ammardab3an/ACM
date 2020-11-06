#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

#define f(i,s,e) for (int i = int(s); i != int(e); i++)
#define ft(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define all(c) (c).begin(), (c).end()

//read scanf functions
#define readI(x) scanf("%d", &x)
#define readL(x) scanf("%I64d", &x)
#define readD(x) scanf("%f", &x)
#define readII(x, y) scanf("%d %d", &x, &y)
#define readLL(x, y) scanf("%I64d %I64d", &x, &y)

typedef long long ll; 

#define OO (1<<30)
#define UNVISITED -1

#define MAX_N 105

int N;
vector<int> G[MAX_N];
int num[MAX_N], low[MAX_N];
bool visited[MAX_N];

vector<int> st; //stack
int cnt; //dfs cnt

//SCC, Cycle detection in directed graph
void dfsStronglyConnectedComponents(int u) {
	num[u] = low[u] = cnt++;
	visited[u] = 1;
	st.push_back(u);
	for (int i=0; i<(int)G[u].size(); i++) {
		int v = G[u][i];
		if (num[v] == UNVISITED) dfsStronglyConnectedComponents(v);
		if (visited[v]) low[u] = min(low[u], low[v]);
	}

	if (num[u] == low[u]) {
		while (1) {
			int v = st.back(); st.pop_back(), visited[v] = 0;
			cout << v << " ";
			if (v == u) break;
		}
		cout << "\n";
	}
}


int main() {
	memset(num, UNVISITED, sizeof num);

	//Create Graph

	for (int i=0; i<N; i++) {
		if (num[i] == UNVISITED) dfsStronglyConnectedComponents(i);
	}

	return 0; 
}
