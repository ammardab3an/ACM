// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string arr[1500];
    set<string> st;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st.insert(arr[i]);
    }

    int ans = 0;

    for(int i =  0 ; i < n; i++)
    for(int j = i+1; j < n; j++)
    {
        string s = "";
        for(int k = 0; k < m; k++)
        {
            if(arr[i][k] == arr[j][k])
                s.push_back(arr[i][k]);
            else if(arr[i][k] != 'S' && arr[j][k] != 'S')
                s.push_back('S');
            else if(arr[i][k] != 'E' && arr[j][k] != 'E')
                s.push_back('E');
            else
                s.push_back('T');
        }

        if(st.count(s))
            ans++;
    }

    cout << ans/3;
}
