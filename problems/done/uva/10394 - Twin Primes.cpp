#include<bits/stdc++.h>

using namespace std;

bool isPrime[18409202];
void fillPrimeArr()
{
    memset(isPrime, true, sizeof isPrime);
    for(long long i = 3; i < 100000; i += 2)
        if (isPrime[i])
            for(long long j = i * i; j < 18409202; j += i)
                isPrime[j] = false;
}

int main()
{
//    ifstream myfile ("D:\\Output.txt");
//    myfile.is_open();
//    #define cin myfile

    string str;
    int arr[101010], n, mx = 0;
    for(n = 0; getline(cin, str); n++)
        mx = max(mx, arr[n] = stoi(str));

    fillPrimeArr();

    int outArr[101010];
    for(int k = 1, i = 3; k <= mx; i += 2)
        if (isPrime[i] && isPrime[i+2])
            outArr[k++] = i;


    for (int i = 0; i < n; i++)
    {
        int j = outArr[arr[i]];
        printf("(%d, %d)\n", j, j+2);
    }
    return 0;
}
