#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[100000];
    int T, N;
    for(cin >> T;T && cin >> N; T--)
    {
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        for(int i = 0; i < N-1; i++)
            cout << arr[i] + arr[i+1] << ' ';
        cout << arr[N-1] << endl;
    }
    return 0;
}
