#include<bits/stdc++.h>

using namespace std;

int main(){

    float a, b, c, d;
    cin >> a >> b >> c >> d;

    float p, q;
    p = a/b;
    q = (1.0 - c/d) * (1.0 - p);

    float ans = 0;
    float lmt = p / (1.0 - q);

    for(int i = 0; i < 1e5; i++)
        ans += p * pow(q, i);

    cout <<  ans;
}
