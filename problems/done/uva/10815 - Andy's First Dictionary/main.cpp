#include <bits/stdc++.h>

using namespace std;

int main()
{
    string inputStr, str;
    set<string> st;

    while(getline(cin, inputStr))
    {
        for(auto c : inputStr)
        {
            if(isalpha(c))
                str.push_back(tolower(c));
            else
                st.insert(str), str.clear();
        }
        st.insert(str), str.clear();
    }

    st.erase(st.begin());
    for(auto it : st)
        cout << it << endl;
}
