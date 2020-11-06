//don't use break statement when there are multiple test cases :)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    for(cin >> t; t--;)
    {
        int n, k1, k2;
        cin >> n >> k1 >> k2;

        int mx = 0;
        bool win = true;

        int num;
        for(int i = 0; i < k1; i++)
        {
            cin >> num;
            mx = max(mx, num);
        }
        for(int i = 0; i < k2; i++)
        {
            cin >> num;
            if(num > mx)
                win = false;
        }
        cout << (win ? "yes" : "no") << endl;
    }
}
