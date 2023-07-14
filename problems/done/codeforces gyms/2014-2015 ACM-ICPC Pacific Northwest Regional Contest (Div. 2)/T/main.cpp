#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define endl '\n'

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t; while(t--){

        string str;
        cin >> str;

        vector<bool> vis(10);
        for(auto c : str) if(isdigit(c)){
            vis[c-'0'] = true;
        }

        char op;
        string a, b, ans;
        bool a_neg = false;
        bool b_neg = false;
        bool ans_neg = false;

        if(str.front()=='-'){
            a_neg = true;
            str.erase(str.begin());
        }

        bool b0 = false;
        bool b1 = false;

        for(auto c : str){

            if(!isdigit(c) && c!='?'){

                if(c == '='){
                    b1 = true;
                }
                else{
                    if(b1){
                        ans_neg = true;
                    }
                    else if(!b0){
                        op = c;
                        b0 = true;
                    }
                    else{
                        assert(c=='-');
                        b_neg = true;
                    }
                }

                continue;
            }

            if(!b0){
                a.push_back(c);
            }
            else if(b0 && !b1){
                b.push_back(c);
            }
            else if(b1){
                ans.push_back(c);
            }
        }

        bool can_0 = true;

        for(auto ss : {a, b, ans}){
            if(ss.front()=='?' && ss.size()>1){
                can_0 = false;
            }
        }

        if(!can_0) vis[0] = true;

        auto calc = [&](int a, int b, char op){

            if(op=='+'){
                return a+b;
            }
            else if(op=='-'){
                return a-b;
            }
            else{
                return a*b;
            }
        };

        auto check = [&](int i)->bool{

            string na = a;
            string nb = b;
            string nans = ans;

            for(auto &c : na) if(c=='?') c = '0'+i;
            for(auto &c : nb) if(c=='?') c = '0'+i;
            for(auto &c : nans) if(c=='?') c = '0'+i;

            int ia = stoi(na);
            int ib = stoi(nb);
            int ians = stoi(nans);

            if(a_neg) ia *= -1;
            if(b_neg) ib *= -1;
            if(ans_neg) ians *= -1;

            if(calc(ia, ib, op)==ians){
                return true;
            }
            else{
                return false;
            }
        };

        int i_ans = -1;

        for(int i = 0; i < 10; i++) if(!vis[i]) {
            if(check(i)){
                i_ans = i;
                break;
            }
        }

        cout << i_ans << endl;
    }
}
