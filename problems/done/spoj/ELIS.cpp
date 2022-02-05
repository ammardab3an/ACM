#include <bits/stdc++.h>

using namespace std;

int mem[10], arr[10], N;
int re(int pos)
{
    if(mem[pos] != -1)
        return mem[pos];

    int mx = 0;
    for(int i = pos + 1; i < N; i++)
        if(arr[i] > arr[pos])
            mx = max(mx, 1 + re(i));

    return mem[pos] = mx;
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    memset(mem, -1, sizeof mem);

    int mx = 0;
    for(int i = 0; i < N; i++)
        mx = max(mx, 1 + re(i));

    cout << mx;
    return 0;
}
