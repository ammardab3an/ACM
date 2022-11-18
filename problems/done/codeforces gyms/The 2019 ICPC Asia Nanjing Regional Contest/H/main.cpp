#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if(b + c >= a){
        puts("NO");
        return 0;
    }

    puts("YES");
    cout << (b+c)*2 + 1;

    return 0;
}
