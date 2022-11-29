// kmp tree min
// minimum index of inserted pattern
// solved offline

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