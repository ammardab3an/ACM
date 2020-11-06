#include<bits/stdc++.h>

using namespace std;

const int MAX = 111;

int main()
{
    for(int N; cin >> N && N;)
    {
        string inputStr;
        bool adj[MAX][MAX];
        memset(adj, false, sizeof adj);

        for(int fr, to; getline(cin, inputStr) && (inputStr != "0");)
        {
            stringstream ss(inputStr);
            ss >> fr;
            while(ss >> to)
                adj[fr][to] = adj[to][fr] = true;
        }

        int cnt = 0;

        bool can[MAX];
        memset(can, true,  sizeof can);

        for(int n = 1; n <= N; n++)
        {
            can[n] = false;

            int cu = (n != 1) ? 1 : 2;

            bool vst[MAX];
            memset(vst, false, sizeof vst);
            vst[cu] = true;

            queue<int> que; que.push(cu);
            while(!que.empty())
            {
                int fr = que.front(); que.pop();
                for(int to = 1; to <= N; to++)
                    if(can[to] && adj[fr][to] && !vst[to]++)
                        que.push(to);
            }

            for(int nn = 1; nn <= N; nn++)
            if((n != nn) && !vst[nn])
            {
                cnt++;
                break;
            }

            can[n] = true;
        }
        cout << cnt << endl;
    }
}
