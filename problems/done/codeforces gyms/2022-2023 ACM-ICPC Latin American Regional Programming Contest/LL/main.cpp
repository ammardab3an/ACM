#include <bits/stdc++.h>

#define int int64_t
#define endl '\n'

using namespace std;


struct hash_struct{

	int n;
	string str;

	array<int, 2> p, m;
	vector<array<int, 2>> pre;
	vector<array<int, 2>> pow_m;

	hash_struct(){}

	hash_struct(string _str){
		str = _str;
		n = str.size();
		init();
		build();
	}

	bool is_prime(int x){
		for(int i = 2; i*i <= x; i++) if(x%i==0){
			return false;
		}
		return true;
	}

	void init(){

		p = {130807, 1250284429}; //{rand(1e5, 2e5), rand(1e9, 2e9)};
		m = {53, 79}; //{rand(30, 50), rand(50, 100)};

		for(int j = 0; j < 2; j++){
			while(!is_prime(p[j])) p[j]++;
			while(!is_prime(m[j])) m[j]++;
		}

		// for(auto i : p) cout << i << ' '; cout << endl;
		// for(auto i : m) cout << i << ' '; cout << endl;

		pow_m.resize(n, array<int, 2>({0, 0}));

		pow_m[0][0] = pow_m[0][1] = 1;
		for(int i = 1; i < n; i++)
		for(int j = 0; j < 2; j++){
			pow_m[i][j] = (pow_m[i-1][j] *1ll* m[j])%p[j];
		}
	}

	void build(){

		pre.resize(n);

		array<int, 2> cval = {0, 0};
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 2; j++){
				cval[j] = ((cval[j] *1ll* m[j])%p[j] + (str[i]-'a'+1))%p[j];
			}
			pre[i] = cval;
		}
	}

	array<int, 2> query(int l, int r){
		array<int, 2> ret = pre[r];
		if(l) for(int j = 0; j < 2; j++){
			ret[j] = (ret[j] - (pre[l-1][j] *1ll* pow_m[r-l+1][j])%p[j] + p[j])%p[j];
		}
		return ret;
	}

};

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int k;
    string str;

    cin >> str >> k;

    int n = str.size();
    hash_struct str_hash(str);

    auto check = [&](int l, int r, int d){

        if(d >= (r-l+1)){
            return true;
        }

        auto h0 = str_hash.query(l+d, r);
        auto h1 = str_hash.query(l, r-d);

        return h0==h1;
    };

    int ans = 1;

    int cur = 1;
    int lst = 0;
    for(int i = 1; i < n; i++){

        if(str[i] != str[i-cur]){

            while(cur <= k && !check(lst, i, cur)){
                cur++;
            }

            if(cur > k){
                lst = i;
                cur = 1;
                ans++;
            }
        }
    }

    cout << ans << endl;
}
