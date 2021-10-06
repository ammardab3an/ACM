#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    for(cin >> T; T; T--)
    {
        string inputStr;
        cin >> inputStr;

        string a, b, c, d;
        a = b = c = d = "";

        bool f1, f2;
        f1 = f2 = true;

        for(auto ch : inputStr)
        {
            if(ch >= 'A')
            {
                if(f1)
                    a.push_back(ch);
                else
                {
                    c.push_back(ch);
                    f2 = false;
                }
            }
            else
            {
                if(f2)
                {
                    b.push_back(ch);
                    f1 = false;
                }
                else
                    d.push_back(ch);
            }
        }

        if(f2)
        {
            int x = 0, y = stoi(b);
            for(int i = 0; i < a.size(); i++)
                x += float((a[i] - 'A' +1) * pow(26, a.size()-1-i));
            cout << 'R' << y << 'C' << x << endl;
        }
        else
        {
            int x= stoi(b), y = stoi(d);
            string str_y = "";

            while(y)
            {
                int k = y % 26;
                if(!k)
                {
                    y = y/26 -1;
                    str_y.insert(0, "Z");
                }
                else
                {
                    y /= 26;
                    str_y.insert(0, string(1,'A'+k-1));
                }
            }
            cout << str_y << x << endl;
        }
    }
    return 0;
}
