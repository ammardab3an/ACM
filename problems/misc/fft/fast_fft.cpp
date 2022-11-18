typedef complex<double> cd;

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

http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf

vector<pair<cd, cd>> fft_2_in_1(vector<cd> ab){
	
	int n = ab.size();
	
	fft(ab, false);
	
	vector<pair<cd, cd>> res(n);
	for(int i = 0; i < n; i++){
		int j = (n-i) & (n-1);
		res[i] = {
			((ab[i]+conj(ab[j]))/cd(2, 0)),
			((ab[i]-conj(ab[j]))/cd(0, 2))
		};
	}
	
	return res;
}


vector<cd> fft_2_in_1(vector<cd> &a, vector<cd> &b){
	
	int n = a.size()+b.size()-1;
	n = 1 << int(ceil(log2(double(n))));
	
	vector<cd> ab(n);
	for(int i = 0; i < a.size(); i++){
		ab[i].real(a[i].real());
	}
	for(int i = 0; i < b.size(); i++){
		ab[i].imag(b[i].real());
	}
	
	fft(ab, false);
	
	vector<cd> res(n);
	for(int i = 0; i < n; i++){
		int j = (n-i) & (n-1);
		res[i] = (ab[i]*ab[i] - conj(ab[j]*ab[j])) * cd(0, -0.25);
	}
	
	fft(res, true);
	
	return res;
}

