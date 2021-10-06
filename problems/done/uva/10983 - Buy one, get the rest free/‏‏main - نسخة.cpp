#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 31
#define vi vector<int>
#define piv pair<int,vi>
#define P first
#define U second[0]
#define V second[1]
#define C second[2]
#define E second[3]

vector<piv> flights;
array<int, MAX> cityCnt;
int main()
{
    int N; cin >> N;
    while(N--)
    {
        int n, d, m;
        int u, v, p, c, e;
        int cnt = 0;

        flights.clear();
        cityCnt.fill(0);

        scanf("%d %d %d", &n, &d, &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d %d %d", &u, &v, &p, &c, &e);
            flights.push_back({-p,{u, v, c, e}});
        }
        for(int i = 0; i < n; i++)
        {
            cin >> cityCnt[i];
            cnt += cityCnt[i];
        }

        sort(flights.begin(), flights.end());
        int mn = 0, sz = flights.size();
        for(int i = 0; i < sz; i++)
        {
            int _cnt = cnt;
            array<int, MAX> _cityCnt = cityCnt;

            for(int j = i; j < sz; j++)
            {
                piv fl = flights[j];
                if(_cityCnt[fl.U] > 0 && fl.E < d)
                {
                    int _mn =  min(_cityCnt[fl.U], fl.C);
                    _cnt -= _mn;
                    _cityCnt[fl.U] -= _mn;
                }
            }

            if (_cnt == 0) mn = min(mn, flights[i]);
        }
        cout << mn << endl;
    }
    return 0;
}
