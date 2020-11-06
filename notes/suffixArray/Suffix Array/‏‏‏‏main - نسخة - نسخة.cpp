
// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

void radixSort(vector<pair<pair<int, int>, int>> & arr){

    int n = arr.size();

    {
        vector<int> cnt(n);
        for(int i = 0; i < n; i++)
            cnt[arr[i].first.second]++;

        vector<pair<pair<int, int>, int>> new_arr(n);
        vector<int> pos(n);

        pos[0] = 0;
        for(int i = 1; i < n; i++)
            pos[i] = pos[i-1] + cnt[i-1];

        for(auto p : arr){
            int i = p.first.second;
            new_arr[pos[i]] = p;
            pos[i]++;
        }

        arr = new_arr;
    }

    {
        vector<int> cnt(n);
        for(int i = 0; i < n; i++)
            cnt[arr[i].first.first]++;

        vector<pair<pair<int, int>, int>> new_arr(n);
        vector<int> pos(n);

        pos[0] = 0;
        for(int i = 1; i < n; i++)
            pos[i] = pos[i-1] + cnt[i-1];

        for(auto p : arr){
            int i = p.first.first;
            new_arr[pos[i]] = p;
            pos[i]++;
        }

        arr = new_arr;
    }

}

void suffix(string str){

    str += "$";
    int n = str.size();

    vector<int> p(n), c(n);

    {
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) a[i] = {str[i], i};
        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++) p[i] = a[i].second;

        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]] +1;

        }
    }


    for(int k = 0; (1 << k) < n; k++){

        vector<pair<pair<int, int>, int>> a(n);
        for(int i = 0; i < n; i++) a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};


        radixSort(a);

//        sort(a.begin(), a.end());


        for(int i = 0; i < n; i++) p[i] = a[i].second;

        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else
                c[p[i]] = c[p[i-1]] +1;

        }
    }

    for(int i = 0; i < n; i++)
//        cout << p[i] << " " << str.substr(p[i], n - p[i]) << endl;
        cout << p[i] << ' ';
}

int main(){

    string str;
    cin >> str;
    suffix(str);
}
