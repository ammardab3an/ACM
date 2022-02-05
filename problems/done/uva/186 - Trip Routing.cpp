#include <bits/stdc++.h>

using namespace std;

#define tot first
#define routeVec second

pair< int, vector< pair< pair< int, int > , int > > > grid[100][100];
map<int, string> mp;
map<string, int> _mp; int _mpCnt = 0;

void go()
{
    for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
        grid[i][j] = {1e9, {}};

    string inputStr;
    while(getline(cin, inputStr))
    {
        if(inputStr.empty()) break;

        int cnt = 0;
        string input[4];
        for(auto c:inputStr)
        {
            if(c == ',') {
                cnt++; continue;}
            input[cnt].push_back(c);
        }
        for(int i = 0; i < 3; i++)
        if(!_mp.count(input[i]))
        {
            mp[_mpCnt] = input[i];
            _mp[input[i]] = _mpCnt;
            _mpCnt++;
        }

        if(grid[_mp[input[0]]][_mp[input[1]]].tot > stoi(input[3]))
        {
            grid[_mp[input[1]]][_mp[input[0]]] = {stoi(input[3]) , {{{_mp[input[0]], _mp[input[2]]}, stoi(input[3])}}};
            grid[_mp[input[0]]][_mp[input[1]]] = {stoi(input[3]) , {{{_mp[input[1]], _mp[input[2]]}, stoi(input[3])}}};
        }

    }

    for(int k = 0; k < 100; k++)
    for(int i = 0; i < 100; i++)
    for(int j = 0; j < 100; j++)
    if(grid[i][j].tot > grid[i][k].tot + grid[k][j].tot)
    {
        grid[i][j].tot = grid[i][k].tot + grid[k][j].tot;
        grid[i][j].routeVec = grid[i][k].routeVec;
        grid[i][j].routeVec.insert(grid[i][j].routeVec.end(), grid[k][j].routeVec.begin(), grid[k][j].routeVec.end());
    }

    while(getline(cin, inputStr))
    {
        cout << endl << endl
             << "From                 To                   Route      Miles" << endl
             << "-------------------- -------------------- ---------- -----" << endl;

        string input[2]; int cnt = 0;
        for(auto c:inputStr)
        {
            if(c == ',') {
                cnt++; continue;}
            input[cnt].push_back(c);
        }

        string past = input[0];
        for(auto it : grid[_mp[input[0]]][_mp[input[1]]].routeVec)
        {
            printf("%-20s %-20s %-10s %5d\n", past.c_str(), mp[it.first.first].c_str(), mp[it.first.second].c_str(), it.second);
            past = mp[it.first.first];
        }

        cout << "                                                     -----" << endl;
        printf( "                                          Total      %5d\n", grid[_mp[input[0]]][_mp[input[1]]].tot);
    }
}
int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);
    go();
    return 0;
}
