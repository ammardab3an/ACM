#include <iostream>

using namespace std;

int main()
{
    int n;
    for(cin >> n; n--;)
    {
        int i; cin >> i;
        if(i%2)
        {
            cout << "First";
            return 0;
        }
    }
    cout << "Second";
}
