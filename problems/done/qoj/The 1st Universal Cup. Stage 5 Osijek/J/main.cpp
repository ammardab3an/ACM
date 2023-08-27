#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    if(n==1){
        cout << "POSSIBLE" << endl;
        cout << "1 1" << endl;
    }
    else {
        if(n%10){
            cout << "IMPOSSIBLE" << endl;
        }else{
            vector<pair<int,int>>v={{1,1},{4,2},{3,5},{2,8},{5,9},{6,6},{7,3},{10,4},{9,7},{8,10}};
            cout << "POSSIBLE" << endl;
            for(int i=0;i<n;i+=10){
                for(auto x:v){
                    cout<<x.first+i<<" "<<x.second+i<<'\n';
                }
            }
        }
    }
}

