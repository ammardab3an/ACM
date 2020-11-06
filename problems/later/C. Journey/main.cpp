#inc    lude <bits/stdc++.h>

using namespace std;

const int MAX = 100010;
array<vector<int>, MAX> adj;
bool vist[MAX];

set<int> st;

int go(int fr)
{
   vist[fr] = true;
    double ins = 0;
   for(auto to : adj[fr]) if(!vist[to])
   {
       go(to);

   }
}
int main()
{
    int N, fr, to;
    for(cin >> N; --N;)
    {
        cin >> fr >> to;
        adj[fr].push_back(to);
        adj[to].push_back(fr);
    }

    memset(vist, false, sizeof vist);

    go(1, 0);

    cout << setprecision(15) << fixed << (float)accumulate(st.begin(), st.end(), 0) / st.size();

}
