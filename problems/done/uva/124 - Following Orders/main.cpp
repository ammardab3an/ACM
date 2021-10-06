#include <bits/stdc++.h>

using namespace std;

//declaration
int n;
bool in[26];
bool vs[26];
bool mp[26][26];
char st[26];

void dfs(int idx)
{
    if(idx == n){
        cout << st << endl;
        return;
    }

    for(int i = 0; i < 26; i++) if(in[i] && !vs[i])
    {
        for(int j = 0; j < 26; j++)
            if(mp[i][j] && vs[j])
                return;

        vs[i] = true;
        st[idx] = i + 'a';
        dfs(idx +1);
        vs[i] = false;
    }
}

int main()
{
    string inputLine; bool first = true;
    while(getline(cin, inputLine))
    {
        if(!first)
            cout << endl;
        first = false;

        n = 0;
        memset(in, 0, sizeof in);
        memset(vs, 0, sizeof vs);
        memset(mp, 0, sizeof mp);
        memset(st, 0, sizeof st);

        for(auto c : inputLine)
            if(c != ' ')
                in[c - 'a'] = true, n++;

        getline(cin, inputLine);
        for(int i = 0; i < inputLine.length(); i += 4)
            mp[inputLine[i] - 'a'][inputLine[i+2] - 'a'] = true;

        dfs(0);
    }
}
