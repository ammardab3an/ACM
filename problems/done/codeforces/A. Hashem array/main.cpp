#include<bits/stdc++.h>

using namespace std;

vector<long long> vec;
set   <long long> mem[60][60];

void go(int pos, int k)
{
    if(mem[pos][k].empty())

        for(int n = (k == 1) ? pos : 1; n <= (pos - (k-1)); n++)
        {
            go(pos - n, k - 1);
            for(auto e : mem[pos - n][k - 1])
                mem[pos][k].insert(e & (vec[pos] - vec[pos-n]));
        }
}
int main()
{
    int T, N, K;
    for(cin >> T;T;T--)
    {
        vec = {0};
        cin >> N >> K;

        long long A;
        for(int i = 0; (i < N) && (cin >> A); i++)
            vec.push_back(vec.back() +A);

        for(int i = 0; i < 60; i++)
        for(int j = 0; j < 60; j++)
            mem[i][j].clear();

        mem[0][0].insert(((long long)1 << 63)-1);

        go(N, K);
        set<long long> _go = mem[N][K]; _go.insert(0);

        cout << *max_element(_go.begin(), _go.end()) << endl;
    }
}
