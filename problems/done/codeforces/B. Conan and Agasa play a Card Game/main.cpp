#include<bits/stdc++.h>

using namespace std;

int arr[100010];
int fre[100010];

int main()

{
    int n; cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        fre[arr[i]]++;
    }

    for(int i = 0; i < n; i++) if(fre[arr[i]] % 2)
    {
        cout << "Conan";
        return 0;
    }

    cout << "Agasa";
}
