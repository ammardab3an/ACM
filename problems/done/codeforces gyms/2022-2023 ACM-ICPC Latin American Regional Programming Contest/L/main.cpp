#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct sparse_table {

    int N, K;
    vector<vector<int>> st;
    vector<int> log;

    int f(int x){return x;}
    int f(int x, int y){
        return min(x, y);
    }

    sparse_table(){}
    sparse_table(vector<int> a){

        N = a.size();
        K = ceil(log2(N))+1;
        st.resize(N, vector<int>(K+1));

        log.resize(N+1);
        log[1] = 0;
        for(int i = 2; i <= N; i++) log[i] = log[i/2]+1;

        for(int i = 0; i < N ;i++) st[i][0] = f(a[i]);

        for(int j = 1; j <= K; j++){

            for(int i = 0; i + (1<<j) <= N; i++){

                st[i][j] = f(st[i][j-1], st[i + (1 << (j-1))][j-1]);

            }

        }

    }

    int minQuery(int l, int r){

        int j = log[r-l+1];
        int minimum = min(st[l][j], st[r-(1 << j)+1][j]);
        return minimum;

    }

};

struct suffix_array {

    string s;
    int n;
    vector<int> c, p, lcp;
    sparse_table st;

    suffix_array (string s){

        char dollarSign = '$';
        s += dollarSign;
        this->s = s;
        this->n = s.length();
        int n = this->n;
        vector<int> c(n, 0), p(n, 0), cnt(max(n, 256), 0);
        for(char x : s) cnt[x]++;
        for(int i = 1; i < 256; i++) cnt[i] += cnt[i-1];
        for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++) c[p[i]] = (s[p[i]] != s[p[i-1]]) ? c[p[i-1]] + 1 : c[p[i-1]];
        for(int i = 2; i <= 2*n; i <<= 1){
            vector<pair<int, int>> v;
            vector<int> pn = p, cn = c;
            for(int j = 0; j < n; j++){
                v.push_back({j, (j+i/2)%n});
            }
            for(int &j : cnt) j = 0;
            for(int j = 0; j < n; j++) cnt[c[v[j].second]]++;
            for(int j = 1; j < n; j++) cnt[j] += cnt[j-1];
            for(int j = 0; j < n; j++) pn[--cnt[c[v[j].second]]] = j;
            for(int &j : cnt) j = 0;
            for(int j = 0; j < n; j++) cnt[c[pn[j]]]++;
            for(int j = 1; j < n; j++) cnt[j] += cnt[j-1];
            for(int j = 0; j < n; j++) p[--cnt[c[pn[n-1-j]]]] = pn[n-1-j];
            cn[p[0]] = 0;
            int classes = 1;
            for(int j = 1; j < n; j++){
                pair<int, int> cur = { c[p[j]], c[(p[j]+i/2)%n] };
                pair<int, int> prev = { c[p[j-1]], c[(p[j-1]+i/2+n)%n] };
                if(cur != prev) classes++;
                cn[p[j]] = classes-1;
            }
            c.swap(cn);
        }

        // c.pop_back();
        // for(int &x : c) x--;
        // p.erase(p.begin());

        for(int x : p) cout << x << " ";
        cout << endl;
        for(int x : c) cout << x << " ";
        cout << endl;

        this->p = p;
        this->c = c;

    }

    void prt(){for(int x : p) cout << x << " "; cout << endl;}

    void st_build(){
        assert((int)lcp.size() > 0);
        sparse_table st1(lcp);
        st = st1;
        return;
    }

    void lcp_build(){
        lcp.resize(n-1);
        for(int i = 0, k = 0; i < n; i++){
            if(c[i] == n-1){
                k = 0;
                continue;
            }
            int j = p[c[i]+1];
            cout << "P " << " nad " << c[i] << endl;
            for(int x : p) cout << x << " ";
            cout << endl;
            while(i+k < n && j+k < n && s[i+k] == s[k+j]) k++;
            lcp[c[i]] = k;
            if(k > 0) k--;
        }
    }

    int lcp_query(int i, int j){
        cout << "final " << endl;
        if(i == j) return n - i - 1;
        if(c[i] > c[j]-1) swap(i, j);
        assert(c[i] <= c[j]-1);
        return st.minQuery(c[i], c[j]-1);
    }

};

char buf[200010];

string read(){
    scanf("%s", buf);
    return buf;
}

int main()
{

    string s;
    int d;
    cin >> s >> d;

    suffix_array suf(s);
    suf.lcp_build();
    cout << "here" << endl;
    cout << "here2222222222221" << endl;
    suf.st_build();

    int n = s.length();
    cout << "hereNNNN " << n << endl;
    int ans = 0, len = 0;
    vector<int> vis(n+10, 0);
    for(int i = 0; i < n;){
        if(vis[i]) continue;
        cout << "i " << i << endl;
        ans++;
        int curI = i+1;
        vis[i] = 1;
        cout << "hereCCCc " << curI << endl;
        int len = 1, pos = 0;
        while(curI < n){
            cout << "In while" << endl;
            assert(i+pos%n < curI);
            cout << "sCur " << curI << endl;
            if(s[curI] == s[i+(pos)%len]) pos++, curI++;
            else {
                cout << "here10 " << endl;
                while(len <= d && suf.lcp_query(i, i+len+1) != (curI-i+1)-len-1) len++;
                cout << "len" << endl;
                if(len > d){
                    i = curI;
                    break;
                }
                vis[curI] = 1;
                curI++;
            }
        }
        if(i == n-1) break;
    }

    cout << "Got here" << endl;
    cout << ans;

    return 0;

}
