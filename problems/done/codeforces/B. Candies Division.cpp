#include<bits/stdc++.h>

using namespace std;

#define lli long long int
#define pii pair<int, int>
#define iii pair<int, pii>
#define vi  vector<int>
#define vp  vector<pii>

//declarations



void go()
{
    lli n, k, sum;
    cin >> n >> k;
    sum += n/k;
    sum *= k;
    n -= sum;
    sum += min(n, k/2);
    cout << sum << endl;
}
int main()
{
    int t;
    for(cin >> t; t--;)
    {
        go();
    }
}
