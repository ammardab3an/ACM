#include<bits/stdc++.h>

using namespace std;

//declarations
#define MAX 201
array<vector<string>, MAX> dict;

bool compare(string a, string b, int ln)
{
    bool cnt = false;

    for(int i = 0; i < ln; i++)
        if (a[i] != b[i])
        {
            if (cnt)
                return false;
            cnt++;
        }
    return true;
}
int go(string src, string dist, int ln, set<string> past)
{
    int mn = INT_MAX -1;
    for(auto nxtWord : dict[ln])
        if (compare(src, nxtWord, ln) &&
                past.find(nxtWord) == past.end())
        {
            if (nxtWord == dist)
                return true;

            // take it
            past.insert(nxtWord);
            mn = min(mn, go(nxtWord, dist, ln, past) +1);
            // leave it
            past.erase(nxtWord);
        }
    return mn;
}
void input()
{
    string s;
    dict.fill({});
    while(true)
    {
        getline(cin, s);
        if (s[0] == '*')
            break;
        dict[s.size()].push_back(s);
    }
    /*
    we can use cin method, but we have to clear the buffer [cin.ignore(INT_MAX, "\n")] after the input
    function done because cin function scan the entry to the very next space or \n, so it leaves a "\n"
    string in the buffer so if we call getline after that it will return a blank string and that could
    raise an error if we used that.
    */
}

int main()
{
    int n;
    char inputChar[50];
    string inputLine, src, dist;

    cin >> n;
    while(n--)
    {
        input();
        while(true)
        {
            getline(cin, inputLine);
            if (inputLine.empty())
                break;
            // entry formating
            strcpy(inputChar, inputLine.c_str());

            src  = strtok(inputChar, " ");
            dist = strtok(NULL, " ");
            cout << inputLine << " " << go(src, dist, src.size(), {src}) << endl;
        }
        if (n)
            cout << endl; // Presentation error
    }
    return 0;
}
