#include<bits/stdc++.h>

using namespace std;

vector<int> primeVec;
#define MAX_SZ 32000 // (1e9) ** 0.5 = 31622
void fillPrimeVec()
{
    bool bs[MAX_SZ];
    memset(bs, true, sizeof bs);
    bs[0] = bs[1] = false;

    for(long long i = 2; i < MAX_SZ; i++) if(bs[i])
    {
        for(long long j = i*i; j < MAX_SZ; j += i)
            bs[j] = false;
        primeVec.push_back(i);
    }

}
vector<int> primeFactors(int N)
{
    if(!N) return {0};
    vector<int> factors;
    int PF_idx = 0,
        PF = primeVec[PF_idx];
    while(N != 1 && (PF*PF <= N))
    {
        while(!(N % PF))
        {
            N /= PF;
            factors.push_back(PF);
        }
        PF = primeVec[PF_idx++];
    }
    if(N != 1) factors.push_back(N);
    return factors;
}

int main()
{
    fillPrimeVec();
    for(int i; (cin >> i) && (i);)
    {
        vector<int> i_factors = primeFactors(i);
        vector<int>::iterator new_end = unique(i_factors.begin(), i_factors.end());
        int result = i;
        for(vector<int>::iterator j = i_factors.begin(); j != new_end; j++)
            result = result - result / *j;
        cout << result << endl;
    }
    return 0;
}
