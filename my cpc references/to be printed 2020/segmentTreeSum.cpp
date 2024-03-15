#include <iostream>

using namespace std;

const int N = 100;

int arr[N];
int seg[N << 2];

void build(int nd, int L, int R){

    if(L == R){
        seg[nd] = arr[L];
        return;
    }

    int mid = (L + R) >> 1;

    build(nd << 1, L, mid);
    build(nd << 1 | 1, mid+1, R);

    seg[nd] = seg[nd << 1] + seg[nd << 1 | 1];
}

void update(int nd, int L, int R, int idx, int val){

    if(L == R){
        seg[nd] = val;
        return;
    }

    int mid = (L + R) >> 1;
    if(idx <= mid)
        update(nd << 1, L, mid, idx, val);
    else
        update(nd << 1 | 1, mid+1, R, idx, val);

    seg[nd] = seg[nd << 1] + seg[nd << 1 | 1];
}

int query(int nd, int L, int R, int from, int to){
    if(to < L || R < from)
        return 0;
    
    if(from <= L && R <= to)
        return seg[nd];
    
    int mid = (L + R) >> 1;

    int leftAns  = query(nd << 1    ,   L  , mid, from, to);
    int rightAns = query(nd << 1 | 1, mid+1, R  , from, to);

    return leftAns + rightAns;
}

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    while(true){

        int fn;
        cout << "Enter fn : ";
        cin >> fn;

        switch(fn){
            case 0:
                return 0;

            case 1:
                int from, to;
                cout << "Enter from, to : ";
                cin >> from >> to;
                cout << "Ans = " << query(1, 1, n, from, to) << endl;
                break;

            case 2:
                int idx, val;
                cout << "Enter idx, val : ";
                cin >> idx >> val;
                update(1, 1, n, idx, val);
                cout << "Done" << endl;
                break;
        }
    }
}