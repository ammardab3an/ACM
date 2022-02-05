#include<bits/stdc++.h>

using namespace std;

// declarations
#define inf 1000000007
#define LL  long long
int ans[1000100][2][2];
string s;
int len;

// the idea is to generate every possible grid which does match with the input one.

// index is the index of the current position.
// pre = 1 if the previous position is a mine else 0 .
// now = 1 if we want to put a mine in current position else 0 .

int dfs(int index, bool pre, bool now)
{
    if(index == len)
        return now == 0;

    if(ans[index][pre][now] != -1)
        return ans[index][pre][now];

    // if now = 1 then s[index] should be a mine or a question mark
    // if now = 1 then s[index] shouldn't be a number
    if (now)
    {
        if(s[index] != '*' && s[index] != '?')
            return 0;
    }
    // if now = 0 then s[index] should be a number or a question mark
    // if now = 0 then s[index] shouldn't be a mine
    else
    {
        if(s[index] == '*')
            return 0;
    }


    int total = 0;
    // pre + next is the sum of neighbors mines
    for(int next = 0; next <= 1; next++)
    {
        switch (s[index])
        {
        case '0':
            if((pre+next) != 0)
                continue; break;

        case '1':
            if((pre+next) != 1)
                continue; break;

        case '2':
            if((pre+next) != 2)
                continue; break;
        }

        total = ( total + dfs(index+1, now, next) ) % inf;
    }
    return ans[index][pre][now] = total;
}
int main()
{
    cin >> s;
    len = s.size();

    memset(ans, -1, sizeof ans);

    cout << (dfs(0,0,0) + dfs(0,0,1)) % inf << endl;
    return 0;
}
