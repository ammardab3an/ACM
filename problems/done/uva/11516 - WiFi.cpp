#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> houses;

bool possible(int mxDis)
{
    int lastRouter = houses[0] + mxDis;
    int usedRouters = 1;
    for(int i = 1; i < m && usedRouters <= n; i++)
        if(houses[i] - lastRouter > mxDis)
        {
            lastRouter = houses[i] + mxDis;
            usedRouters++;
        }
    return usedRouters <= n;
}
int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.c", "w", stdout);

    int T;
    for(cin >> T;T;T--)
    {
        cin >> n >> m;
        houses.clear();
        for(int house, i = 0; i < m; i++)
        {
            cin >> house;
            houses.push_back(house*10);
        }
        sort(houses.begin(), houses.end());

        int mxDis;
        int l = 0, r = (houses[m-1] - houses[0])/2, m;
        while(l <= r)
        {
            m = (l+r)/2;
            if(possible(m))
            {
                mxDis = m;
                r = m-1;
            }
            else
                l = m+1;
        }
        cout << mxDis/10 << '.' << mxDis%10 << endl;
    }
    return 0;
}
