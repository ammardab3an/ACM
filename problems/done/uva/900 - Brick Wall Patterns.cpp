#include<bits/stdc++.h>

using namespace std;

long long mem[55];
long long fabonacci(int len)
{
    return (mem[len] != -1) ? mem[len] : (mem[len] = (fabonacci(len -1) + fabonacci(len -2)));
}
int main()
{
    memset(mem, -1, sizeof mem);
    mem[0] = 0; mem[1] = 1;
    for(int i; cin >> i && i;)
        cout << fabonacci(i+1) << endl;
    return 0;
}
