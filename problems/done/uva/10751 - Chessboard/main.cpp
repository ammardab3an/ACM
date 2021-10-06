#include<bits/stdc++.h>

using namespace std;

int main()
{
//    ofstream myfile;
//    myfile.open ("D:\\Output.txt");
//    #define cout myfile

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        double an;
        if (N == 0 || N == 1)
            an = 0;
        else
            an = pow(N,2) + pow((N-2), 2) * (sqrt(2)-1);

        cout << fixed << setprecision(3) << an << endl;
    }
    return 0;

//    myfile.close();
}
