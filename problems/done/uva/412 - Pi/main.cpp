#include<bits/stdc++.h>

using namespace std;

int main()
{
    for(int N; (cin >> N) && (N);)
    {
        vector<int> vec;
        for(int i, j = 0; (j < N) && (cin >> i); j++)
            vec.push_back(i);

        double num = 0, all = 1;
        for(int i = 0; i < N; i++)
            for(int j = i+1; (j < N) && (all++); j++)
                if(__gcd(vec[i], vec[j]) == 1)
                    num++;
        if(num)
            cout << fixed << setprecision(6) << sqrt(6*(all-1)/num) << endl;
        else
            cout << "No estimate for this data set." << endl;
    }
    return 0;
}
