// ntt 

// mod = 2**k * c + 1
// ASSERT: root_pw(2**k) > 2*N

const int mod = 7340033;
const int root = 5;		// 2**c -> (2**k)th root
const int root_1 = 4404020;	// root inverse
const int root_pw = 1 << 20;	// 2**k (note: 2**k must be greater than N)

const int N = 2e5 + 5;
const int mod = 998244353;
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;

const int N = 2e5 + 5;
const int mod = 998244353;
const int root = 363395222;
const int root_1 = 704923114;
const int root_pw = 1 << 19;

// A[i] = mul(A[i], B[i])

void fft (vector<int> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		int nrev = pow_exp (n, mod-2);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}

