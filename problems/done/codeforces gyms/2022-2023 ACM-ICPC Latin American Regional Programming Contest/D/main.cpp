#include <iostream>

using namespace std;

int main()
{
    int n;cin>>n;
    int a,b;cin>>a>>b;
    for(int i=0;i<n;i++){
        char c1,c2;cin>>c1>>c2;
        if(c1=='Y'||!b)cout<<"Y ",b++,a--;
        else cout<<"N ";

        if(c2=='Y'||!a)cout<<"Y\n",b--,a++;
        else cout<<"N\n";
    }
    return 0;
}
// --aa--
