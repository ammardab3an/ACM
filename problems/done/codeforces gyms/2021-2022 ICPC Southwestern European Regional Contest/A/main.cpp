#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        map<int,int> mp;
        int n, cnt = 0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int b,d;
            cin>>b>>d;

            if(mp[d])
            {
                mp[d] = max(mp[d] , b);
            }
            else
            {
                cnt++;
                mp[d] = b;
            }
        }

        if(cnt == 10)
        {
            int sum = 0;
            for(int i=1; i<=10; i++)
                sum += mp[i];
            cout<<sum;
        }
        else cout<<"MOREPROBLEMS";
        cout<<endl;

    }

    return 0;
}
