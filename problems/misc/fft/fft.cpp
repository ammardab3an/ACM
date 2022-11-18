
const int NMAX = 6e5 + 10;
const int LOG_MAX = ceil(log2(double(NMAX)));

complex<double> pre_exp[2][(1 << LOG_MAX) + 1];

void fill_pre(){
    int mx = (1 << LOG_MAX) + 1;
    for(int i = 1; i < mx; i++){
        pre_exp[0][i] = exp(complex<double>(0, 2.0*PI/i));
        pre_exp[1][i] = exp(complex<double>(0, -2.0*PI/i));
    }
}

valarray<complex<double> > fft(const valarray<complex<double> > &x,int sign=-1)
{
    int N = x.size();
    
    if(N == 1){
        return x;
    }
        
    valarray<complex<double> > even = x[slice(0,N/2,2)];
    valarray<complex<double> > odd = x[slice(1,N/2,2)];
    
    even = fft(even, sign);
    odd = fft(odd, sign);
    
    valarray<complex<double> > X(N);
    complex<double> cm1=1, cm2=pre_exp[sign==-1][N];
    
    for(int k=0;k<N/2;k++){
        X[k] = even[k]+cm1*odd[k];
        X[k+N/2] = even[k]-cm1*odd[k];
        cm1 *= cm2;
    }
    
    return X;
}

valarray<complex<double> > inv_fft(const valarray<complex<double> > &x)
{
    complex<double> N=x.size();
    return fft(x,1)/N;
}

string mul(const string &a, const string &b){
    
    int deg_a = a.size()-1;
    int deg_b = b.size()-1;
    int res_deg = deg_a + deg_b;
    int res_sz = res_deg+1;
    
    res_sz = 1 << (int)ceil(log2(double(res_sz)));
    
    valarray<complex<double>> A(res_sz), B(res_sz);
    
    for(int i = 0; i < a.size(); i++){
        A[a.size()-1-i] = a[i]-'0';
    }
    for(int i = 0; i < b.size(); i++){
        B[b.size()-1-i] = b[i]-'0';
    }
    
    A = fft(A);
    B = fft(B);
    A *= B;
    A = inv_fft(A);
    
    string res;
    
    int cr = 0;
    for(int i = 0; i < A.size(); i++){
        
        int x = int(round(A[i].real())) + cr;
        cr = x / 10;
        x %= 10;
        
        res.push_back('0'+x);
    }
    res.push_back('0'+cr);
    
    while((res.size() > 1) && (res.back() == '0')) res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

int32_t main(){
    
    fastIO;
    
    fill_pre();
    
    int t; cin >> t; while(t--){
        string a, b;
        cin >> a >> b;
        cout << mul(a, b) << endl;
    }	
}
