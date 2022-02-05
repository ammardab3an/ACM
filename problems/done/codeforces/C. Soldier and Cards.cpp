#include<bits/stdc++.h>

using namespace std;

//declarations
queue<int> q[2];

pair<int, int> go()
{
    int cnt = 0;
    int t0, t1;
    while(!q[0].empty() && !q[1].empty())
    {
        if (cnt > 1000) return {0, 0};
        t0 = q[0].front(); q[0].pop();
        t1 = q[1].front(); q[1].pop();
        if (t0 > t1)
        {
            q[0].push(t1);
            q[0].push(t0);
        }
        else
        {
            q[1].push(t0);
            q[1].push(t1);
        }
        cnt++;
    }
    return {cnt, (q[1].empty()) ? 1 : 2};
}

void input()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2; i++){
        int k;
        cin >> k;
        while (k--){
            int ch;
            cin >> ch;
            q[i].push(ch);
        }
    }
}

void output(pair<int, int> p)
{
    if (p.second)
        cout << p.first << " " << p.second;

    else
        cout << -1;
}

int main()
{
    input();
    output(go());
    return 0;
}
