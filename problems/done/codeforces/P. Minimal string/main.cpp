// By AmmarDab3an - Aleppo University

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    int strSz = str.size();

    int arr[26];
    memset(arr, 0, sizeof arr);

    for(int i = 0; i < strSz; i++)
        arr[str[i] - 'a']++;

    stack<char> st;

    int cur = 0;
    while(!arr[cur]) cur++;

    for(int i = 0; i < strSz; i++){
        char c = str[i];
        if(c == 'a' + cur){
            cout << c;
            arr[c - 'a']--;
            while(!arr[cur]) cur++;
            while(!st.empty() && (st.top() <= 'a' + cur)){
                cout << st.top(); st.pop();
            }
        }
        else{
            st.push(c);
            arr[c - 'a']--;
        }
    }
    while(!st.empty()){
        cout << st.top(); st.pop();
    }
}
