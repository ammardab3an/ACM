#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fr first
#define sc second
#define ll  long long
#define mp make_pair
#define mod 1000000007

using namespace std;

int n;
int per[200200];

int pr(int x){
    if(per[x] == x)return x;
    return per[x] = pr(per[x]);
}

char s[1010][1010];
vector<int>p[200200];

bool v[200200];
bool v1[200200];

bool ch(int x){
    if(v1[x])return 1;
    if(v[x])return 0;
    v[x] = 1;
    v1[x] = 1;
    for(int i=0 ;i <p[x].size() ; i++){
        if(ch(p[x][i]))return 1;
    }
    v1[x] = 0;
    return 0;
}

int res[1001000];
void top(int x){
    if(res[x])return ;
    int mx = 1;
    for(int i=0 ;i <p[x].size() ;i++){
        top(p[x][i]);
        mx= max(mx,res[p[x][i]]+1);
    }
    res[x] = mx;
}

int main()  {
    int n,m;
    cin>>n>>m;
    for(int i=0 ;i <=n+m+5; i++)per[i] =i;
    for(int i =0 ;i <n ;i ++){
        scanf("%s",s[i]);
        for(int j=0 ;j <m ;j ++){
            if(s[i][j] == '='){
                int x = i;
                int y = j+n;
                x = pr(x);
                y = pr(y);
                per[x] = y;
            }
        }
    }
    for(int i =0 ;i <n ;i ++){
        for(int j=0 ;j <m ;j ++){
            if(s[i][j] == '>'){
                p[pr(i)].push_back(pr(j+n));
            }
            else if(s[i][j] == '<'){

                p[pr(j+n)].push_back(pr(i));
            }
        }
    }

    for(int i=0 ;i <n+m ; i++){
        if(ch(pr(i))){
            cout<<"No\n";
            return 0;
        }
    }

    for(int i=0 ;i <n+m ; i++){
        top(i);
    }
    printf("Yes\n");
    for(int i=0 ;i <n ; i++){
        printf("%d ",res[pr(i)]);
    }
    printf("\n");
    for(int i=0 ;i <m ; i++){
        printf("%d ",res[pr(i+n)]);
    }

    return 0;
}
