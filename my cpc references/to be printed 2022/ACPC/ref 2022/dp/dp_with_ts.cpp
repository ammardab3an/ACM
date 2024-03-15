// dp with ternary search

int arr[505];
int mem[505][505];
int vis[505][505], vid;

int go(int n, int m){
    
    if(m == 1) return arr[n];
    
    if(vis[n][m] == vid) 
        return mem[n][m];
    vis[n][m] = vid;    
    
    int l = 1;
    int r = n-m+1;
    
    auto f = [&](int i){
        return go(n-i, m-1) + arr[i];
    };
    
    int ans = min(f(l), f(r));
    
    while(r-l > 1){
        
        int mid = (l+r)/2;
        int ans1 = f(mid), ans2 = f(mid+1);
        if(ans1 > ans2){
            l = mid, ans = min(ans, ans2);
        }
        else{
            r = mid, ans = min(ans, ans1);
        }
    }
    
    return mem[n][m] = ans;
}

int32_t main(){
    
    int tt = 0;
    int t; cin >> t; while(t--){
        
        cout << "Case " << ++tt << ": " << endl;

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        
        vid++;
        int q; cin >> q; while(q--){
            
            int a, b;
            cin >> a >> b;
            
            if(a < b){
                cout << "impossible" << endl;
                continue;
            }
            
            int ans = go(a, b);
            cout << ans << endl;
        }
    }	
}
