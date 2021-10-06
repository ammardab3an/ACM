// Problem: B. Pleasant Pairs
// Contest: Codeforces - Codeforces Round #728 (Div. 2)
// URL: https://codeforces.com/contest/1541/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/* Zohir Boshi Template */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define s(a , n) sort (a , a + n)
#define f(n) for(int i=0 ; i < n ; i++)

#define msi map<string, int>
#define mci map<char, int>

#define vs vector <string>
#define vi vector <int>

#define ps pair <string , string>
#define pc pair <char , char>
#define pi pair <int , int>

#define vpi vector <pair <int,int>>
#define vpci vector <pair <int , char>>

#define sor1(v) sort(v.begin(), v.end())
#define sor2(v) sort(v.rbegin(), v.rend())

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define cif(n) cout << (n ? "YES" : "NO") << endl
int arr[100005] = {0};
void solve()
{
    int n ,a;
    cin >> n;
    vpi arr; // (num , index)
    int co = 0;
    for (int j = 0 ; j < n ; j++)
    {
        scanf("%d", &a);
        arr.push_back(make_pair(a , j + 1));
    }
    sort (arr.begin() , arr.end());
    int maxindex = (2 * n) + 1;
    for (int j = 0 ; j < n ; j++)
    {
        for (int k = j + 1 ; k <= n - 1 ; k++)
        {
            ll x = 1ll * arr[j].first * arr[k].first;
            if (x > maxindex)
            {
                break;
            }
            else
            {
                if ((1ll * arr[j].first * arr[k].first) == (arr[j].second + arr[k].second))
                    co++;
            }
        }
        if (arr[j].first > maxindex)
        {
            break;
        }
    }
    cout << co << endl;
}

int main()
{
//    start of input and output for the file
    #ifndef ONLINE_JUDGE                    //file start
    freopen("input.txt","r",stdin);
    #endif                                  //file end
//    end of input and output for the file

    int t;
    cin >> t;
    while (t--)
        solve();
}