#include<bits/stdc++.h>

using namespace std;

int sumVec(vector<int> vec, int bitMsk, int l, int r)
{
    int tot = 0;
    for(int i = l; i < r; i++)
        tot += (bitMsk &(1<<i)) ? -vec[i] : vec[i];
    return tot;
}
void printVec(vector<int> vec)
{
    for(auto e:vec)
        cout << e << " ";
    cout << endl;
}
void printBitMsk(int bitMsk)
{
    for(int i = 0; i < 16; i++)
        cout << ((bitMsk & (1 << i)) ? 1:0) << " ";
    cout << endl;
}
set<int> re(vector<int> vec, int bitMsk)
{
//    printVec(vec); printBitMsk(bitMsk);
    int sz = vec.size();
    if(!bitMsk || sz == 1)
        return {sumVec(vec,0,0,sz)};

    set<int> outSt;

    for(int i = 0; i < sz; i++) if(bitMsk & (1 << i))
    {
        for(int j = 1; j <= sz - i; j++)
        {
            vector<int> _vec(&vec[i], &vec[i+j]);
            int _bitMsk = 0;
            for(int k = 1; k < j; k++) if(bitMsk & (1 << (i+k)))
                _bitMsk |= 1 << k;

            for(auto it:re(_vec, _bitMsk))
                outSt.insert(sumVec(vec, bitMsk, 0, i) - it + sumVec(vec, bitMsk, i+j, sz));
        }
    }
    return outSt;
}

int main()
{
    string inputStr;
    while(getline(cin, inputStr))
    {
        stringstream strStr(inputStr);
        vector<int> vec; char c; int i, bitMsk = 0;
        strStr >> i;
        vec.push_back(i);
        for(int j = 1; !strStr.eof(); j++)
        {
            strStr >> c >> i;
            vec.push_back(i);
            if(c == '-')
                bitMsk |= (1 << j);
        }

        set<int> ss = re(vec, bitMsk);
        ss.insert(sumVec(vec, bitMsk, 0, vec.size()));

        for(auto it:ss)
            cout << it << endl;

        cout << ss.size() << endl;
    }
    return 0;
}
