// Problem: A. Maze
// Contest: Codeforces - Codeforces Round #222 (Div. 1)
// URL: https://codeforces.com/problemset/problem/377/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef multiset<int> msi;
typedef pair<int, int> pi;
typedef vector<int> vi;

string read(char x[]) {
    scanf("%s", x);
    return x;
}

const int N = 8;
const int M = 2e5 + 23;

char v[M];
// int f(int u){return root [u] == u ? u : (root[u] = f(root[u]));}
int cnt[M], n, m, k;
string s[555];
queue<pi> q;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int lvl[555][555];

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#';
}

stack<pi> ans;

void bfs(int x, int y) {
    q.push({x, y});
    lvl[x][y] = 1;
    while(!q.empty()) {
        pi cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(!check(nx, ny)) continue;
            if(lvl[nx][ny]) continue;
            lvl[nx][ny] = lvl[cur.first][cur.second] + 1;
            q.push({nx, ny});
            ans.push({nx, ny});
        }
    }
}

void solve() {
    scanf("%d %d %d", &n, &m, &k);
    pi f;
    for(int i = 0; i < n; i++) s[i] = read(v);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            if(s[i][j] == '.') {
                f.first = i, f.second = j;
                break;
            }
    }
    bfs(f.first, f.second);
    for(int i = 0; i < k; i++) {
        s[ans.top().first][ans.top().second] = 'X';
        ans.pop();
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) printf("%c", s[i][j]);
        puts("");
    }
}

int main() { solve(); }