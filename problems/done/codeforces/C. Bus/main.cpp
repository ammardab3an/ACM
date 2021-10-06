#include<bits/stdc++.h>

using namespace std;
#define pii pair<int,int>
#define iii pair<int, pii>
#define id first
#define tx second
#define t_i first
#define x_i second
int main()
{
    // input and sorting by time /t_i/
    int n, m;
    cin >> n >> m;
    iii que[100000];
    for(int t, x, i = 0; i < n; i++)
    {
        cin >> t >> x;
        que[i] = {i, {t, x}};
    }
    sort(que, que+n, [](iii p1, iii p2){return p1.tx.t_i < p2.tx.t_i;});

    // simulator
    int ans[100000], watch = 0, pos = 0;
    // compare function / by x_i /.
    auto comp = [](iii p1, iii p2){return p1.tx.x_i> p2.tx.x_i;};
    while(pos < n)
    {
        priority_queue<iii, vector<iii>, decltype(comp)> bus(comp);
        for(int i = 0; i < m && pos+i < n; i++)
        {
            bus.push(que[pos+i]);
            watch = max(watch, que[pos+i].tx.t_i);
        }
        pos += m;
        int lastPos = 0;
        while(!bus.empty())
        {
            // vec contains group of students who arrived to their destination.
            vector<iii> vec = {bus.top()}; bus.pop();
            while(!bus.empty())
            {
                iii top = bus.top();
                if(top.tx.x_i == vec[0].tx.x_i)
                {
                    vec.push_back(top);
                    bus.pop();
                }
                else break;
            }
            // assign arriving time value for each of them.
            // watch += time between last bus stop and this one.
            watch += vec[0].tx.x_i - lastPos;
            for(auto it:vec)
                ans[it.id] = watch;
            // time wanted for the group to get off.
            watch += 1 + int(vec.size()/2);

            lastPos = vec[0].tx.x_i;
        }
        // returning to bus stop at school.
        watch += lastPos;
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ' ;
    return 0;
}
