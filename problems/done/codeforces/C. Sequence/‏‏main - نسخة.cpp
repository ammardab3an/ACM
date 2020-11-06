#include<bits/stdc++.h>

using namespace std;

#define lli long long int

int n;
int arrA[5050];
int arrB[5050]; // arrB = sorted(arrA)
lli  mem[5050];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arrA[i];

    copy(arrA, arrA+n, arrB);
    sort(arrB, arrB+n);

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        mem[j] += abs(arrA[i] - arrB[j]);
        if(j)
            mem[j] = min(mem[j-1], mem[j]);
    }

    cout << mem[n-1];
}
