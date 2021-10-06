#include<bits/stdc++.h>

using namespace std;

#define lli long long

int n;
int arr[5000];
lli mem[5000][5000];

lli go(int pos, int lastPos)
{
    if(pos == n)
        return 0;

    lli & ans = mem[pos][lastPos];
    if(ans != -1)
        return ans;

    if(arr[pos] == arr[pos-1])
        return ans = go(pos+1, pos);

    lli dif = abs(arr[pos] - arr[pos-1]);

    lli fAns = dif + go(pos+1, pos-1);

    lli sAns = go(pos+1, pos);
    if(arr[lastPos] > arr[pos])
        sAns += pos * dif;

    return ans = min(fAns, sAns);
}

int main()
{
    cin >> n;
    for(int num, i = 0; i < n; i++)
        cin >> arr[i];

    memset(mem, -1, sizeof mem);

    cout << (n ? go(1, 0) : 0);
}
