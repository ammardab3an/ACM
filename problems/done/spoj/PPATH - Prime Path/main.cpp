#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int from, to;
vector<int> graph[10000];
bool         vist[10000];

void createTheGraph()
{
    bitset<10000> bs;
    bs.reset(); bs.flip();

    vector<int> primes;
    for(int i = 2; i < 10000; i++) if(bs.test(i))
    {
        for(int j = i*i; j < 10000; j+=i)
            bs.set(j, false);

        if(i > 1000) primes.push_back(i);
    }

    int sz = primes.size();

    for(int i = 0  ; i < sz; i++)
    for(int j = i+1; j < sz; j++)
    {
        int pi = primes[i];
        int pj = primes[j];

        if(((pi/1000 == pj/1000) + ((pi/100)%10 == (pj/100)%10) + ((pi/10)%10 == (pj/10)%10) + (pi%10 == pj%10)) == 3)
        {
            graph[pi].push_back(pj);
            graph[pj].push_back(pi);
        }
    }
}
void bfs()
{
    memset(vist, false, sizeof vist);
    vist[from] = true;

    queue<pii> que;
    que.push({from, 0});

    while(!que.empty())
    {
        pii fr = que.front(); que.pop();
        int pi = fr.first;
        int co = fr.second;

        if(pi == to)
        {
            cout << co << endl;
            return;
        }

        for(auto t : graph[pi]) if(!vist[t])
        {
            vist[t] = true;
            que.push({t, co+1});
        }
    }
}
int main()
{
    createTheGraph();

    int T;
    for(cin >> T; T; T--)
    {
        cin >> from >> to;
        bfs();
    }
}
