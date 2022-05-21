// 典型LIS
// <= ならupper_bound、< ならlower_boundにする必要がある
ll get_lis(vl &a) {
	ll N = a.size(); vl dp(N, LINF);
	for (ll i = 0; i < N; ++i) *upper_bound(all(dp), a[i]) = a[i];
	return lower_bound(all(dp), INF) - dp.begin();
}

// 典型部分列DP
vl subseq_num(vector<ll> &v, ll m = mod) {
  ll n = v.size(); map<ll, ll> lasti;
  vl dp(n + 1, 0), sum(n + 2, 0); dp[0] = 1; sum[1] = 1;
  rep(i, n) {
    dp[i] += sum[i] - sum[lasti[v[i]]]; if (dp[i] < 0) dp[i] += m;
    sum[i + 1] = (sum[i] + dp[i]) % m;
    lasti[v[i]] = i;
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

// 二次元累積和（一応）
vvl cumsum2d(vvl &a) {
  ll H = a.size(), W = a[0].size(); vvl sum(H + 1, vl(W + 1, 0));
  rep(i, H) rep(j, W) sum[i + 1][j + 1] += sum[i + 1][j] + sum[i][j + 1] + a[i][j] - sum[i][j];
  return sum;
}

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
