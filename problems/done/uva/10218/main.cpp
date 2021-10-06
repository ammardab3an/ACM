#include<bits/stdc++.h>

using namespace std;

//declarations
double M, W, C;
double p, q;
double c_mem[1000][1000];
double f_mem[1000];

double f(int n)
{
    if(!n) return 1;

    if (f_mem[n]) return f_mem[n];

    double re = 1;
    for (int i = n; i; i--)
        re *= i;

    return f_mem[n] = re;
}
double choose(int n, int k)
{
    if (!k || !n || (k == n)) return 1;

    if (c_mem[n][k]) return c_mem[n][k];

    double re = 1;
    for (int i = 0; i < k; i++)
        re *= n-i;

    return c_mem[n][k] = c_mem[n][n-k] = re / f(k);
}
double binomial(double n, double k)
{
    return choose(n, k) * pow(p, k) * pow(q, n-k);
}
double go()
{
    double  re = 0;
    for(int i = 0; i <= C; i += 2)
        re += binomial(C, i);
    return re;
}
int main()
{
    while (true)
    {
        cin >> M >> W >> C ;
        if (!M && !W) break;

        p = M/(M+W);
        q = 1-p;

        memset(c_mem, 0, sizeof c_mem);
        memset(f_mem, 0, sizeof f_mem);

        cout << fixed << setprecision(7) << go() << endl;
    }
    return 0;
}
