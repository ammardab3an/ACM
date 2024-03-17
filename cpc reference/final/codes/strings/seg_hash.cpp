// seg hash

int n, m;
char str[2][NMAX];
int  seg[2][NMAX << 2];
int fast_power[NMAX];

void seg_build(int nd, int L, int R, bool k){

    if(L == R){
        seg[k][nd] = str[k][L] - 'a' + 1;
        return;
    }

    int mid = (L+R) >> 1;
    seg_build(nd << 1, L, mid, k);
    seg_build(nd << 1 | 1, mid+1, R, k);

    seg[k][nd] = (seg[k][nd << 1] + (fast_power[mid-L+1] * seg[k][nd << 1 | 1])%MOD)%MOD;
}

void seg_update(int nd, int L, int R, int idx, char val, bool k){

    if(L == R){
        str[k][L] = val;
        seg[k][nd] = str[k][L] - 'a' + 1;
        return;
    }

    int mid = (L+R) >> 1;

    if(idx <= mid)
        seg_update(nd << 1, L, mid, idx, val, k);
    else
        seg_update(nd << 1 | 1, mid+1, R, idx, val, k);

    seg[k][nd] = (seg[k][nd << 1] + (fast_power[mid-L+1] * seg[k][nd << 1 | 1])%MOD)%MOD;
}

int seg_query(int nd, int L, int R, int from, int to, bool k){

    if(to < L || R < from)
        return 0;

    if(from <= L && R <= to)
        return fast_power[L-from] * seg[k][nd];

    int mid = (L+R) >> 1;
    int leftAns  = seg_query(nd << 1, L, mid, from, to, k);
    int rightAns = seg_query(nd << 1 | 1, mid+1, R, from, to, k);

    return (leftAns + rightAns)%MOD;
}

int32_t main(){

    fastIO;

#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    fast_power[0] = 1;
    for(int i = 1; i < NMAX; i++){
        fast_power[i] = fast_power[i-1] * POW;
        fast_power[i] %= MOD;
    }

    int t; cin >> t; while(t--){

        cin >> n >> m;

        char tmp[n];
        cin >> tmp;

        strcpy(str[0]+1, tmp);
        reverse(tmp, tmp+n);
        strcpy(str[1]+1, tmp);

        seg_build(1, 1, n, 0);
        seg_build(1, 1, n, 1);

        while(m--){

            int k;
            cin >> k;

            if(k == 1){
                int idx; char c;
                cin >> idx >> c;
                seg_update(1, 1, n, idx, c, 0);
                seg_update(1, 1, n, n-idx+1, c, 1);
            }

            else{
                int l, r;
                cin >> l >> r;
                int a0 = seg_query(1, 1, n, l, r, 0);
                int a1 = seg_query(1, 1, n, n-r+1, n-l+1, 1);
                cout << (a0 == a1 ? "Adnan Wins" : "ARCNCD!") << endl;
            }
        }

    }
}

// nihad

ll power[4][1000005],prehash[4][1000006],md[2]={mod,mod+2},pr[2]={29,31};
string s[2];
void hashfun(int j){
    int p=pr[j%2],m=md[j%2],n=s[j/2].size();
    power[j][0]=1;
    prehash[j][0]=s[j/2][0]-'a'+1;
    for(int i=1; i<n; i++)
        power[j][i]=(power[j][i-1]*p)%m;
    for(int i=1; i<n; i++)
        prehash[j][i]=((prehash[j][i-1]*p)%m + (s[j/2][i]-'a'+1))%m;
}
int subhash(int j,int l,int r)
{
    int h=prehash[j][r],p=pr[j%2],m=md[j%2];
    if(l)
        h=(h-(prehash[j][l-1]*power[j][r-l+1])%m + m )%m;
    return h;
}
ll join(ll x,ll y,ll yl,int j){
    R (x*power[j][yl]+y)%md[j];
}