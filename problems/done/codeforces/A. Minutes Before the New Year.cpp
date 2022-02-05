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
    int h, m;
    cin >> h >> m;

    cout << (23-h) * 60 + (60-m) << endl;
}
int main()
{
    int t;
    for(cin >> t; t--;)
    {
        go();
    }
}
