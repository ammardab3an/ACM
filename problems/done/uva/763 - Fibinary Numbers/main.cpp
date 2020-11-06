#include<bits/stdc++.h>

using namespace std;

// declarations
#define MAX_SZ 110
vector<string> fibVec;
array<string, MAX_SZ> mem;

// BigInt
//--------------------------------------------------------------------------------------------
string sumBigInt(string a1, string a2)
{
    string ans = "";
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());

    int a1Sz = a1.size(), a2Sz = a2.size();
    int mxSz = max(a1Sz, a2Sz);
    a2.insert(a2Sz, string(mxSz - a2Sz, '0'));
    a1.insert(a1Sz, string(mxSz - a1Sz, '0'));

    int carry = 0;
    for(int sm, i = 0; i < mxSz; i++)
    {
        sm = a1[i] - '0' + a2[i] - '0' + carry;
        ans.push_back('0' + sm % 10);
        carry = sm/10;
    }
    if(carry) ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}
string subBigInt(string a1, string a2)
{
    string ans = "";

//    if(a2 >= a1) swap(a1, a2); // a1 is always bigger than a2 Int > fibVec[i]
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());

    int a1Sz = a1.size(), a2Sz = a2.size();
    int mxSz = max(a1Sz, a2Sz);
    a2.insert(a2Sz, string(mxSz - a2Sz, '0'));
    a1.insert(a1Sz, string(mxSz - a1Sz, '0'));

    int carry = 0;
    for(int sub, i = 0; i < mxSz; i++)
    {
        sub = (a1[i] - '0') - (a2[i] - '0') - carry;
        if(sub < 0)
        {
            sub += 10;
            carry = 1;
        }
        else carry = 0;
        ans.push_back(sub + '0');
    }
    while(ans.back() == '0')
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;

}
bool biggerOrEql(string a1, string a2)
{
    int a1Sz = a1.size(), a2Sz = a2.size();
    if(a1Sz != a2Sz) return (a1Sz > a2Sz) ? true : false;
    for(int i = 0; i < a1Sz; i++)
    {
        if(a1[i] > a2[i])
            return true;
        else if(a1[i] < a2[i])
            return false;
    }
    return true;
}
// Fibonacci Numbers
//--------------------------------------------------------------------------------------------
string fib(int i)
{
    return (mem[i] != "") ? mem[i] : (mem[i] = sumBigInt(fib(i-1), fib(i-2)));
}
void fillFibVec()
{
    mem.fill("");
    mem[0] = "0"; mem[1] = "1";
    fib(MAX_SZ -1);
    fibVec.insert(fibVec.end(), mem.begin()+2, mem.end());
}
// Converting
//--------------------------------------------------------------------------------------------
string fibToInt(string a)
{
    string Int = "0";
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++)
        if(a[i] == '1')
            Int = sumBigInt(Int, fibVec[i]);
    return Int;
}
string intToFib(string Int)
{
    string Fib = "";
    bool b = false;
    for(int i = MAX_SZ -3; i >= 0; i--)
    {
        if(biggerOrEql(Int, fibVec[i]))
        {
            Int = subBigInt(Int, fibVec[i]);
            Fib.push_back('1');
            b = true;
        }
        else if(b)
            Fib.push_back('0');
    }
    return Fib;
}
//--------------------------------------------------------------------------------------------
int main()
{
//    freopen("D:\\input.txt", "r", stdin);
//    freopen("D:\\output.txt", "w", stdout);

    fillFibVec();

    bool b = false;
    for(string a1, a2; cin >> a1 >> a2;)
    {
        if(b) cout << endl;
        string ans = intToFib(sumBigInt(fibToInt(a1), fibToInt(a2)));
        cout << ((ans != "") ? ans : "0") << endl;
        b = true;
    }

    return 0;
}
