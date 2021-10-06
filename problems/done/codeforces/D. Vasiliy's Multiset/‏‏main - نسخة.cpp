#include<bits/stdc++.h>

using namespace std;

struct trieNode
{
    int cnt;
    trieNode * nxt[2];

    trieNode()
    {
        cnt    = 1;
        nxt[0] = nullptr;
        nxt[1] = nullptr;
    }
};

void trieInsert(trieNode * root, int value)
{
    trieNode * current = root;

    for(int i = 31; i >= 0; i--)
    {
        bool b = value & (1 << i);

        trieNode * node = current -> nxt[b];
        if(!node)
        {
            node = new trieNode();
            current -> nxt[b] = node;
        }
        else
            node -> cnt++;

        current = node;
    }
}

void trieDelete(trieNode * root, int value)
{
    trieNode * current = root;
    for(int i = 31; i >= 0; i--)
    {
        bool b = value & (1 << i);

        current = current -> nxt[b];

        current -> cnt--;
    }
}

int findMxXor(trieNode * root, int num)
{
    int ans = 0;
    trieNode * current = root;

    for(int i = 31; i >= 0; i--)
    {
        bool b = num & (1 << i);
        trieNode * node_1 = current -> nxt[!b];
        trieNode * node_2 = current -> nxt[ b];

        if(node_1 && (node_1 -> cnt) > 0)
        {
            ans ^= !b << i;
            current = node_1;
        }
        else
        {
            ans ^=  b << i;
            current = node_2;
        }
    }
    return ans;
}
int main()
{
    trieNode * root = new trieNode();
    trieInsert(root, 0);

    int k;
    for(cin >> k; k--;)
    {
        char c; int num;
        cin >> c >> num;
        switch(c)
        {
            case '+':
                trieInsert(root, num); break;
            case '-':
                trieDelete(root, num); break;
            case '?':
                cout << (num ^ findMxXor(root, num)) << endl;
        }
    }
}
