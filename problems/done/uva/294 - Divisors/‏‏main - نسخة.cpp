#include<bits/stdc++.h>

using namespace std;


vector<int> primesVec(long long sieveSz)
{
    bitset<1000010> bs;
    bs.reset(); bs.flip();
    bs.set(0, false); bs.set(1, false);

    vector<int> primes;
    sieveSz++;

    for(long long i = 2; i <= sieveSz; i++) if(bs.test(i))
    {
        for(long long j = i*i; j <= sieveSz; j += i)
            bs.set(j, false);
        primes.push_back(i);
    }
    return primes;
}

vector<int> primes = primesVec(1000000);
vector< pair<int,int> > primeFactors(int N)
{
    if(!N) return {{0, 0}};
    vector< pair<int,int> > factors;
    int PF_idx = 0,
        PF = primes[PF_idx];
    while(N != 1 && (PF*PF <= N))
    {
        for(bool b = false; !(N % PF); b = true)
        {
            N /= PF;
            if(b){factors.back().second++; continue;};
            factors.push_back({PF, 1});
        }
        PF = primes[PF_idx++];
    }
    if(N != 1) factors.push_back({N, 1});
    return factors;
}

int main()
{
    int T;
    for(cin >> T;T;T--)
    {
        int lower, upper;
        cin >> lower >> upper;

        int P, D;
        P = D = 0;

        for(int p = lower; p <= upper; p++)
        {
            vector< pair<int,int> > ppf = primeFactors(p);
            int d = 1;
            for(auto pii:ppf)
                d *= pii.second +1;

            if(d > D)
            {
                P = p;
                D = d;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", lower, upper, P, D);
    }
    return 0;
}
