#include <bits/stdc++.h>

using namespace std;

const int N=1e7+10;

int n,m;
int p[N],sz[N];
vector<string>v;
string s;

int get_p(int x){
    if(x==p[x])return x;
    return p[x]=get_p(p[x]);
}

void join(int x,int y){
    x=get_p(x),y=get_p(y);
    if(x==y)return ;
    if(sz[x]>sz[y])p[y]=x,sz[x]+=sz[y];
    else p[x]=y,sz[y]+=sz[x];
}


void build_graph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool ok[4]={1,1,1,1};
            for(int k=0;k<m;k++){
                if(s[k]=='0')continue;
                if(v[i][(j+k)%m]=='1')ok[0]=ok[1]=ok[2]=ok[3]=0;
                if(v[i][(j+k+1)%m]=='1')ok[0]=0;
                if(v[i][(j+k-1+m)%m]=='1')ok[1]=0;
                if(i){
                    if(v[i-1][(j+k)%m]=='1')ok[2]=0;
                }else{
                    ok[2]=0;
                }
                if(i+1<n){
                    if(v[i+1][(j+k)%m]=='1')ok[3]=0;
                }else{
                    ok[3]=0;
                }
            }
            if(ok[0])join(i*m+j,i*m+(j+1)%m);
            if(ok[1])join(i*m+j,i*m+(j-1+m)%m);
            if(ok[2]&&i>0)join(i*m+j,(i-1)*m+j);
            if(ok[3]&&i+1<n)join(i*m+j,(i+1)*m+j);
        }
    }
}

int main()
{
    cin>>n>>m;
    v.clear();
    v.resize(n);
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    n++;
    v.emplace_back(string(m,'0'));
    for(int i=0;i<1e6;i++)p[i]=i,sz[i]=1;

    build_graph();
    bool ok=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int a=i,b=(n-1)*m+j;
                if(get_p(a)==get_p(b))ok=1;
        }
    }

    for(int i=0;i<1e6;i++)p[i]=i,sz[i]=1;
    reverse(s.begin(),s.end());
    build_graph();
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int a=i,b=(n-1)*m+j;
                if(get_p(a)==get_p(b))ok=1;
        }
    }

    if(ok==1)cout<<"Y";
    else cout<<"N";
    return 0;
}
