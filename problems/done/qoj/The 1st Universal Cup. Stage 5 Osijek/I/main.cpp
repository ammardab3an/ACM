#include <iostream>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;

    if(n <= 2){
        cout << 1 << endl;
    }
    else{
        cout << (n*1ll*2)%998244353 << endl;
    }
}
