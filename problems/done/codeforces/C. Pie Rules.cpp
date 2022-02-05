#include<bits/stdc++.h>

using namespace std;

int n;
int arr[50];
int mem[50];

int go(int pos)
{
    if(pos == n)
        return 0;

    if(mem[pos] != -1)
        return mem[pos];

    int fAns = + arr[pos] - go(pos+1);
    int sAns = - arr[pos] + go(pos+1);

    return mem[pos] = max(fAns, sAns);
}
int main()
{
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    memset(mem, -1, sizeof mem);

    sum -= go(0);
    sum /= 2;

    cout << sum << ' ' << go(0) + sum;
}
