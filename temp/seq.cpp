// 典型LIS
// <= ならupper_bound、< ならlower_boundにする必要がある
ll get_lis(vl &a) {
	ll N = a.size(); vl dp(N, LINF);
	for (ll i = 0; i < N; ++i) *upper_bound(all(dp), a[i]) = a[i];
	return lower_bound(all(dp), INF) - dp.begin();
}

// 典型部分列DP
vmi subseq_num(vector<ll> &v) {
  ll n = v.size(); map<ll, ll> lasti;
  vmi dp(n + 1, 0), sum(n + 2, 0); dp[0] = 1; sum[1] = 1;
  rep(i, n) {
    dp[i + 1] += sum[i + 1] - sum[lasti[v[i]]];
    sum[i + 2] = sum[i + 1] + dp[i + 1];
    lasti[v[i]] = i + 1;
  }
  return dp;
}

// 典型LCS
string lcs(string &s1, string &s2){
  ll s1n = s1.size(), s2n = s2.size();
  vvl dp(s1n + 1, vl(s2n + 1, 0));
  vector<vlp> dpfrom(s1n + 1, vlp(s2n + 1, {-1, -1}));
  rep(i, s1n) rep(j, s2n) {
    if (s1[i] == s2[j]) { dp[i + 1][j + 1] = dp[i][j] + 1; dpfrom[i + 1][j + 1] = {i, j};
    } else {
      dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]); dpfrom[i + 1][j + 1] = dp[i + 1][j] > dp[i][j + 1] ? mp(i + 1, j) : mp(i, j + 1);
    }
  }

  string s = ""; ll m = s1n, n = s2n;
  while (dpfrom[m][n].first >= 0) {
    if (dpfrom[m][n] == mp(m - 1, n - 1)) s.pb(s1[m - 1]);
    auto [tm, tn] = dpfrom[m][n]; m = tm; n = tn;
  }
  reverse(all(s)); return s;
}

// dpなど用差分更新累積和（更新範囲が限られてないとクエリO(n)）
template<typename T>
struct incr_csum {
  int n, upd = 1e9; vector<T> a, asum;
  explicit incr_csum(int _n): n(_n), a(n, T(0)), asum(n + 1, T(0)) {}
  explicit incr_csum(const vector<T> &v): n(v.size()) { a = v; asum(n + 1); update_all(); }
  // 関数以外の代入禁止
  T &operator[](int k) { if (upd != INF && upd < k) { for(int i = upd; i < k; ++i) asum[i + 1] = asum[i] + a[i]; upd = k; } return asum[k]; }
  T set(int k, T x) { if (a[k] != x) chmin(upd, k); return a[k] = x; }
  T add(int k, T x) { if (x != 0) chmin(upd, k); return a[k] += x; }
  T sum(int l, int r) { return (*this)[r] - (*this)[l]; }
  void update_all() { for(int i = 0; i < n; ++i) asum[i + 1] = asum[i] + a[i]; upd = -1; }
};


// 二次元累積和（一応）
vvl csum2d(vvl &a) {
  ll H = a.size(), W = a[0].size(); vvl sum(H + 1, vl(W + 1, 0));
  rep(i, H) rep(j, W) sum[i + 1][j + 1] += sum[i + 1][j] + sum[i][j + 1] + a[i][j] - sum[i][j];
  return sum;
}

// 三次元imos
struct imos3d {
  using tu = tuple<ll, ll, ll>; tu sz; v3l data;
  imos3d(tu s) { sz = s; auto [x, y, z] = sz; data.assign(x + 1, vvl(y + 1, vl(z + 1, 0))); }
  void add(int x, int y, int z, ll a) { data[x][y][z] += a; }
  void imos_add(tu p1, tu p2, ll a) {
    auto [x1, y1, z1] = p1; auto [x2, y2, z2] = p2;
    add(x1, y1, z1, a); add(x2, y1, z1, -a); add(x1, y2, z1, -a); add(x2, y2, z1, a);
    add(x1, y1, z2, -a); add(x2, y1, z2, a); add(x1, y2, z2, a); add(x2, y2, z2, -a);
  }
  void build() {
    auto [x, y, z] = sz;
    rep(i, x) rep(j, y) rep(k, z) data[i + 1][j][k] += data[i][j][k];
    rep(i, x) rep(j, y) rep(k, z) data[i][j + 1][k] += data[i][j][k];
    rep(i, x) rep(j, y) rep(k, z) data[i][j][k + 1] += data[i][j][k];
  }
};

// Reference:
// D. Gusfield,
// Algorithms on Strings, Trees, and Sequences: Computer Science and
// Computational Biology
template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
  int n = int(s.size());
  if (n == 0) return {};
  std::vector<int> z(n);
  z[0] = 0;
  for (int i = 1, j = 0; i < n; i++) {
    int& k = z[i];
    k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
    while (i + k < n && s[k] == s[i + k]) k++;
    if (j + z[j] < i + z[i]) j = i;
  }
  z[0] = n;
  return z;
}

std::vector<int> z_algorithm(const std::string& s) {
  int n = int(s.size());
  std::vector<int> s2(n);
  for (int i = 0; i < n; i++) {
    s2[i] = s[i];
  }
  return z_algorithm(s2);
}

vs split(string str, char del) {
  int cur = 0; vs res;
  while (cur < str.size()) {
    auto to = str.find(del, cur); if (to == string::npos) to = str.size();
    res.pb(str.substr(cur, to - cur));
    cur = to + 1;
  }
  return res;
}

vl manacher(const string &_s, bool even = false) {
  string s = "";
  if (even) { for(int i = 0; i < (int)_s.size(); ++i) { s.pb('$'); s.pb(_s[i]); } s.pb('$'); } else s = _s;
  ll n = s.size();
  vl radius(n); int i = 0, j = 0;
  while(i < n) {
    while(i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
    radius[i] = j;
    int k = 1;
    while(i - k >= 0 && i + k < n && k + radius[i - k] < j) {
      radius[i + k] = radius[i - k]; ++k;
    }
    i += k; j -= k;
  }
  if (even) { radius.erase(radius.begin()); radius.pop_back(); for(int i = 0; i < (int)radius.size(); ++i) --radius[i]; }
  return radius;
}
