
const double Pi = acos(-1.0);
struct cpx{
	double r, i;
	cpx(double _r = 0.0, double _i = 0.0){ r = _r, i = _i; }
	cpx operator+(const cpx &b){
		return cpx(r + b.r, i + b.i);
	}
	cpx operator-(const cpx &b){
		return cpx(r - b.r, i - b.i);
	}
	cpx operator * (const cpx &b){
		return cpx(r*b.r - i*b.i, r*b.i + i*b.r);
	}
};
void change(vector<cpx> &y){
	int ln = y.size();
	for (int i = 1, j = ln >> 1; i<ln - 1; i++){
		if (i<j)swap(y[i], y[j]);
		int k = ln >> 1;
		while (j >= k){
			j -= k;
			k >>= 1;
		}
		j += k;
	}
}
void fft(vector<cpx> &y, int on){
	change(y);
	int len = y.size();
	for (int m = 2; m <= len; m <<= 1){
		cpx wm(cos(-on * 2 * Pi / m), sin(-on * 2 * Pi / m));
		for (int k = 0; k<len; k += m){
			cpx w(1, 0);
			for (int j = 0; j<m / 2; j++){
				cpx u = y[k + j];
				cpx t = w*y[k + j + m / 2];
				y[k + j] = u + t;
				y[k + j + m / 2] = u - t;
				w = w*wm;
			}
		}
	}
	if (on == -1)for (int i = 0; i<len; i++)y[i].r /= len;
}
vector<int> mult(vector<int> &a, vector<int> &b){
	int len = 1;
	int la = a.size();
	int lb = b.size();
	while (len<la + lb) len <<= 1;
	vector<cpx> x1(len);
	vector<cpx> x2(len);
	for (int i = 0; i<la; i++) x1[i] = cpx(a[i], 0);
	for (int i = la; i<len; i++)x1[i] = cpx(0, 0);
	for (int i = 0; i<lb; i++)x2[i] = cpx(b[i], 0);
	for (int i = lb; i<len; i++)x2[i] = cpx(0, 0);
	fft(x1, 1); fft(x2, 1);
	for (int i = 0; i < len; i++) x1[i] = x1[i] * x2[i];
	fft(x1, -1);
	vector<int> sol(len);
	for (int i = 0; i<len; i++){
		sol[i] = round(x1[i].r);
		//sol[i] = int(x1[i].r + 0.5);
	}
}
