#include<bits/stdc++.h>
using namespace std;

const int N=100100;
long long mem[10][N];
int a[]={1 , 5 , 10 , 25 , 50};

long long dp(int i , int n){
    if(n == 0)
        return 1;

    if(i == 5)
        return 0;

    if(mem[i][n] != -1)
        return mem[i][n];

    long long path1=0 , path2=0;

    if(n >= a[i]){
        path1=dp(i , n-a[i]);
        path2=dp(i+1 , n);
    }

    return mem[i][n]=path1 + path2;

}

int main()
{
    int n;
    memset(mem,-1,sizeof mem);

    while(cin>>n){
        cout<<dp(0,n)<<endl;
    }
    return 0;
}
