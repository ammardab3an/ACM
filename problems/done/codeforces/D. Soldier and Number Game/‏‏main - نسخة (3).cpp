
// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<lli, lli>      pll;
typedef pair<int, pii>      iii;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;

#define multiCases true
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define freopenI freopen("input.txt", "r", stdin)
#define freopenO freopen("output.txt", "w", stdout)

// Global Variables

const int MAX = 5e6 + 10;

vi primes;
int mem[MAX];
bitset<MAX> bs;

void fillPrimesVec()
{
    bs.reset(); bs.flip();
    bs.set(0, false); bs.set(1, false);

    int sieveSz = MAX - 1;
    for(lli i = 2; i <= sieveSz; i++) if(bs.test(i))
    {
        for(lli j = i*i; j <= sieveSz; j += i)
            bs.set(j, false);
        primes.push_back(i);
    }
}

void offline(){

    fillPrimesVec();

    for(int n = 2; n < MAX; n++){

        int fac = n;

        for(int i : primes){
            if(n % i == 0){
                fac = i;
                break;
            }
            if(i*i > n)
                break;
        }

        mem[n] = mem[ n / fac ] + 1;
    }

    for(int n = 2; n < MAX; n++)
        mem[n] += mem[n-1];
}

void solve(){

    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", mem[a] - mem[b]);
}

int main(){

    offline();

    int t; scanf("%d", &t); while(t--){
        solve();
    }
}
