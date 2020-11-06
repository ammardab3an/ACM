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

#define MAX_N 105
#define UNVISITED -1

bool artPoint[MAX_N];
vector<pair<int, int> > bridges; //bridge between u and v

int par[MAX_N], num[MAX_N], low[MAX_N];
int cnt;
vector<int> G[MAX_N]; //Graph
int N = 6;
void dfsArticulationPointsAndBridges(int u) {
	num[u] = low[u] = cnt++;
	for (int i=0; i<(int)G[u].size(); i++) {
		int v = G[u][i];
		if (num[v] == UNVISITED) {
			par[v] = u;
			dfsArticulationPointsAndBridges(v);

			if (num[u] <= low[v]) artPoint[u] = 1;
			if (num[u] < low[v]) bridges.push_back(make_pair(u, v));
			low[u] = min(low[u], low[v]);
		} else if(par[u] != v) low[u] = min(low[u], num[v]);
	}
}

int main() {
	//you have to fill the graph
//	G[0].push_back(1); G[1].push_back(0);
//	G[1].push_back(2); G[2].push_back(1);
//	G[1].push_back(3); G[3].push_back(1);
//	G[1].push_back(4); G[4].push_back(1);
//	G[1].push_back(5); G[5].push_back(1);
//	G[4].push_back(5); G[5].push_back(4);


	G[0].push_back(1), G[1].push_back(2), G[2].push_back(0);
	G[1].push_back(0), G[2].push_back(1), G[0].push_back(2);

	cnt = 0;
	memset(num, UNVISITED, sizeof num);
	memset(par, -1, sizeof par);

	dfsArticulationPointsAndBridges(0);
	//articulation points
	//loop on all vertices on the graph
	for (int i=0; i<N; i++) {
		if (!artPoint[i]) continue;
		if (i==0 && G[i].size() < 2) continue; //it should have more than one children
		cout << i << " ";
	}

	cout << "\nBridges \n";

	//bridges
	for(int i=0; i<(int)bridges.size(); i++)
		cout << bridges[i].first << " " << bridges[i].second <<"\n";
	return 0; 
}
