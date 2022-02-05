#include <bits/stdc++.h>

using namespace std;

//declarations
int n, sz;
int  arr[200020];
bool had[200020];
vector<int> notHad, givers;

void makeItRight(int i, int dir)
{
    if(i == -1 || i == sz)
        return;

    if(notHad[i] == givers[i])
    {
        // if I'm going to go outside the vector then change the direction of checking.
        // this condition is equal to !(dir == +1 && i+1 < sz) && !(dir == -1 &&  0 < i)

        if(0 <= i && sz <= i+1)
            dir *= -1;

        swap(notHad[i], notHad[i + dir]);
    }
    makeItRight(i + dir, dir);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);

        if(arr[i])
            had[arr[i]] = true;
        else
            givers.push_back(i);
    }

    for(int i = 1; i <= n; i++)
        if(!had[i])
            notHad.push_back(i);

    sz = givers.size();

    makeItRight(0, 1); // just like magic

    for(int i = 1, j = 0; i <= n; i++)
    {
        if(arr[i])
            printf("%d ", arr[i]);
        else
        {
            printf("%d ", notHad[j]);
            j++;
        }
    }
}
