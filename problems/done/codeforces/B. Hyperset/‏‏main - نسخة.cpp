// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string arr[1500];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;

    for(int i =  0 ; i < n; i++)
    for(int j = i+1; j < n; j++)
    for(int k = j+1; k < n; k++)
    {
        bool b1, b2, b3, b4, b5, b = true;

        for(int l = 0; l < m; l++)
        {
            b1 = arr[i][l] == arr[j][l];
            b2 = arr[j][l] == arr[k][l];
            b3 = arr[i][l] == arr[k][l];

            b4 = b1 && b2;
            b5 = !b4 && !b3;

            if(!b4 && !b5)
            {
                b = false;
                break;
            }
        }

        ans += b;
    }

    cout << ans;
}
