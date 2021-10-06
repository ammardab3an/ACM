#include<bits/stdc++.h>

using namespace std;

int pri[101];
bool auc[101];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> pri[i];
    memset(auc, false, sizeof auc);
    for(int t, i = 1; i <= m; i++)
    {
        cin >> t;
        auc[t] = true;
    }
    long long int tot = 0;
    vector<int> vec;
    for(int i = 1; i <= n; i++)
    {
        if(auc[i])
            vec.push_back(pri[i]);
        else
            tot += pri[i];
    }
    sort(vec.begin(), vec.end());
    while(!vec.empty())
    {
        int f = vec.back(); vec.pop_back();
        if(f < tot)
            tot *= 2;
        else
            tot += f;
    }
    cout << tot;
    return 0;
}
