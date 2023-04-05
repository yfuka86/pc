// テンプレに入れた
// vl divisor(ll n) { vl ret; for (ll i = 1; i * i <= n; i++) { if (n % i == 0) { ret.pb(i); if (i * i != n) ret.pb(n / i); } } sort(all(ret)); return ret; }
// ll mex(vl& v) { ll n = v.size(); vb S(n + 1); for (auto a: v) if (a <= n) S[a] = 1; ll ret = 0; while (S[ret]) ret++; return ret; }
// vl primes(const ll n) { vb isp(n + 1, true); for(ll i = 2; i * i <= n; i++) { if ((i > 2 && i % 2 == 0) || !isp[i]) continue; for(ll j = i * i; j <= n; j += i) isp[j] = 0; } vl ret; for(ll i = 2; i <= n; i++) if (isp[i]) ret.emplace_back(i); return ret; }
// vector<pair<ll, ll>> factorize(ll n) { vector<pair<ll, ll>> res; for (ll a = 2; a * a <= n; ++a) { if (n % a != 0) continue; ll ex = 0; while (n % a == 0) { ++ex; n /= a; } res.emplace_back(a, ex); } if (n != 1) res.emplace_back(n, 1); return res; }

bool is_prime(long long N) { if (N == 1) return false; for (long long i = 2; i * i <= N; ++i) if (N % i == 0) return false; return true; }
// tortient関数
vl tortient_enum(const ll n) {
  vl ps = primes_below(n), ret(n + 1); iota(all(ret), 0);
  for (auto &p: ps) for (int i = 1; i * p <= n; ++i) ret[i * p] -= ret[i * p] / p;
  return ret;
}
ull euler_phi(ull n) {
  ull ret = n;
  for(ll i = 2; i * i <= n; i++) if(n % i == 0) { ret -= ret / i; while(n % i == 0) n /= i; }
  if(n > 1) ret -= ret / n; return ret; }

// 商の列挙（√N）https://ei1333.github.io/luzhiled/snippets/math/quotient-range.html
template< typename T >
vector< pair< pair< T, T >, T > > quotient_range(T N) {
  T M;
  vector< pair< pair< T, T >, T > > ret;
  for(M = 1; M * M <= N; M++) {
    ret.emplace_back(make_pair(M, M), N / M);
  }
  for(T i = M; i >= 1; i--) {
    T L = N / (i + 1) + 1;
    T R = N / i;
    if(L <= R && ret.back().first.second < L) ret.emplace_back(make_pair(L, R), N / L);
  }
  return ret;
}

// k進数変換
vl basek(ll n, ll k) {
  assert(k > 1); vl ret;
  while (n) { ret.pb(n % k); n /= k; }
  return ret;
}
// 10進数に変換
ll kto10(vl v, ll k) {
  assert(k > 1); ll ret = 0, pk = 1;
  rep(i, v.size()) { ret += pk * v[i]; pk *= k; }
  return ret;
}

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

// 二点からマンハッタン距離の等しい点（二点のパリティが等しい場合のみ存在）
LP manhattan_samedist(LP p1, LP p2, ll dist) {
  auto [x1, y1] = p1;
  auto [x2, y2] = p2;
  ll dx = x2 - x1, dy = y2 - y1;
  bool swaped = false;
  if (abs(dx) > abs(dy)) { swap(dx, dy); swaped = true; }
  ll rem = dist * 2 - abs(dx) - abs(dy);
  // パリティチェック
  assert(rem > 0 && !(rem & 1));

  ll ddx = abs(dx) + rem / 2;
  ll ddy = dist - (abs(dx) + rem / 2);
  if (dx < 0) ddx = -ddx;
  if (dy < 0) ddy = -ddy;
  if (swaped) swap(ddx, ddy);

  return mp(x1 + ddx, y1 + ddy);
}

// 等比数列などの和 ABC129-F
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
