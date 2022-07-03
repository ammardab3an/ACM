#include <iostream>

using namespace std;

int main()
{

    string a[2];
    cin >> a[0] >> a[1];

    int ok[4] = {0};

    int n = a[0].length();
    for(int i = 0; i < n; i++){
        int num = 0;
        if(a[0][i] == '#') num |= 1;
        if(a[1][i] == '#') num |= 2;
        ok[num]++;
    }

    if(ok[1] && ok[2] && !ok[3]) puts("NO");
    else {
        puts("YES");
        for(int i = 0; i < ok[0]; i++){
            printf(".");
        }
        for(int i = 0; i < ok[1]; i++){
            printf("#");
        }
        for(int i = 0; i < ok[3]; i++){
            printf("#");
        }
        for(int i = 0; i < ok[2]; i++){
            printf(".");
        }
        puts("");
        for(int i = 0; i < ok[0]; i++){
            printf(".");
        }
        for(int i = 0; i < ok[1]; i++){
            printf(".");
        }
        for(int i = 0; i < ok[2]; i++){
            printf("#");
        }
        for(int i = 0; i < ok[3]; i++){
            printf("#");
        }
    }

    return 0;
}
