//done
#include<bits/stdc++.h>

using namespace std;

int ln;
int a[222];
int mem[222][222][222];
int oo = 1e9;

int dp(int pos, int lastW, int lastB)
{
    if (pos == ln)
        return 0;

    if (mem[pos][lastW][lastB] != -1)
        return mem[pos][lastW][lastB];

    int path_1 = (a[pos] > a[lastB]) ? dp(pos+1, lastW, pos) : oo;
    int path_2 = (a[pos] < a[lastW]) ? dp(pos+1, pos, lastB) : oo;
    int path_3 = 1 + dp(pos+1, lastW, lastB);

    return mem[pos][lastW][lastB] = min(path_1, min(path_2,path_3));
}

int main()
{
    while (true)
    {
        cin >> ln;

        if (ln == -1)
            return 0;

        ln += 2;
        memset(mem, -1, sizeof mem);
        for (int i = 2; i < ln; i++)
            cin >> a[i];

        a[0] = +oo;
        a[1] = -oo;
        cout << dp(2, 0, 1) << endl;
    }

}
