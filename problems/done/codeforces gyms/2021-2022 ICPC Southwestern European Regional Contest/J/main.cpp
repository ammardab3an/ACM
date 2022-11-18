#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool can(int w, int h, int i){

    int rem = w%i;
    if(rem > 1) return 0;

    if(rem == 0){

        int h1 = h-1;
        rem = h1%i;
        if(rem > 1) return 0;

        // cout << "Here " << rem << endl;
        if(rem == 0){
            int w1 = w-1;
            rem = w1%i;
            if(rem > 1) return 0;
            if(rem == 1){
                return h1%i == 0;
            } else {
                return (h1-1)%i == 0;
            }

        } else {
            return (h1-1)%i == 0;
        }

    } else {

        rem = h%i;
        // cout << "here "<< i << endl;
        if(rem > 1) return 0;
        if(rem == 0){
            int w1 = w-1;
            rem = w1%i;
            if(rem > 1) return 0;

            if(rem == 1){
                return (h-1)%i == 0;
            } else {
                return (h-2)%i == 0;
            }

        } else {
            return (h-2)%i == 0;
        }

    }

}

int main()
{

    int t;
    scanf("%d", &t);
    while(t--){

        ll w, h;
        cin >> w >> h;

        if(w > h)swap(h, w);

        set<int> v;
        for(int i = 1; i*i <= w; i++){
            if(w%i == 0){
                v.insert(i);
                v.insert(w/i);
            } else if((w-1)%i == 0){
                v.insert(i);
                v.insert((w-1)/i);
            } else if((w-2)%i == 0){
                v.insert(i);
                v.insert((w-2)/i);
            }
        }
        v.insert(w-1);
        v.insert(w-2);

        vector<int> ans;

        for(int i : v){
            // cout << "i " << i << " and " << i << endl;
            if(can(w, h, i) || can(h, w, i)) ans.push_back(i);
        }

        printf("%d", (int)ans.size());

        for(int x : ans) printf(" %d", x);
        puts("");

    }

    return 0;
}
