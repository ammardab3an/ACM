// Problem: Ada and Jobs
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/ADAJOBS/
// Memory Limit: 1536 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
//priority_queue next_permutation
#define ll long long
#define flot(n) cout << setprecision(n) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
#define all(a) a.begin() , a.end()
#define allr(a) a.rbegin() , a.rend()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair<pii,int>
#define plll pair<ll,pll>
#define R return
#define B break
#define C continue
#define SET(n , i) memset(n , i , sizeof(n))
#define SD ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i , n) for(int i = 0 ; i < n ; i++)
#define repn(i , j , n) for(int i = j ; i < n ; i++)
#define repr(i,n,j) for(int i=n;i>=j;i--)
#define positive(x) (x%mod+mod)%mod
#define YES(f)cout<<(f?"YES":"NO")<<endl
#define F first
#define S second
#define endl '\n'
using namespace std;
void MAX(int32_t &x,int32_t y){x=max(x,y);}
void MAX(ll &x,ll y){x=max(x,y);}
void MIN(int32_t &x,int32_t y){x=min(x,y);}
void MIN(ll &x,ll y){x=min(x,y);}
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6+7;
const int mod = 1e9+7;
ll Mul(ll x,ll y){R((x%mod)*(y%mod))%mod;}
ll Add(ll x,ll y){R((x%mod)+(y%mod)+2ll*mod)%mod;}
int n,m,q;
string s,x[N];
int trie[N][26],lps[N];
int out[N];
int state = 1;
void build() {
    memset(trie , -1 , sizeof trie);
    memset(lps , -1 , sizeof lps);
    SET(out,INF);
}
void insert(string s,int idx) {
    int cur_state = 0 , sz = s.size();
    for(int j = 0 ; j < sz ; j++) {
        int ch = s[j] - 'a';
        if(trie[cur_state][ch] == -1) 
            trie[cur_state][ch] = state++;
        cur_state = trie[cur_state][ch];
    }
    MIN(out[cur_state], idx); // 
}
void buildMatchingMachine() {
    for(int i = 0 ; i < 26 ; i++) {
        if(trie[0][i] == -1) 
            trie[0][i] = 0;
    }
    queue<int> q;
    for(int i = 0 ; i < 26 ; i++) {
        if(trie[0][i] != 0) {
            lps[trie[0][i]] = 0;
            q.push(trie[0][i]);
        }
    }
    while(!q.empty()) {
        int state = q.front();
        q.pop();
        for(int ch = 0 ; ch < 26 ; ch++) {
            if(trie[state][ch] != -1) {
                int fil = lps[state];
                while(trie[fil][ch] == -1) 
                    fil = lps[fil];
                lps[trie[state][ch]] = fil = trie[fil][ch];
                MIN(out[trie[state][ch]] , out[fil]); 
                q.push(trie[state][ch]);
            }
        }
    }
}
int nextState(int cur_state, char x) {
    int ch = x-'a';
    while(trie[cur_state][ch] == -1)
        cur_state = lps[cur_state];
    return trie[cur_state][ch];
}
bool serachWords(string s, int idx) {
    int cur_state = 0 , n = s.size();
    for(int i = 0 ; i < n ; i++) {
        cur_state = nextState(cur_state , s[i]);
        if(out[cur_state] < idx) R 1;
    }
    return 0;
}
pair<int,string> a[N];
void solve() {
    build();
    int n;cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i].F >> a[i].S;
        if(a[i].F == 0) insert(a[i].S , i);
    }
    buildMatchingMachine();
    for(int i = 0 ; i < n ; i++) {
        if(a[i].F == 1) {
            YES(serachWords(a[i].S , i));
        }
    }
}
void sett(){
}
int32_t main() {
    SD;
    int t = 1;
    // cin >> t;
    // scanf("%d" , &t);
    while(t--){  
        solve();
        sett();
    }
}