#include "bits/stdc++.h"

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int h[200],n;
int a[200][5];

int dp(int pos, int last)
{
    if (pos == n) return 0;

     if (a[pos][last+1] != -1) return a[pos][last+1];//check

    int A = 0, B = 0, C = dp(pos+1, -1);

    if(last !=2 && h[pos]==3) A =dp(pos+1,2) + 1;
    if(last !=2 && h[pos]==2) A =dp(pos+1,2) + 1;
    if(last !=1 && h[pos]==1) B =dp(pos+1,1) + 1;
    if(last !=1 && h[pos]==3) B =dp(pos+1,1) + 1;

    return a[pos][last+1] = max(A,max(B, C));
}
int main()
{
    fast

    cin >> n;

    for (int i = 0; i < n; i++) cin >> h[i];

    memset(a, -1, sizeof(a));

    cout << n - dp(0, -1)<<"\n" ;
}
