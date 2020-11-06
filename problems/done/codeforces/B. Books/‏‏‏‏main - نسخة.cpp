#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
 
int A[N];
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t;
    cin>>n>>t;
 
    for(int i = 0; i < n; i++)
        cin>>A[i];
 
    int ans = 0, sum = 0, left = 0;
    for(int right = 0; right < n; right++)
    {
        sum += A[right];
 
        while(sum > t)
            sum -= A[left++];
 
        ans = max(ans, right - left + 1);
    }
 
    cout<<ans<<"\n";
    return 0;
}