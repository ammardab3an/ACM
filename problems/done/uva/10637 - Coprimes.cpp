#include<bits/stdc++.h>

using namespace std;

bool GCD[101][101];
int a[30], sz;

void generate(int n, int m, int mn){
    if(n == sz)
    {
        if(m == 0)
        {
            for(int i = 0; i < sz-1; i++)
                printf("%d ", a[i]);
            printf("%d\n", a[sz-1]);
        }
        return;
    }

    for(int i = mn; i *(sz-n) <= m; i++)
    {
        for(int j = 0; j < n; j++)
            if(!GCD[a[j]][i])
                goto endLoop;

        a[n] = i;
        generate(n+1, m-i, i);
        endLoop:;
    }
}
void fill_GCD_arr()
{
    memset(GCD, false, sizeof GCD);
    for(int i = 1; i <= 100; i++)
        for(int j = i; j <= 100; j++)
            if(__gcd(i,j) == 1)
                GCD[i][j] = true;
}
int main(){
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    fill_GCD_arr();

    int T, S;
    scanf("%d", &T);

    for(int t = 1; T--; t++)
    {
        scanf("%d %d", &S, &sz);
        printf("Case %d:\n", t);
        generate(0, S, 1);
    }

    return 0;
}
