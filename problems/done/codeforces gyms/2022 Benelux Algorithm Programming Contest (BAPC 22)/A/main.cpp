#include<bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}

signed main(){

    int n, k, avg;
    cin >> n >> k >> avg;

    int sm = 0;
    vector<int> vec(n);
    for(auto &i : vec) cin >> i, sm += i;

    double ans = abs(double(avg) - double(sm)/double(n));

    if(k >= 1){
        for(auto i : vec){
            double cans = abs(double(avg) - double(sm-i)/double(n-1));
            ans = min(ans, cans);
        }
    }

    if(k >= 2){
        for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++){
            double cans = abs(double(avg) - double(sm-vec[i]-vec[j])/double(n-2));
            ans = min(ans, cans);
        }
    }

    if(k >= 3){

        for(int r = 0; r < 20; r++){

            shuffle(vec.begin(), vec.end(), rng);
            vector<int> v0(vec.begin(), vec.begin()+(vec.size()/2));
            vector<int> v1(vec.begin()+(vec.size()/2), vec.end());

            vector<int> tmp0, tmp1;
            for(int i = 0; i < v0.size(); i++)
            for(int j = 0; j < i; j++) tmp0.push_back(v0[i]+v0[j]);
            for(int i = 0; i < v1.size(); i++)
            for(int j = 0; j < i; j++) tmp1.push_back(v1[i]+v1[j]);

            sort(tmp0.begin(), tmp0.end());
            sort(tmp1.begin(), tmp1.end());

            for(auto i : v0){

                int x = (sm-i)-avg*(n-3);
                auto it = lower_bound(tmp1.begin(), tmp1.end(), x);

                if(it != tmp1.end()){
                    double cans = abs(double(avg) - double(sm-i-(*it))/double(n-3));
                    ans = min(ans, cans);
                }
                if(it != tmp1.begin()){
                    it--;
                    double cans = abs(double(avg) - double(sm-i-(*it))/double(n-3));
                    ans = min(ans, cans);
                }
            }

            for(auto i : v1){

                int x = (sm-i)-avg*(n-3);
                auto it = lower_bound(tmp0.begin(), tmp0.end(), x);

                if(it != tmp0.end()){
                    double cans = abs(double(avg) - double(sm-i-(*it))/double(n-3));
                    ans = min(ans, cans);
                }
                if(it != tmp0.begin()){
                    it--;
                    double cans = abs(double(avg) - double(sm-i-(*it))/double(n-3));
                    ans = min(ans, cans);
                }
            }

            if(k >= 4){

                for(auto i : tmp0){

                    int x = (sm-i)-avg*(n-4);
                    auto it = lower_bound(tmp1.begin(), tmp1.end(), x);

                    if(it != tmp1.end()){
                        double cans = abs(double(avg) - double(sm-i-(*it))/double(n-4));
                        ans = min(ans, cans);
                    }
                    if(it != tmp1.begin()){
                        it--;
                        double cans = abs(double(avg) - double(sm-i-(*it))/double(n-4));
                        ans = min(ans, cans);
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}
