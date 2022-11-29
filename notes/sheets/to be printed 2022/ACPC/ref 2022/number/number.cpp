number theory functions

// liner sieve 

std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

// phi 

const int N = 10000000;
int lp[N + 1];
int phi[N + 1];
vector<int> pr;

void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

// mobius

const int NMAX = 1e5 + 10;

vector <int> prime;
bool not_prime[NMAX];
int mob[NMAX];

void mobius(int n = NMAX){
	
	for(int i = 2; i < n; i++){
		
		if(!not_prime[i]){
			prime.push_back(i);
			mob[i] = -1;
		}
		
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			
			not_prime[i * prime[j]] = true;
			
			if (i % prime[j] == 0){
				mob[i * prime[j]] = 0;
				break;	
			}
			else{
				mob[i * prime[j]] = mob[i] * mob[prime[j]];
			}
		}
	}	
}



// prime factors in logn

#define MAXN   100001
 
// stores smallest prime factor for every number
int spf[MAXN];
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

//  S(i,j) the number of ways to put i different elements into j sets and there are no empty set.
int mem[1010][1010];
int s(int i, int j){
    if(!i) return 0;
    if(j==1) return 1;
    int &ret = mem[i][j];
    if(ret+1) return ret;
    int st_path = s(i-1, j-1);
    int nd_path = mul(j, s(i-1, j));
    return ret = add(st_path, nd_path);
}



// Given an array a consisting of n positive integers, find the number of its coprime subsequences. Since the answer may be very large, print it modulo 109 + 7.

// Problem: F. Coprime Subsequences

int32_t main(){
 
	mobius();
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int ai;
		cin >> ai;	
		for(lli i = 1; i*i <= ai; i++) if(ai%i==0){
			cnt[i]++;
			if(i != (ai/i)) cnt[ai/i]++;
		}
	}
	int ans = 0;
	for(int i = 2; i <= 1e5; i++){
		int f = add(pow_exp(2, cnt[i]), -1);
		ans = add(ans, mul(mob[i], f));	
	}
	ans = add(add(pow_exp(2, n), -1), ans);	
	cout << ans << endl;
}