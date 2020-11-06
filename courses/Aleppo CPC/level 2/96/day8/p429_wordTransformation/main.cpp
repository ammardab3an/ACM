#include<bits/stdc++.h>

using namespace std;

//declarations
map<int, map<string, vector<string> > > graph;
// map<length, map<word, vector<of similar words> > >

int bfs(string src, string dist, int ln)
{
    map<string, int> visited;
    visited[src] = 0;
    queue<string> q;
    q.push(src);
    while(!q.empty())
    {
        string top = q.front(); q.pop();
        if (top == dist)
            return visited[top];
        for (auto w : graph[ln][top])
        {
            if (!visited.count(w))
            {
                visited[w] = visited[top] +1;
                q.push(w);
            }
        }
    }
}
bool compare(string a, string b, int ln)
{
    bool cnt = 0;

    for(int i = 0; i < ln; i++)
        if (a[i] != b[i])
        {
            if (cnt)
                return 0;
            cnt++;
        }
    return cnt == 1;
}
void input()
{
    graph.clear();
    string word; int ln;
    while(true)
    {
        getline(cin, word);
        ln = word.size();
        graph[ln][word];
        if (word[0] == '*')
            return;
        for(auto g : graph[ln])
            if (compare(word, g.first, ln))
            {
                graph[ln][word].push_back(g.first);
                graph[ln][g.first].push_back(word);
            }
    }
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
            cout << inputLine << " " << bfs(src, dist, src.size()) << endl;
        }
        if (n)
            cout << endl; // Presentation error
    }
return 0;
}
