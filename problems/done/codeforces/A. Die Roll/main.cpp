#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x,y;
    cin >>x>>y;
    int r = 7-max(x,y);
    int gcd = __gcd(r,6);
    cout <<(r/gcd)<<"/"<<(6/gcd) ;
    return 0;
}

