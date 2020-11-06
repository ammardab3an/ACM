#include<bits/stdc++.h>

using namespace std;

int compare(int i , int j)
{
    if (i == j) return -1;
    if (i < j)  return 0;
    if (i > j)  return 1;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    string s;
    int h, m, total;
    int cnt = 0, f = 1, last = INT_MAX;

    while(n--)
    {
        getline(cin, s);
        h = stoi(s.substr(1, 2));
        m = stoi(s.substr(4, 2));

        if (h == 12) h = 0;

        total = (s[7] == 'a') ? (h*60 + m) : ((h + 12)*60 + m);

        switch (compare(total, last))
        {
            case -1: // total equal to last
                if (f < 10)
                    f++;
                else
                {
                    cnt++;
                    f = 1;
                }
                break;

            case 0: // total is smaller than last
                cnt++;
                f = 1;
                break;

            case 1: // total is bigger than last
                f = 1;
                break;
        }
        last = total;
    }

    cout << cnt << endl;

    return 0;
}
