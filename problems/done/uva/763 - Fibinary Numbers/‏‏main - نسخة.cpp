// this code could work if fibVecSz < 90

#include<bits/stdc++.h>

using namespace std;

vector<long long> fibVec;
int fibVecSz;
long long mem[110];

long long fib(int i)
{
    return (mem[i] != -1) ? mem[i] : (mem[i] = (fib(i-1) + fib(i-2)));
}
void fillFibVec()
{
    for(int i = 2; i < 90; i++)
        fibVec.push_back(fib(i));
    fibVecSz = fibVec.size();
}
long long fibToInt(string a)
{
    long long Int = 0;
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++)
        if(a[i] == '1')
            Int += fibVec[i];
    return Int;
}
string intToFib(long long Int)
{
    string Fib = "";
    bool b = false;
    for(int i = fibVecSz -1; i >= 0; i--)
    {
        if(Int >= fibVec[i])
        {
            Int -= fibVec[i];
            Fib.push_back('1');
            b = true;
        }
        else if(b)
            Fib.push_back('0');
    }
    return Fib;
}
int main()
{
    freopen("D:\\input.txt", "r", stdin);
    freopen("D:\\output.txt", "w", stdout);

    memset(mem, -1, sizeof mem);
    mem[0] = 0; mem[1] = 1;
    fillFibVec();

    string a1, a2;
    bool b = false;
    while(cin >> a1 >> a2)
    {
        if(b) cout << endl;
        cout << intToFib(fibToInt(a1) + fibToInt(a2)) << endl;
        b = true;
    }

    return 0;
}
