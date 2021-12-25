bool is_prime(long long N) {
  if (N == 1) return false;
  for (long long i = 2; i * i <= N; ++i) if (N % i == 0) return false;
  return true;
}

vector<int> primes_below(const int N) {
  vector<bool> is_prime(N + 1, true);
  for(int i = 2; i * i <= N; i++) {
    if ((i > 2 && i % 2 == 0) || !is_prime[i])  continue;
    for(int j = i * i; j <= N; j += i) is_prime[j] = false;
  }
  vector<int> ret;
  for(int i = 2; i <= N; i++) if (is_prime[i]) ret.emplace_back(i);
  return ret;
}

vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0;
    while (N % a == 0) { ++ex; N /= a; }
    res.push_back({a, ex});
  }
  if (N != 1) res.push_back({N, 1});
  return res;
}

vector<long long> divisor(long long n) {
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b) swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
