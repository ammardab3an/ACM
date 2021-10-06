#include<bits/stdc++.h>

using namespace std;

#define LLI_MAX 9e18

int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
auto dp(int i, int j)
{
    if(j == 1)
        return pow(2, i-1);

    auto mn = LLI_MAX;
    if(i >= j) for(int k = 1; k < i; k++)
        if(i % (k+1) == 0){
            auto _mn = dp(i/(k+1), j-1) * pow(prime[j-1],k);
            mn = min(mn, _mn);}
    return mn;
}
int main()
{
    int i;
    cin >> i;

    auto mn = LLI_MAX;
    for(int j = 1; j <= 10; j++)
        mn = min(mn, dp(i, j));

    cout << (long long int)mn;
    return 0;
}
