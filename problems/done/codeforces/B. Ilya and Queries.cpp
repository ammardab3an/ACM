#include <iostream>

using namespace std;

//declaration
string s;
int a[100001];

void go()
{
    for (int i = 0; i < s.length(); i++)
    {
        a[i] = a[i-1];
        if (s[i] == s[i+1])
            a[i]++;
    }

}
int main()
{
    int n;
    cin >> s >> n;
    go();

    while(n--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r-2]-a[l-2] << endl;
    }
    return 0;
}
