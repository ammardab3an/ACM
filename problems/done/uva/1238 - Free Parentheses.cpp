#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;

vector<int> N;
vector<char> S;
set<int> V;
bool dp[30 + 5][30 + 5][6000 + 5];

void search(int idx, int nLeftParen, int value)
{
    if (idx == N.size())
    {
        V.insert(value);
        return;
    }
    if (dp[idx][nLeftParen][value + idx * MAX])
        return;

    // Put a left parenthesis.
    // It's necessary to use S[] for the case "- 0 + x".
    // nLeftParen in the number of leftParen.
    // remember -(-x)) = x, => nLeftParen % 2 == 0.
    // take it
    if (S[idx] == '-')
        search(idx + 1,
               nLeftParen + 1,
               value + ((nLeftParen % 2 == 0) ? N[idx] : -N[idx]));

    // Put 0, 1 .. up to nParen right parentheses.
    // leave it
    for (int i = 0; i <= nLeftParen; ++i)
        search(idx + 1,
               nLeftParen - i,
               value + ((nLeftParen % 2 == 0) ? N[idx] : -N[idx]));

    // value can be negative int => (+ idx * MAX).
    dp[idx][nLeftParen][value + idx * MAX] = true;
}

int solve()
{
    memset(dp, false, sizeof(dp));
    V.clear();
    search(0, 0, 0);
    return V.size();
}

int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    string inputStr;
    while (getline(cin, inputStr))
    {
        stringstream strStr(inputStr);
        char sign; int num;
        strStr >> num;
        N = {num}; S = {'+'};
        while (strStr >> sign >> num)
        {
            N.push_back((sign == '+') ? num : -num);
            S.push_back(sign);
        }
        cout << solve() << endl;
    }
    return 0;
}
