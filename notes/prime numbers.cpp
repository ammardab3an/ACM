
// Sieve of Eratosthenes
// generate prime numbers

#include<bits/stdc++.h>

using namespace std;

bitset<1000010> bs;
vector<int> primesVec(long long sieveSz)
{
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
vector<int> primeFactors(int N)
{
    if(!N) return {0};
    vector<int> primes = primesVec(N),
                factors;
    int PF_idx = 0,
        PF = primes[PF_idx];
    while(N != 1 && (PF*PF <= N))
    {
        while(!(N % PF))
        {
            N /= PF;
            factors.push_back(PF);
        }
        PF = primes[PF_idx++];
    }
    if(N != 1) factors.push_back(N);
    return factors;
}
int main()
{
    while(true)
    {
        int i; cin >> i;
        for(auto it:primeFactors(i))
            cout << it << endl;
    }
    for(auto it:primesVec(1000))
        cout << it << endl;
    return 0;
}

