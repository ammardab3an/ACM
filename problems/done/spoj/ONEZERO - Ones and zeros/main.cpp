#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool is(int i, string d)
{
    string re = "";
    while(!d.empty())
    {
        int len = to_string(i).length();
        int c0 = stoi(d.substr(0,len));
        if (c0 < i)
        {
            if (!(len < d.length()))
            {
                if (d[0] == '0')
                    return true;
                return false;
            }
            len++;
            c0 = stoi(d.substr(0, len));
        }
        int c1 = c0 / i;
        re += to_string(c1);
        int c2 = c1 * i;
        d = to_string(c0 - c2) + d.substr(len);
    }
    return true;
}

string bfs(int i)
{
    queue<string> q;
    q.push("1");
    int ln = to_string(i).length();
    while (true)
    {
        string fs = q.front();
        q.pop();
        if (fs.length() >= ln)
            if (is(i, fs))
                return fs;
        q.push(fs + "0");
        q.push(fs + "1");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        cout << bfs(j) << endl ;
    }
    return 0;
}
