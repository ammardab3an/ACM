#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

typedef long double dt;
typedef complex<dt> cd;

const int NMAX = 1e5 + 10;
const int BLOCK_SZ = sqrt(NMAX);
const dt PI = acos(-1);

void fft(vector<cd> & a, bool invert) {

    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        dt ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> calc(const vector<int> &vec){

    vector<cd> A(vec.size()*2), B(vec.size()*2);

    for(int i = 0; i < vec.size(); i++){
        A[i] = A[i+vec.size()] = vec[i]+1;
    }

    for(int i = 0; i < vec.size(); i++){
        B[i] = vec[vec.size()-i-1]+1;
    }

    int sz = A.size()*2-1;
    sz = 1 << int(ceil(log2(dt(sz))));

    A.resize(sz);
    B.resize(sz);

//    for(auto i : A) cout << i << ' '; cout << endl;
//    for(auto i : B) cout << i << ' '; cout << endl;

    fft(A, false);
    fft(B, false);

    for(int i = 0; i < sz; i++){
        A[i] *= B[i];
    }

    fft(A, true);

    vector<int> ret(vec.size());
    for(int i = 0; i < vec.size(); i++){
        ret[i] = roundl(A[vec.size()-1+i].real());
    }

    return ret;
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    for(auto &i : vec) cin >> i, i--;

    vector<vector<int>> vec_c_s, vec_c_l;
    vector<bool> vis(n);

    for(int i = 0; i < n; i++) if(!vis[i]){

        int p = i;
        vector<int> cur;
        while(!vis[p]){
            vis[p] = true;
            cur.push_back(p);
            p = vec[p];
        }

        if(cur.size() >= BLOCK_SZ){
            vec_c_l.push_back(cur);
        }
        else{
            vec_c_s.push_back(cur);
        }
    }

    vector<vector<int>> tmp_l;
    for(auto &v : vec_c_l){
        tmp_l.push_back(calc(v));
    }

    vector<vector<int>> tmp_s(BLOCK_SZ);
    for(int i = 0; i < BLOCK_SZ; i++){
        tmp_s[i] = vector<int>(i, 0);
    }

    for(auto &v : vec_c_s){
        vector<int> tmp = calc(v);
        for(int i = 0; i < v.size(); i++){
            tmp_s[v.size()][i] += tmp[i];
        }
    }

    while(q--){

        int k;
        cin >> k;

        int ans = 0;

        for(auto &v : tmp_l){
            ans += v[k%v.size()];
        }

        for(int i = 1; i < BLOCK_SZ; i++){
            ans += tmp_s[i][k%i];
        }

        cout << ans << endl;
    }
}
