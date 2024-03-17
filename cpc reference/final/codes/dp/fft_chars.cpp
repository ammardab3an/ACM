// fft chars
// Problem: E. Dasha and cyclic table
 
const int NMAX = 400 + 10;

using cd = complex<double>;
void fft(vector<cd> & a, bool invert) {
	
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

int n, m, x, y;
string str[NMAX];
string pat[NMAX];
int pat_cnt[NMAX];
double phi[26];
cd ang_a[26];
cd ang_b[26];
vector<cd> tmp_a[NMAX];
vector<cd> tmp_b[NMAX];
bool good[NMAX][NMAX][NMAX];

int32_t main(){
    
    fastIO;
    
#ifdef LOCAL
    freopenI;
    freopenO;
#endif

    // freopen("name.in", "r", stdin);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
    	cin >> str[i];
    }
    
    cin >> x >> y;
    for(int i = 0; i < x; i++){
    	cin >> pat[i];
    }
    
    for(int i = 0; i < x; i++)
    for(int j = 0; j < y; j++) if(pat[i][j]=='?'){
    	pat_cnt[i] += 1;
    }
    
    for(int i = 0; i < 26; i++){
    	phi[i] = double(2*PI*i)/double(26);
    	ang_a[i] = cd(cos(phi[i]), sin(phi[i]));
    	ang_b[i] = cd(cos(phi[i]), -sin(phi[i]));
    }
    
    int sz_a = m;
    while(sz_a < y) sz_a += m;
    sz_a += m;
    
    int deg_a = sz_a-1;
    // int deg_b = y-1;
	int res_deg = deg_a;
	int res_sz = res_deg+1;
	res_sz = 1 << int(ceil(log2(double(res_sz))));
	
	for(int i = 0; i < n; i++){
		
		tmp_a[i] = vector<cd>(res_sz);
		
		for(int j = 0; j < sz_a; j++){
			tmp_a[i][j] = ang_a[str[i][j%m]-'a'];
		}
		
		fft(tmp_a[i], false);
	}
	
	for(int i = 0; i < x; i++){
		
		tmp_b[i] = vector<cd>(res_sz);
		
		for(int j = 0; j < y; j++) if(pat[i][y-j-1] != '?'){
			tmp_b[i][j] = ang_b[pat[i][y-j-1]-'a'];
		}
		
		fft(tmp_b[i], false);
	}
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < x; j++){
		
		vector<cd> A(res_sz);
		
    	for(int k = 0; k < res_sz; k++){
    		A[k] = tmp_a[i][k] * tmp_b[j][k];
    	}
    	
    	fft(A, true);
    	
    	for(int k = 0; k < m; k++) if(int(A[k+y-1].real() + EPS)+pat_cnt[j]==y){
    		good[i][k][j] = 1;
    	}		
	}
    
    for(int i = 0; i < n; i++){
    	
	    for(int j = 0; j < m; j++){
	    	
	    	bool cgood = true;
	    	
	    	for(int k = 0; k < x; k++){
	    		if(!good[(i+k)%n][j][k]){
	    			cgood = false;
	    			break;
	    		}
	    	}
	    	
	    	cout << cgood;
	    }
	    
	    cout << endl;
    }
}
