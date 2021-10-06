// AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

const int MAX = 4000040;

int cnt = 1;
int trie[MAX][2];

void trieInsert(int num)
{
    int cur = 0;
    for(int i = 30; i >= 0; i--)
    {
        bool b = num & (1 << i);
        if(!trie[cur][b])
            trie[cur][b] = cnt++;
        cur = trie[cur][b];
    }
}

int go(int num, int d)
{
    if(trie[num][0] && trie[num][1])
        return min(go(trie[num][0], d-1), go(trie[num][1], d-1)) + (1 << d);

    for(bool b : {0, 1}) if(trie[num][b])
        return go(trie[num][b], d-1);

    return 0;
}

int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        trieInsert(num);
    }
    cout << go(0, 30);
}
