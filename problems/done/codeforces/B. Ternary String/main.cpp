#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+10;

char str[MAX];
int arr[MAX][6];

int main()
{
    int t; cin >> t; while(t--){

        cin >> str;
        int strLen = strlen(str);

        int tmp[3];
        memset(tmp, -1, sizeof tmp);

        for(int i = 0; i < strLen; i++){
            for(int j = 0; j < 3; j++)
                arr[i][j] = tmp[j];
            tmp[str[i] - '0' -1] = i;
        }

        memset(tmp, -1, sizeof tmp);
        for(int i = strLen-1; i >= 0; i--){
            for(int j = 0; j < 3; j++)
                arr[i][j+3] = tmp[j];
            tmp[str[i] - '0' -1] = i;
        }

        int ans = INT_MAX;

        for(int i = 0; i < strLen; i++){

            int x, y;
            if(str[i] == '1')
                x = 1, y = 2;
            else if(str[i] == '2')
                x = 0, y = 2;
            else
                x = 0, y = 1;

            if((arr[i][x] == -1 && arr[i][x+3] == -1) || (arr[i][y] == -1 && arr[i][y+3] == -1))
                continue;

            int tmp = INT_MAX;

            if(arr[i][x] != -1 && arr[i][y+3] != -1)
                tmp = arr[i][y+3] - arr[i][x] +1;

            if(arr[i][y] != -1 && arr[i][x+3] != -1)
                tmp = min(tmp, arr[i][x+3] - arr[i][y] +1);

            ans = min(ans, tmp);
        }

        cout << (ans != INT_MAX ? ans : 0) << endl;
    }
}
