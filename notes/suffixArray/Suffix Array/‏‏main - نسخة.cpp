

// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

void count_sort(vector<int> &p, vector<int> & c){

    int n = p.size();

}

void radix_sort(vector<pair<pair<int, int>, int>> & arr){

    int n = arr.size();

    {
        vector<int> cnt(n), pos(n);
        for(auto p : arr) cnt[p.first.second]++;

        pos[0] = 0;
        for(int i = 1; i < n; i++) pos[i] = pos[i-1] + cnt[i-1];

        vector<pair<pair<int, int>, int>> new_arr(n);

        for(auto p : arr) new_arr[pos[p.first.second]++] = p;

        arr = new_arr;
    }

    {
        vector<int> cnt(n), pos(n);
        for(auto p : arr) cnt[p.first.first]++;

        pos[0] = 0;
        for(int i = 1; i < n; i++) pos[i] = pos[i-1] + cnt[i-1];

        vector<pair<pair<int, int>, int>> new_arr(n);

        for(auto p : arr) new_arr[pos[p.first.first]++] = p;

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
        for(int i = 1; i < n; i++)
            c[p[i]] = c[p[i-1]] + (a[i].first != a[i-1].first);
    }

    for(int k = 0; (1 << k) < n; k++){

        vector<pair<pair<int, int>, int>> a(n);


        for(int i = 0; i < n; i++) a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};

        radix_sort(a);

        for(int i = 0; i < n; i++) p[i] = a[i].second;

        c[p[0]] = 0;
        for(int i = 1; i < n; i++)
            c[p[i]] = c[p[i-1]] + (a[i].first != a[i-1].first);
    }

    for(int i = 0; i < n; i++)
        cout << p[i] << ' ';
}

int main(){

    string str;
    cin >> str;
    suffix(str);
}
