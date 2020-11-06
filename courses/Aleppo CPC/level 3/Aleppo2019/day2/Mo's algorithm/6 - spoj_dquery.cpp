#include <bits/stdc++.h>

using namespace std;

struct query{
    int l,r,idx;
};
query Q[200202];
int c[1001001] , a[30300] , sol[200202] , n , q , sz ,ans=0;

bool cmp(query a,query b)
{
    if(a.l/sz==b.l/sz)return a.r<b.r;
    return a.l<b.l;
}

void add(int x)
{
    c[x]++;
    if(c[x]==1)ans++;
}
void del(int x)
{
    c[x]--;
    if(c[x]==0)ans--;
}

int main()
{
    scanf("%d",&n);
    sz=sqrt(n);
    for(int i=1; i<=n; i++)
        scanf("%d",a+i);
    scanf("%d",&q);
    for(int i=1; i<=q; i++)
    {
        scanf("%d %d",&Q[i].l,&Q[i].r);
        Q[i].idx=i;
    }
    sort(Q+1,Q+1+q,cmp);

    int ll=1,rr=0;
    for(int i=1; i<=q; i++)
    {
        int left=Q[i].l , right=Q[i].r;

        while(rr<right)
        {
            rr++;
            add(a[rr]);
        }
        while(rr>right)
        {
            del(a[rr]);
            rr--;
        }
        while(ll>left )
        {
            ll--;
            add(a[ll]);
        }
        while(ll<left )
        {
            del(a[ll]);
            ll++;
        }

        sol[Q[i].idx]=ans;
        //cout<<left<<" "<<right<<" "<<ans<<endl;
    }
    for(int i=1; i<=q; i++)
        printf("%d\n",sol[i]);

    return 0;
}
