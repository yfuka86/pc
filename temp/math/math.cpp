// テンプレに入れた
// vl divisor(ll n) { vl ret; for (ll i = 1; i * i <= n; i++) { if (n % i == 0) { ret.pb(i); if (i * i != n) ret.pb(n / i); } } sort(all(ret)); return ret; }
// ll mex(vl& v) { ll n = v.size(); vb S(n + 1); for (auto a: v) if (a <= n) S[a] = 1; ll ret = 0; while (S[ret]) ret++; return ret; }

bool is_prime(long long N) { if (N == 1) return false; for (long long i = 2; i * i <= N; ++i) if (N % i == 0) return false; return true; }

vector<ll> primes_below(const ll N) {
  vector<bool> is_prime(N + 1, true); for(ll i = 2; i * i <= N; i++) { if ((i > 2 && i % 2 == 0) || !is_prime[i]) continue; for(ll j = i * i; j <= N; j += i) is_prime[j] = false; }
  vector<ll> ret; for(ll i = 2; i <= N; i++) if (is_prime[i]) ret.emplace_back(i); return ret; }

vl tortient_enum(const ll n) {
  vl ps = primes_below(n), ret(n + 1); iota(all(ret), 0);
  for (auto &p: ps) for (int i = 1; i * p <= n; ++i) ret[i * p] -= ret[i * p] / p;
  return ret;
}

map<ll, ll> prime_factorize(ll N) {
  map<ll, ll> res;
  for (ll a = 2; a * a <= N; ++a) { if (N % a != 0) continue; ll ex = 0; while (N % a == 0) { ++ex; N /= a; } res[a]= ex; }
  if (N != 1) res[N] = 1; return res; }

// ap + bq = gcd(a, b)
LP extGCD(ll a, ll b) {
  ll p11 = 1, p12 = 0, p21 = 0, p22 = 1;
  while (b) {
    ll s = a / b;
    // matrix{{0, 1}, {1, -s}}
    a -= s * b; swap(a, b);

    p11 -= s * p21; p12 -= s * p22;
    swap(p11, p21); swap(p12, p22);
  }
  return {p11, p12};
}

ull euler_phi(ull n) {
  ull ret = n;
  for(ll i = 2; i * i <= n; i++) if(n % i == 0) { ret -= ret / i; while(n % i == 0) n /= i; }
  if(n > 1) ret -= ret / n; return ret; }

// mod.cppに依存している
// a^x ≡ b (mod. m) となる最小の正の整数 x を求める
ll mod_log(ll a, ll b, ll m) {
  a %= m; b %= m; ll sqrtm = sqrtll(m).se;
  unordered_map<ll, ll> apow; ll rem = a;
  for(ll r = 1; r < sqrtm; ++r) {
    if (!apow.count(rem)) apow[rem] = r;
    (rem *= a) %= m;
  }

  ll A = mod_pow(mod_inv(a, m), sqrtm, m);
  rem = b;
  for(ll q = 0; q < sqrtm; ++q) {
    if (rem == 1 && q > 0) return q * sqrtm;
    else if (apow.count(rem)) return q * sqrtm + apow[rem];
    (rem *= A) %= m;
  }
  return -1;
}

vl fib(ll n) {
  assert(n >= 2 && n <= 103); vl f(n); f[0] = f[1] = 1;
  for (int i = 2; i < n; i++) f[i] = f[i - 1] + f[i - 2];
  return f;
}

// 速い素数列挙
vector<int> prime_enumerate(int N) {
  vector<bool> sieve(N / 3 + 1, 1);
  for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6 - d, i++) {
    if (!sieve[i]) continue;
    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,
             qe = sieve.size();
         q < qe; q += r = s - r)
      sieve[q] = 0;
  }
  vector<int> ret{2, 3};
  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)
    if (sieve[i]) ret.push_back(p);
  while (!ret.empty() && ret.back() > N) ret.pop_back();
  return ret;
}

// 等比数列などの和
mint geo_sum(mint a, mint r, ll sz) {
  if (sz == 0) return mint(0);
  if (sz == 1) return a;

  mint ret = 0;
  if (sz & 1) { ret += a; a *= r; }
  mint s = geo_sum(a, r, sz / 2);
  ret += s + r.pow(sz / 2) * s;
  return ret;
}

mint geo_lin_sum(mint a, int i, mint r, ll sz) {
  if (sz == 0) return mint(0);
  if (sz == 1) return a * i;

  mint ret = 0;
  if (sz & 1) { ret += a * i; a *= r; i++; }
  mint s = geo_lin_sum(a, i, r, sz / 2);
  ret += s + r.pow(sz / 2) * (s + geo_sum(a, r, sz / 2) * (sz / 2));
  return ret;
}
