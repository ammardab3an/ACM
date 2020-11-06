#define Matrix vector< vector < long long > >
long long MOD=1000000007;
void Resize_Matrix(long long n , long long m , Matrix &M){
    M.clear();
    for(int j=0;j<n;j++) {
        M.push_back( vector< long long >() );
        M[j].resize(m);
        for(int i=0;i<m;i++) M[j][i]=0;
    }
}
Matrix Matrix_Multiplication(Matrix A , Matrix B){
    Matrix Ans; long long n , m;
    Resize_Matrix(n=A.size() , m=A[0].size() , Ans);
    for(long long j=0;j<n;j++){
        for(long long i=0;i<n;i++){
            Ans[j][i]=0;
            for(long long k=0;k<n;k++){
                Ans[j][i]+= A[j][k]*B[k][i];
                Ans[j][i]%=MOD;
            }
        }
    }
    
    return Ans;
}
Matrix Matrix_Exponentiation(Matrix M , long long power){
    if(power==1) { return M; }
    Matrix ret=Matrix_Exponentiation(M , power/2);
    ret=Matrix_Multiplication(ret , ret);
    if(power%2) ret=Matrix_Multiplication(ret , M);
    return ret;
}
