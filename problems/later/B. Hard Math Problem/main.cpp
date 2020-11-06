#include<bits/stdc++.h>

using namespace std;

const int64_t L1D_CACHE_SIZE = 32768;

std::vector<int64_t> primes;
void segmented_sieve(int64_t limit)
{
  int64_t sqrt = (int64_t) std::sqrt(limit);
  int64_t segment_size = std::max(sqrt, L1D_CACHE_SIZE);
  int64_t count = (limit < 2) ? 0 : 1;

  // we sieve primes >= 3
  int64_t i = 3;
  int64_t n = 3;
  int64_t s = 3;

  std::vector<char> sieve(segment_size);
  std::vector<char> is_prime(sqrt + 1, true);
  std::vector<int64_t> multiples;

  for (int64_t low = 0; low <= limit; low += segment_size)
  {
    std::fill(sieve.begin(), sieve.end(), true);

    // current segment = [low, high]
    int64_t high = low + segment_size - 1;
    high = std::min(high, limit);

    // generate sieving primes using simple sieve of Eratosthenes
    for (; i * i <= high; i += 2)
      if (is_prime[i])
        for (int64_t j = i * i; j <= sqrt; j += i)
          is_prime[j] = false;

    // initialize sieving primes for segmented sieve
    for (; s * s <= high; s += 2)
    {
      if (is_prime[s])
      {
           primes.push_back(s);
        multiples.push_back(s * s - low);
      }
    }

    // sieve the current segment
    for (std::size_t i = 0; i < primes.size(); i++)
    {
      int64_t j = multiples[i];
      for (int64_t k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = false;
      multiples[i] = j - segment_size;
    }

    for (; n <= high; n += 2)
      if (sieve[n - low]) // n is a prime
        count++;
  }
}


//----------------------------------------------------------------------------------


int main()
{
    segmented_sieve(1e20);
    vector<long long>::iterator primeVecBegin = primes.begin(), primeVecEnd = primes.end();

    int T, N;
    map<int, pair<long long, long long> > mem;
    for(cin >> T; T; T--)
    {
        cin >> N;
        long long sum_a = 0, sum_b = 1;
        long long a, b, gcd;
        for(int i = N; i > 1; i--)
        {
            if(mem.count(i))
            {
                a = mem[i].first;
                b = mem[i].second;
            }
            else
            {
                a = primes[lower_bound(primeVecBegin, primeVecEnd, i) - primeVecBegin];
                b = primes[upper_bound(primeVecBegin, primeVecEnd, i) - primeVecBegin];

            }
            sum_a = sum_a * a * b + sum_b;
            sum_b = sum_b * a * b;
            gcd = __gcd(sum_a, sum_b);
            sum_a /= gcd;
            sum_b /= gcd;
        }

        mem[N] = {sum_a, sum_b};
        printf("%llu/%llu\n", sum_a, sum_b);
    }
    return 0;
}
