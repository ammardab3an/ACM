#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin.tie(NULL);
    for(cin >> T;T;T--)
    {

        map<int, int>  Map[30000];
        map<int, bool> arr[30000];

        int N; cin >> N;
        for(int f, t, w, i = 0; i < N-1; i++)
        {
            cin >> f >> t >> w;
            Map[f][t] = Map[t][f] = w;
            arr[f][t] = arr[t][f] = 1;
        }
        for(int k = 0; k < N; k++)
        for(int j = 0; j < N; j++)
        for(int i = 0; i < N; i++)
            if(arr[i][k] && arr[k][j])
            {
                if(!Map[i][j])
                    Map[i][j] = INT_MAX;

                Map[i][j] = Map[j][i] = min(Map[i][j], Map[i][k] + Map[k][j]);
                arr[i][j] = arr[j][i] = 1;
            }

        for(int i = 0; i < N; i++)
        {
            int mx = 0;
            for(auto m:Map[i])
                if(m.first != i)
                    mx = max(mx, m.second);
            cout << mx << endl;
        }
    }
    return 0;
}
