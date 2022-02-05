#include<bits/stdc++.h>

using namespace std;

vector<int> primeVector = {1};
void fillPrimeVector()
{
    bitset<10010> bs;
    bs.reset(); bs.flip();
    bs.set(0, false); bs.set(1, false);

    int sieveSz = 1010;

    for(long long i = 2; i <= sieveSz; i++) if(bs.test(i))
    {
        primeVector.push_back(i);
        for(long long j = i*i; j <= sieveSz; j += i)
            bs.set(j, false);
    }
}

int main()
{
    fillPrimeVector();
    int N, C;
    while(cin >> N >> C)
    {
        vector<int>::iterator r_idx = upper_bound(primeVector.begin(), primeVector.end(), N);
        vector<int> newPrimeVec(primeVector.begin(), r_idx);
        int sz = newPrimeVec.size();

        printf("%d %d: ", N, C);

        C = (sz%2) ? C*2 -1 : C*2;
        int b = (sz > C) ? (sz-C)/2 : 0;
        int bc = min(b+C, sz);
        for(int i =  b; i < bc; i++)
            cout << newPrimeVec[i] << ((i != bc-1) ? " " : "");
        cout << endl << endl;
    }
    return 0;
}
