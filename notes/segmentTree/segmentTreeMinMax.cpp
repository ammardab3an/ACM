#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int N = 100;

int arr[N];
int seg[2][N << 2];

void build(int nd, int L, int R){
    
    if(L == R){
        seg[0][nd] = seg[1][nd] = arr[L];
        return;
    }

    int mid = (L + R) >> 1;
    build(nd << 1, L, mid);
    build(nd << 1 | 1, mid+1, R);
    
    seg[0][nd] = min(seg[0][nd << 1], seg[0][nd << 1 | 1]);
    seg[1][nd] = max(seg[1][nd << 1], seg[1][nd << 1 | 1]);
}

void update(int nd, int L, int R, int idx, int val){

    if(L == R){
        seg[0][nd] = seg[1][nd] = val;
        return;
    }

    int mid = (L + R) >> 1;

    if(idx <= mid)
        update(nd << 1, L, mid, idx, val);
    else
        update(nd << 1 | 1, mid+1, R, idx, val);

    seg[0][nd] = min(seg[0][nd << 1], seg[0][nd << 1 | 1]);
    seg[1][nd] = max(seg[1][nd << 1], seg[1][nd << 1 | 1]);
}

pii query(int nd, int L, int R, int from, int to){

    if(to < L || R < from)
        return {INT_MAX, INT_MIN};

    if(from <= L && R <= to)
        return {seg[0][nd], seg[1][nd]};

    int mid = (L + R) >> 1;
    pii leftAns = query(nd << 1, L, mid, from, to);
    pii rightAns = query(nd << 1 | 1, mid+1, R, from, to);

    return {min(leftAns.first, rightAns.first),
            max(leftAns.second, rightAns.second)};
}

int main(){

    int n;
    cout << "Enter n : ";
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
            {
				int from, to;
				cout << "Enter from, to : ";
				cin >> from >> to;
				pii ans = query(1, 1, n, from, to);
				cout << "Ans = " << ans.first << ' ' << ans.second << endl;
            }
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
