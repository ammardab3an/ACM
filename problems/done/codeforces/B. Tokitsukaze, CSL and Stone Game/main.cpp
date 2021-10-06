#include<bits/stdc++.h>

using namespace std;

int n;
int arr[100010];
map<int, int> mp;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] ++;
    }

    long long mv = 0;
    sort(arr, arr + n);

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < i)
            break;
        mv += arr[i] - i;
    }

    int x, cnt = 0;
    for(auto p : mp)
    {
        if(p.second >= 3)
        {
            cout << "cslnb";
            return 0;
        }
        if(p.second >= 2)
        {
            cnt ++;
            x = p.first;
        }
    }

    if((cnt > 1) || (cnt == 1 && mp[x-1] == 1))
    {
        cout << "cslnb";
        return 0;
    }

    cout << ((mv % 2) ? "sjfnb" : "cslnb");
}
