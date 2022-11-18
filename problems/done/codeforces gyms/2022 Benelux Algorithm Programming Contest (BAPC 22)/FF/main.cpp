#include <bits/stdc++.h>
using namespace std;
#define double long double

double get(string s)
{
    int E = 0, N =0, W = 0, S = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == 'E') E++;
        else if(s[i] == 'N') N++;
        else if(s[i] == 'W') W++;
        else S++;
    }


    double ans=0;
    if(E && N)
    {
        ans = 0;
        double cur= 180;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'E' && ans >0) ans -= cur / 2;
            else if (s[i] == 'N' && ans <90) ans += cur/2;
            cur/= 2;
        }

    }
    else if (N && W)
    {
        ans = 90;
        double cur= 180;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'N' && ans >90) ans -= cur / 2;
            else if (s[i] == 'W' && ans <180) ans += cur/2;
            cur/= 2;
        }
    }
    else if (W && S)
    {
        ans = 180;
        double cur= 180;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'W' && ans >180) ans -= cur / 2;
            else if (s[i] == 'S' && ans <270) ans += cur/2;
            cur/= 2;
        }
    }
    else if (S && E)
    {
        ans = 270;
        double cur= 180;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'S' && ans >270) ans -= cur / 2;
            else if (s[i] == 'E' && ans <360) ans += cur/2;
            cur/= 2;
        }
    }

    else if(E) return 0;
    else if(N) return 90;
    else if(W) return 180;
    else if(S) return 270;
    return ans;
}

int main()
{
    string s, t;
    cin>>s>>t;
    double a = get(s), b = get(t);
    double aa = max(a,b), bb = min(a,b);
    double ans = min(aa-bb, bb + 360 - aa);
    cout << fixed << setprecision(12) << ans;

    return 0;
}
