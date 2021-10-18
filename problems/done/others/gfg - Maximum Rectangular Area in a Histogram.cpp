// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array

class Solution
{
    public:
    long getMaxArea(long long arr[], long long n){
        
        long long res = 0;
        long long curr = 0;
        stack<long long> s;
        long long i;
        
        for(i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()] > arr[i])
            {
                int topp = s.top();
                s.pop();
                curr = arr[topp] * ((s.empty()) ? i : (i-s.top()-1));
                res = max(res,curr);
            }
            s.push(i); 
        }
        
        while(!s.empty())
        {
            int topp = s.top();
            s.pop();
            curr = arr[topp] * ((s.empty()) ? i : (i-s.top()-1));
            res = max(res,curr);
        }
        return res;
        
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends