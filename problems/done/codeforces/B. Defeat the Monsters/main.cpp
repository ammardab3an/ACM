// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;
typedef long long int       lli;
typedef pair<int, int>      pii;
typedef pair<int, pii>      iii;
typedef pair<lli, lli>      pll;
typedef pair<lli, pll>      lll;
typedef vector<int>         vi;
typedef vector<lli>         vll;
typedef vector<pii>         vpii;

// Global Variables

const int MAX = 1e6;

bitset<MAX + 10> bs;
vi primes;

void primesVec(lli sieveSz)
{
    bs.reset(); bs.flip();
    bs.set(0, false); bs.set(1, false);

    sieveSz++;

    for(lli i = 2; i <= sieveSz; i++) if(bs.test(i))
    {
        for(lli j = i*i; j <= sieveSz; j += i)
            bs.set(j, false);
        primes.push_back(i);
    }

}

vector<int> primeFactors(int N)
{
    if(!N) return {0};

    vi factors;

    int PF_idx = 0,
        PF = primes[PF_idx];

    while(N != 1 && (PF*PF <= N))
    {
        while(!(N % PF))
        {
            N /= PF;
            factors.push_back(PF);
        }
        PF = primes[PF_idx++];
    }

    if(N != 1) factors.push_back(N);

    return factors;
}

void solve(){

    map<int, vi> mp;
    int n;
    cin >> n;
    while(n--){
        int x; cin >> x;
        map<int, int> _mp;
        for(auto i : primeFactors(x))
            _mp[i]++;
        for(auto p : _mp)
            mp[p.first].push_back(p.second);
    }
//    for(auto p : mp){
//        cout << p.first << ' ';
//        for(auto i : p.second)
//            cout << i << ' ' ;
//        cout << endl;
//    }
    int cnt = 0;
    for(auto p : mp){
        cnt += ceil(p.second.size() / 3.0);
    }

    cout << cnt << endl;
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; if(true) cin >> t;

    primesVec(MAX);

	while(t--){
		solve();
	}
}
