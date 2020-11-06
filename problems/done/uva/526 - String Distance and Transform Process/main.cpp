// By AmmarDab3an - Aleppo University

#include<bits/stdc++.h>

using namespace std;

// Global Variables

const int MAX = 88;

string str0, str1;
int sz0, sz1;
int mem[MAX][MAX];

int best(int i, int j){

    if(i == sz0){
        return sz1 - j;
    }
    if(j == sz1){
        return sz0 - i;
    }

    int & ret = mem[i][j];
    if(ret != -1) return ret;

    if(str0[i] == str1[j])
        return ret = best(i+1, j+1);    // pass

    int stPath = 1 + best(i, j+1);      // add
    int ndPath = 1 + best(i+1, j);      // remove
    int rdPath = 1 + best(i+1, j+1);    // replace

    return ret = min(stPath, min(ndPath, rdPath));
}

int idx   = 1;
int shift = 0;

void printBest(int i, int j){

    if(i == sz0){
        for(int k = 0; k < sz1 - j; k++)
            cout << idx++ << " Insert " << i+k+1+shift << "," << str1[j+k] << endl;
        shift += sz1 - j;
        return;
    }
    if(j == sz1){
        for(int k = 0; k < sz0 - i; k++){
            cout << idx++ << " Delete " << i+k+1+shift << endl;
            shift--;
        }
        return;
    }

    if(str0[i] == str1[j]){
        printBest(i+1, j+1);    // pass
        return;
    }


    int stPath = 1 + best(i, j+1);      // add
    int ndPath = 1 + best(i+1, j);      // remove
    int rdPath = 1 + best(i+1, j+1);    // replace

    int optimal = best(i, j);

    if(optimal == stPath){
        cout << idx++ << " Insert " << i+1+shift << "," << str1[j] << endl;
        shift++;
        printBest(i, j+1);
    }
    else if(optimal == ndPath){
        cout << idx++ << " Delete " << i+1+shift << endl;
        shift--;
        printBest(i+1, j);
    }
    else{
        cout << idx++ << " Replace " << i+1+shift << "," << str1[j] << endl;
        printBest(i+1, j+1);
    }
}

int main(){

	ios::sync_with_stdio(0); cin.tie(0);

	while(cin >> str0 >> str1){

        sz0 = str0.size();
        sz1 = str1.size();

        memset(mem, -1, sizeof mem);
        cout << best(0, 0) << endl;

        idx = 1, shift = 0;
        printBest(0, 0);
        cout << endl;
	}
}
