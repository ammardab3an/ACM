#include <bits/stdc++.h>

using namespace std;

int mem[100][200], arr[100], N;
int re(int pos, int last)
{
    if(mem[pos][last] != -1)
        return mem[pos][last];
    if(pos == N) return 0;

    int path_1 = re(pos+1, last);

    int path_2 = INT_MIN;
    if(arr[pos] > last)
        path_2 = 1 + re(pos+1, arr[pos]);

    return mem[pos][last] = max(path_1, path_2);
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    memset(mem, -1, sizeof mem);
    cout << max(1+ re(1, arr[0]), re(1, INT_MIN));
    return 0;
}
