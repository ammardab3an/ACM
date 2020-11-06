#include<bits/stdc++.h>

using namespace std;
        //if (lexicographical_compare(one, one+strlen(one), two, two+strlen(two)))

#define MAX 5001

int main()
{
    char one[MAX], two[MAX], re[MAX];

    while (true)
    {
        scanf("%s", &one);
        scanf("%s", &two);

        sort(one, one + strlen(one));
        memset(re, ' ', sizeof re);
        int one_l = strlen(one), two_l = strlen(two);

        for(int i = 0; i < two_l; i++)
        {
            if (two[i] > one[one_l -1])
            {
                cout << "--" << two[i] << " " << one[one_l -1] << endl;
            }
            for(int j = 0; j < one_l; j++)
                if (one[j] == two[i])
                {
                    re[i] = two[i];
                    one[j] = ' ';
                    break;
                }
        }

        for(int i = 0; i < one_l; i++)
            cout << re[i];
        cout << endl;

        sort(one, one + strlen(one));

        for(int i = 0; i < one_l; i++)
            cout << one[i];
        cout << endl;

    }

    return 0;
}
