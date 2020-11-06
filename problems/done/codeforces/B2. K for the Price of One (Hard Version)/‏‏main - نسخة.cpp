// i couldn't use top down method because p can be up to 2e9
// remember to read the input ranges at first you f**king idiot

#include<bits/stdc++.h>

using namespace std;

int n, p, k;
int arr[200020];

int go(int pos, int money)
{
    if(pos == n || !money)
        return 0;

    int fAns = 0 + go(pos +1, money);

    if(arr[pos] > money)
        return go(pos +1, money);

    int sAns = 1 + go(pos +1, money - arr[pos]);

    int tAns = 0;
    if(pos + k <= n)
        tAns = k + go(pos +k, money - arr[pos]);

    return max(fAns, max(sAns, tAns));
}
int main()
{
    int t;
    for(cin >> t; t--;)
    {
        cin >> n >> p >> k;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr+n, greater<int>());

        cout << go(0, p) << endl;
    }
}
