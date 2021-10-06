// By AmmarDab3an - Aleppo University.

#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char str_1[N];
char str_2[N];
int lcs[N][N];
int cnt[N][N];

int main()
{
    int k;
    while(cin >> k && k)
    {
        cin >> str_1 >> str_2;

        int  len_1 = strlen(str_1);
        int  len_2 = strlen(str_2);

        cnt[0][0] = 0;

        for(int i = 0; i <= len_1; i++)
        for(int j = 0; j <= len_2; j++)
        {
            if(!i || !j)
            {
                lcs[i][j] = 0;
                continue;
            }

            lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);

            if(str_1[i-1] == str_2[j-1])
                cnt[i][j] = cnt[i-1][j-1] +1;
            else
                cnt[i][j] = 0;

            if(cnt[i][j] >= k)
                for(int z = k; z <= cnt[i][j]; z++)
                    lcs[i][j] = max(lcs[i][j], lcs[i-z][j-z] +z);
        }
        cout << lcs[len_1][len_2] << endl;
    }
}
