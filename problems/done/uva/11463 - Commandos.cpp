#include <bits/stdc++.h>

using namespace std;

int main()
{
    int graph[110][110];
    int T, N, R, fr, to, be, en, Case = 1;

    for(cin >> T; T--;)
    {
        cin >> N >> R;

        for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            graph[i][j] = (i != j) ? 0xffff : 0;

        while(R--)
        {
            cin >> fr >> to;
            graph[fr][to] = 1;
            graph[to][fr] = 1;
        }

        cin >> be >> en;

        for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);

        int cost = 0;
        for(int i = 0; i < N; i++)
            cost = max(graph[be][i] + graph[i][en], cost);

        printf("Case %d: %d\n", Case++, cost);
    }
}
