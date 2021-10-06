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

const int MAX = 1500 + 10;

int arr[MAX];

int main(){

    int n;
    scanf("%d", &n);

    for(int i =  0; i < n; i++)
        scanf("%d", &arr[i]);

    map<int, vpii> segs;

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            segs[sum].push_back({i, j});
        }
    }

    int ans; int k = 0;

    for(auto seg : segs){

        sort(seg.second.begin(), seg.second.end());

        int cnt = 0;
        int lst = -1;

        for(pii p : seg.second) if(p.first > lst){
            lst = p.second;
            cnt++;
        }

        if(cnt > k) ans = seg.first, k = cnt;
    }

    printf("%d\n", k);
    int lst = -1;
    for(auto p : segs[ans]) if(p.first > lst){
        printf("%d %d\n", p.first+1, p.second+1);
        lst = p.second;
    }
}
