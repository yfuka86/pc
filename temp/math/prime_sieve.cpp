//-------------------------------------------------------
// https://atcoder.jp/contests/abc238/submissions/29086825
// https://cp-algorithms.com/algebra/prime-sieve-linear.html
struct PrimeSieve {
  int n; vector<bool> is_prime; vector<int> pr, mu, pf;
  // pr := primes, mu := moebius, pf[i] := smallest prime p s.t. p | i
  PrimeSieve(int _n){
    n = ++_n; is_prime.assign(n, true); mu.assign(n, 0); pf.assign(n, 0);
    is_prime[0] = is_prime[1] = false; mu[1] = 1;
    for (int i = 2; i < n; i++) {
      if (is_prime[i]) { pr.emplace_back(i); pf[i] = i; mu[i] = -1; }
      for (int p : pr) {
        if (ll(i) * p >= n) break;
        is_prime[i * p] = false; mu[i * p] = -mu[i]; pf[i * p] = p;
        if (i % p == 0) { mu[i * p] = 0; break; }
      }
    }
  }
  vector<pair<int, int>> factorize(int x) { assert(x < n); vector<pair<int, int>> res;
    while (pf[x] > 1) { int d = pf[x], c = 0; while (x % d == 0) { x /= d; c++; } res.emplace_back(d, c); }
    if (x != 1) res.emplace_back(x, 1); return res;
  }
  // not sorted [2..x]
  vector<int> divisors(int x) { assert(x < n); auto f = factorize(x); vector<int> res = { 1 };
    for (auto [p, c] : f) {
      vector<int> powp; powp.emplace_back(p); rep(i, c - 1) powp.emplace_back(powp.back() * p);
      for (int i = res.size() - 1; i >= 0; --i) for (int j = 0; j < c; ++j) res.emplace_back(res[i] * powp[j]);
    }
    res.erase(res.begin()); return res;
  }
};
