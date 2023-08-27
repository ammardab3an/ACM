#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector<string> calc(int n){

    vector<string> grid(n, string(n, '.'));

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        if(((i+1)/2 + j)%2 == 0){
            grid[i][j] = 'D';
        }
    }

    if(n%2==0){
        for(int i = 0; i < n; i += 2){
            if((i/2)%2==0){
                assert(grid[i][n-1]=='.');
                grid[i][n-1] = 'R';
            }
            else{
                assert(grid[i][0]=='.');
                grid[i][0] = 'L';
            }
        }
    }
    else {
        if(n >= 6) for(int i = 6; i < n; i+=4){
            assert(grid[i][0]=='.');
            assert(grid[i][n-1]=='.');
            grid[i][0]='L';
            grid[i][n-1] = 'R';
        }
        if(n >= 2) for(auto i : {2}){
            assert(grid[i][0]=='.');
            assert(grid[i][n-1]=='.');
            grid[i][0]='L';
            grid[i][n-1] = 'R';
        }
    }

    for(int i = 0; i < n; i++) if(grid[0][i]=='D'){
        grid[0][i] = 'U';
        if(n >= 2){
            assert(grid[1][i] == '.');
            grid[1][i] = 'U';
        }

    }

    return grid;
}

int main()
{

//    for(int i = 1; i <= 1000; i++){
//        cout << i << endl << flush;
//        calc(i);
//    }

    int n;
    cin >> n;

    auto grid = calc(n);
    for(int i = 0; i < n; i++){
        cout << grid[i] << endl;
    }
}
