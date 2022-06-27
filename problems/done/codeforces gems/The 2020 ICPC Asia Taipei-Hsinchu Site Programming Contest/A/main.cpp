#include <bits/stdc++.h>

using namespace std;

const int AMAX = 1e7;
bool vis[AMAX];
int a[4];

vector<int> tmp;
vector<int> calc_tmp;

void calc1(int i, int res){

    if(i==calc_tmp.size()){
        if(res >= 0){
            vis[res] = true;
        }
        return;
    }

    calc1(i+1, res+calc_tmp[i]);
    calc1(i+1, res-calc_tmp[i]);
}

void calc(int i){


    if(i==tmp.size()){
        calc1(0, 0);
        return;
    }

    calc_tmp.push_back(tmp[i]);
    calc(i+1);
    calc_tmp.pop_back();

    if(!calc_tmp.empty()){
        int tt = calc_tmp.back();
        calc_tmp.back() *= tmp[i];
        calc(i+1);
        calc_tmp.back() = tt;
    }
}

void go(int msk){

    if(!msk){
        if(tmp.size() > 1){
            calc(0);
        }
        return;
    }

    for(int i = 0; i < 4; i++) if((msk>>i)&1){

        // st_path
        tmp.push_back(a[i]);
        go(msk^(1<<i));
        tmp.pop_back();

        if(!tmp.empty()){
            int tt = tmp.back();
            tmp.back() *= 10;
            tmp.back() += a[i];
            go(msk^(1<<i));
            tmp.back() = tt;
        }
    }
}

int main()
{

    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }

    go((1<<4)-1);

    int cnt = 0;
    for(int i = 0; i < AMAX; i++){
        if(vis[i]){
//            cout << i << endl;
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
