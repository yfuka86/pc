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

template<class T> ll lcs(vector<T> s1, vector<T> s2){
  ll n = s1.size(), m = s2.size();
  vvl dp(n + 1, vl(m + 1, 0));
  rep(i, n) rep(j, m) {
    if (s1[i] == s2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
    else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
  }
  return dp[n][m];
}

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

