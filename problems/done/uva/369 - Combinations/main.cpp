#include<bits/stdc++.h>

using namespace std;

vector<int> primeVec;
void fillPrimeVec()
{
    bitset<1010> bs;
    bs.reset(); bs.flip();
    bs.set(0, false); bs.set(1, false);

    vector<int> primes;
    int sieveSz = 1000;

    for(long long i = 2; i <= sieveSz; i++) if(bs.test(i))
    {
        primeVec.push_back(i);
        for(long long j = i*i; j <= sieveSz; j += i)
            bs.set(j, false);
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
pair< vector<int>, vector<int> >  shortCut(vector<int> vec1, vector<int> vec2)
{
    vector<int> vec11, vec22;

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    int i, j;
    for(i = 0, j = 0; (i < vec1.size()) && (j < vec2.size());)
    {
        if(vec1[i] == vec2[j])
        {
            i++; j++;
        }
        else if(vec1[i] > vec2[j])
        {
            vec22.push_back(vec2[j]);
            j++;
        }
        else if(vec1[i] < vec2[j])
        {
            vec11.push_back(vec1[i]);
            i++;
        }
    }
    for(; i < vec1.size(); i++)
        vec11.push_back(vec1[i]);
    for(; j < vec2.size(); j++)
        vec22.push_back(vec2[j]);

    return {vec11, vec22};
}
int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    fillPrimeVec();
    for(int N, M; cin >> N >> M && N;)
    {
        vector<int> nu, de, iFac;
        for(int i = 0; i < M; i++)
        {
            iFac = primeFactors(N-i);
            nu.insert(nu.end(), iFac.begin(), iFac.end());
            iFac = primeFactors(M-i);
            de.insert(de.end(), iFac.begin(), iFac.end());
        }
        pair< vector<int>, vector<int> > pvv = shortCut(nu, de);
                long long _nu = 1, _de = 1;
        for(auto i : pvv.first)
            _nu *= i;
        for(auto i : pvv.second)
            _de *= i;
        printf("%d things taken %d at a time is %llu exactly.\n", N, M, (_nu/_de));
    }
    return 0;
}
