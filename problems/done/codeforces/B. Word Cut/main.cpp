#include<bits/stdc++.h>

using namespace std;

const int modulo = 1000000007;
int sz;
map<int, bool> w;
map<pair<int,int>, int> mem;

inline string operator >> (string str, int i)
{
    return str.substr(i) + str.substr(0, i);
}


int dp(int ii, int k)
{
    if(mem.count({ii,k})) return mem[{ii,k}];

    if (!k) return (w.count(ii));

    int cnt = 0;
    for(int i = 1; i < sz; i++)
    {
        cnt = (cnt + dp((ii+i)%sz, k-1)) % modulo;
    }
    return mem[{ii,k}] = cnt;
}

int main()
{
    string startStr, endStr;
    cin >> startStr >> endStr;
    sz = startStr.size();
    for(int i = 0; i < sz; i++)
        if (startStr >> i == endStr)
            w[i] = 0;
    if(!w.size())
    {
        cout << 0 << endl;
        return 0;
    }

    int K;
    cin >> K;
    cout << dp(0, K) << endl;

    return 0;
}
