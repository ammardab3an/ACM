//done
//same as BORW
#include<bits/stdc++.h>

using namespace std;

int ln;
int a[101];
int mem[101][101][101];
int oo = 1e9;

int dp(int pos, int lastW, int lastB)
{
    if (mem[pos][lastW][lastB] != -1)
        return mem[pos][lastW][lastB];
    if (pos == ln)
        return 0;

    int path_1 = oo;
    if (a[pos] > a[lastB])
        path_1 = dp(pos+1, lastW, pos);


    int path_2 = oo;
    if (a[pos] < a[lastW])
        path_2 = dp(pos+1, pos, lastB);


    int path_3 = 1+ dp(pos+1, lastW, lastB);
    return mem[pos][lastW][lastB] = min(path_1, min(path_2,path_3));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    while(k--)
    {
        memset(mem, -1, sizeof mem);

        cin >> ln;
        ln += 2;
        for (int i = 2; i < ln; i++)
            cin >> a[i];

        a[0] = oo;
        a[1] = -oo;
        cout << ln -2 -dp(2,0,1) << endl;
    }
    return 0;
}
