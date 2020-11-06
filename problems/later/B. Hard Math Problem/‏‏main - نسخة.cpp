#include<bits/stdc++.h>

using namespace std;

#define MAX_SZ 10000010
vector<int> primeVec;
bool bs[MAX_SZ];


void fillPrimeVec()
{
    memset(bs, true, sizeof bs);
    bs[0] = bs[1] = false;

    for(long long i = 2; i < MAX_SZ; i++) if(bs[i])
    {
        for(long long j = i*i; j < MAX_SZ; j += i)
            bs[j] = false;
        primeVec.push_back(i);
    }

}
bool isPrime(long long N)
{
    if(N < MAX_SZ)
        return bs[N];
    for(int i = 0; i < primeVec.size(); i++) if(N % primeVec[i] == 0) return false;
    return true;
}
int main()
{
    fillPrimeVec();
    int T, N, pMx = primeVec.back();
    vector<int>::iterator primeVecBegin = primeVec.begin(), primeVecEnd = primeVec.end();
    map<int, pair<long long, long long> > mem;
    for(cin >> T;T;T--)
    {
        cin >> N;
        long long sum_a = 0, sum_b = 1;
        long long a, b, gcd;
        for(int i = N; i > 1; i--)
        {
            if(mem.count(i))
            {
                a = mem[i].first;
                b = mem[i].second;
            }
            else
            {
                if(i < pMx)
                {
                    a = primeVec[lower_bound(primeVecBegin, primeVecEnd, i) - primeVecBegin];
                    b = primeVec[upper_bound(primeVecBegin, primeVecEnd, i) - primeVecBegin];
                }
                else
                {
                    for(long long i = N; true; i--)
                        if(isPrime(i)){
                            a = i; break;}
                    for(long long i = N+1; true; i++)
                        if(isPrime(i)){
                            b = i; break;}
                }
            }
            sum_a = sum_a * a * b + sum_b;
            sum_b = sum_b * a * b;
        }
        gcd = __gcd(sum_a, sum_b);
        sum_a /= gcd;
        sum_b /= gcd;

        mem[N] = {sum_a, sum_b};
        printf("%llu/%llu\n", sum_a, sum_b);
    }
    return 0;
}
