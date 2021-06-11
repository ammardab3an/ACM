// Problem: G. Baby Ehab and a GCD Problem, Of Course
// Contest: Codeforces - ECPC 2019 Kickoff
// URL: https://codeforces.com/gym/102881/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e5+1;
ll a, b;
int main () {
        freopen("gcd.in", "r", stdin);

    int q;
    scanf("%d",&q);
    ll gcd = 0;
    while (q--){
        scanf("%I64d %I64d",&a,&b);
        if (!gcd) {
            gcd = b;
        }
        else {
            if (b - a > 0) gcd = 1;
            else gcd = __gcd(gcd, a);
        }
        printf("%I64d\n",gcd);
    }
}