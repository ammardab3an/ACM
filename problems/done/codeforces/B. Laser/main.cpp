#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, x1, y1, x2, y2;
        long long a, b, sum;

        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        if(y1 > y2)
            swap(y1, y2);
        if(x1 > x2)
            swap(x1, x2);

        a = n - x2 + x1;
        b = m - y2 + y1;
        sum = a * b * 2;

        if(a * 2 > n && b * 2 > m){
            sum -= (a * 2 - n) * (b * 2 - m);
        }

        long long re = (long long)n * m - sum;
        cout << re << endl;
    }
    return 0;
}
