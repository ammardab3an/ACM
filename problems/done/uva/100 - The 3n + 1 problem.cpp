#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    int I, J;
    while(cin >> I >> J)
    {
        int i = I, j = J;
        if(I > J)
            swap(i, j);

        int mx = INT_MIN;
        for(int k = i; k <= j; k++)
        {
            int nm = 1, n = k;
            while(n > 1)
            {
                nm++;
                if(n % 2)
                    n = 3*n +1;
                else
                    n /= 2;
            }
            mx = max(mx, nm);
        }
        printf("%d %d %d\n", I, J, mx);
    }
    return 0;
}
