#include<bits/stdc++.h>

using namespace std;

int n;
int arr[100010];
int mem[100010][2];

char go(int pos, bool player)
{
    int & ans = mem[pos][player];

    if(ans != -1)
        return ans;

    for(int i : {1, -1})
    {
        for(int j = pos + i*arr[pos]; (0 <= j && j < n); j += i*arr[pos])
        {
            if(arr[j] > arr[pos])
            {
                if(go(j, !player) == ('A' + player))
                    return ans = ('A' + player);
            }
        }
    }

    return ans = ('A' + !player);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    memset(mem, -1, sizeof mem);

    for(int i = 0; i < n; i++)
        cout << go(i, 0);
}
