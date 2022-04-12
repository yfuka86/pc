bool is_prime(long long N) {
  if (N == 1) return false; for (long long i = 2; i * i <= N; ++i) if (N % i == 0) return false; return true;
}

vector<ll> primes_below(const ll N) {
  vector<bool> is_prime(N + 1, true); for(ll i = 2; i * i <= N; i++) { if ((i > 2 && i % 2 == 0) || !is_prime[i]) continue; for(ll j = i * i; j <= N; j += i) is_prime[j] = false; }
  vector<ll> ret; for(ll i = 2; i <= N; i++) if (is_prime[i]) ret.emplace_back(i); return ret; }

map<long long, long long> prime_factorize(long long N) {
  map<long long, long long> res;
  for (long long a = 2; a * a <= N; ++a) { if (N % a != 0) continue; long long ex = 0; while (N % a == 0) { ++ex; N /= a; } res[a]= ex; }
  if (N != 1) res[N] = 1; return res; }

vector<long long> divisor(long long n) {
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++) { if (n % i == 0) { ret.push_back(i); if (i * i != n) ret.push_back(n / i); } }
  sort(ret.begin(), ret.end()); return ret; }

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

template<typename T> vector<T> m_map(vector<vector<T>>& l, vector<T>& r) {
  assert(l.size() > 0 || r.size() > 0); assert(l[0].size() == r.size()); vector<T> ans(l.size(), 0);
  for(int i = 0; i < l.size(); i++) for (int j = 0; j < r.size(); j++) ans[i] += l[i][j] * r[j]; return ans; }
template<typename T> vector<vector<T>> m_product(vector<vector<T>>& l, vector<vector<T>>& r) {
  assert(l.size() > 0 || r.size() > 0); assert(l[0].size() == r.size());
  vector<vector<T>> ans(l.size(), vector<T>(r[0].size(), 0));
  for(int i = 0; i < l.size(); i++) { assert(l[i].size() == l[0].size());
    for(int j = 0; j < r[0].size(); j++) for(int k = 0; k < l[0].size(); k++) { assert(r[k].size() == r[0].size()); ans[i][j] += l[i][k] * r[k][j]; }
  }
  return ans; }
template <typename T> T m_pow(T m, ll n) { T res = m; n--; for(; n; n >>= 1, m = m_product(m, m)) if(n & 1) res = m_product(res, m); return res; }

ll mex(vl& v) {
  set<ll> S; for(ll n: v) S.insert(n);
  ll ret = 0; while (S.find(ret) != S.end()) ret++;
  return ret; }

// mod.cppに依存している
// a^x ≡ b (mod. m) となる最小の正の整数 x を求める
ll mod_log(ll a, ll b, ll m) {
  a %= m; b %= m; ll sqrtm = sqrt_ceil(m);
  map<ll, ll> apow; ll rem = a;
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
