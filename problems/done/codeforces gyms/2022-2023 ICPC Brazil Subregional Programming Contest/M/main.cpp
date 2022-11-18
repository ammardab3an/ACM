#include<bits/stdc++.h>

using namespace std;

#define int int64_t

const int NMAX = 1e6 + 10;
const int MAXN = 1e6 + 10;

typedef vector<int> vi;
typedef pair<int, int> pii;

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;

    while(x != 1){
        int p = spf[x];
        ret.push_back(p);
        while(x%p==0) x/=p;
    }

    return ret;
}

int sm[NMAX];
int vis[NMAX], vid;

void add_sm(int i, int d){
    if(vis[i] != vid){
        vis[i] = vid;
        sm[i] = 0;
    }
    sm[i] += d;
}

int get_sm(int i){
    if(vis[i]!=vid){
        return 0;
    }
    return sm[i];
}

void clear_sm(){
    vid++;
}

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    sieve();

    int n, q;
    cin >> n >> q;

    vi vec(n);
    for(auto &i : vec) cin >> i;

    vector<pii> queries(q);
    for(auto &[c, d] : queries){
        cin >> c >> d;
    }

    vector<vi> vec_vp(n);
    for(int i = 0; i < n; i++){
        vec_vp[i] = getFactorization(i+1);
    }
    vector<vi> queries_vp(q);
    for(int i = 0; i < q; i++){
        queries_vp[i] = getFactorization(queries[i].first);
    }

    vector<vector<pii>> vec_vp_precalc(n);
    for(int i = 0; i < n; i++){
        auto &v = vec_vp[i];
        for(int msk = 1; msk < (1<<v.size()); msk++){
            int p = 1;
            for(int i = 0; i < v.size(); i++) if((msk>>i)&1){
                p *= v[i];
            }
            vec_vp_precalc[i].push_back({p, __builtin_popcount(msk)%2});
        }
    }

    vector<vi> queries_vp_precalc(q);
    for(int i = 0; i < q; i++){
        auto &v = queries_vp[i];
        for(int msk = 1; msk < (1<<v.size()); msk++){
            int p = 1;
            for(int i = 0; i < v.size(); i++) if((msk>>i)&1){
                p *= v[i];
            }
            queries_vp_precalc[i].push_back(p);
        }
    }

    vi ans(n);

    queue<pair<pii, vi>> que;
    que.push({{0, q}, vi(n)});
    iota(que.front().second.begin(), que.front().second.end(), 0);

    vi tmp;
    int cur = 1e9;

    auto update_sm = [&](int i){
        int di = queries[i].second;
        for(auto p : queries_vp_precalc[i]){
            add_sm(p, di);
        }
    };

    auto query_sm = [&](int i){
        int ret = 0;
        auto &v = vec_vp[i];
        for(auto [p, b] : vec_vp_precalc[i]){
            if(b) ret += get_sm(p);
            else ret -= get_sm(p);
        }
        return ret;
    };

    while(!que.empty()){

    	auto fr = que.front();
    	que.pop();

    	int l = fr.first.first;
    	int r = fr.first.second;
    	auto &v = fr.second;

    	if(l==r){
    		for(auto i : v) ans[i] = l;
    		continue;
    	}

    	int mid = (l+r)/2;

    	if(cur <= mid){
    		for(int i = cur+1; i <= mid; i++){
                update_sm(i);
    		}
    	}
    	else{
            clear_sm();
            for(int i = 0; i <= mid; i++){
                update_sm(i);
            }
    	}

    	cur = mid;

		vi lf, ri;
    	for(auto i : v){
    		int tot = query_sm(i);
    		if(vec[i] <= tot){
    			lf.push_back(i);
    		}
    		else{
    			ri.push_back(i);
    		}
    	}

    	if(!lf.empty()) que.push({{l, mid}, lf});
    	if(!ri.empty()) que.push({{mid+1, r}, ri});
    }

    for(auto e : ans){
        if(e==q) e = -1;
        else e = e+1;
        cout << e << endl;
    }
}
