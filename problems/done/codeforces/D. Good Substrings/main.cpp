#include<bits/stdc++.h>

using namespace std;

bool good[200];
int k;

struct trieNode
{
 	map<char, trieNode*> children;
};
void trieInsert(trieNode *root, string word)
{
 	trieNode *current = root;
 	for(auto ch : word)
 	{
 		trieNode *node = current->children[ch];
 		if(!node)
 		{
 			node = new trieNode();
 			current->children[ch] = node;
 		}
 		current = node;
 	}
}
int trieCount(trieNode *root)
{
    int cnt = 1;
    for(auto to : root->children)
        cnt += trieCount(to.second);
    return cnt;
}

bool goodToGo(string str)
{
    int cnt = 0;
    for(auto ch : str) if(!good[ch])
    {
        if(cnt == k) return false;
        cnt++;
    }
    return true;
}
int main()
{
    string str, arr, subStr;

    cin >> str >> arr;
    for(int i = 0; i < 26; i++)
        good[i+97] = arr[i]-'0';
    cin >> k;

    trieNode *root = new trieNode;

    int sz = str.size();
    for(int i = 0; i < sz; i++)
    {
        int l = 1, r = sz-i, m, mxd = 0;
        while(l <= r)
        {
            m = (r+l)/2;
            if(goodToGo(str.substr(i,m)))
            {
                mxd = m;
                l = m+1;
            }
            else
                r = m-1;
        }
        trieInsert(root, str.substr(i, mxd));
    }

    cout << trieCount(root)-1;

    return 0;
}
