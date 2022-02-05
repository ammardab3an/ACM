#include<bits/stdc++.h>

using namespace std;

#define maxBits 22
#define maxMask (1 << maxBits)
#define maxN 1000000

int dp[maxMask], a[maxN];

int main() {
    memset(dp, -1, sizeof dp);

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        dp[a[i]] = a[i];
    }

    for(int i = 0; i < maxMask; i++)
        for(int j = 0; j < maxBits; j++)
            if(dp[i] != -1)
                dp[i | 1 << j] = dp[i];

    for(int i = 0; i < n; i++)
        printf("%d ", dp[~a[i] & maxMask-1]);

	return 0;
}
