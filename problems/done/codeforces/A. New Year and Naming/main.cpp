// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string arr_1[22];
    string arr_2[22];

    for(int i = 0; i < n; i++)
        cin >> arr_1[i];
    for(int i = 0; i < m; i++)
        cin >> arr_2[i];

    int t;
    for(cin >> t; t--;)
    {
        int k; cin >> k; k--;
        cout << arr_1[k%n] << arr_2[k%m] << endl;
    }
}
