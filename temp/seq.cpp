// <= ならupper_bound、< ならlower_boundにする必要がある
ll get_lis(vector<ll> &a) {
	ll N = a.size(); vector<ll> dp(N, INF);
	for (ll i = 0; i < N; ++i) *upper_bound(dp.begin(), dp.begin() + N, a[i]) = a[i];
	return lower_bound(dp.begin(), dp.begin() + N, INF) - dp.begin();
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

template<typename T>
pair<typename vector<T>::iterator, typename vector<T>::iterator > max_successive(vector<T> &a) {
  ll c = 1; auto f = a.begin(), t = a.begin();
  for (auto itr = a.begin(); itr != a.end(); itr++) { if (itr - a.begin() > 0 && *itr == *(itr - 1)) { c++; } else c = 1; if (c > t - f) { t = itr + 1; f = t - c; } }
  return make_pair(f, t);
}

int lcs(string &s1, string &s2){
  vector<vector<int> > dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
  function<int(int, int)> rec = [&](int m, int n) -> int {
    if (dp[m][n] != -1) return dp[m][n];
    if (m == 0 || n == 0) return dp[m][n] = 0;
    if (s1[m - 1] == s2[n - 1]) return dp[m][n] = rec(m - 1, n - 1) + 1;
    return max(rec(m, n - 1), rec(m - 1, n));
  };
  return rec(s1.size(), s2.size());
}

// Rolling hash
const ll P_B = 17, P_M = 1e9 + 7;
vl bf(1e6 + 10, -1);
ll b_fact(ll p) {
  if (bf[p] == -1) { bf[0] = 1; rep(i, 1e6 + 9) bf[i + 1] = bf[i] * P_B % P_M; }
  return bf[p];
}

vl s_hash(vl& s) {
  vl h(s.size() + 1, 0);
  rep(i, s.size()) { h[i + 1] = (P_B * h[i] + s[i]) % P_M; }
  return h;
}

ll sub_hash(vl& h, ll l, ll r) {
  assert(0 <= l && l < r && r <= h.size());
  ll ret = h[r] - (b_fact(r - l) * h[l] % P_M); if (ret < 0) ret += P_M;
  return ret;
}
// ビット列を反転のインデックスのみで保持したいもの
struct Bitseq {
  vector<ll> ranges;
  Bitseq() : ranges(0) {}

  void invert(ll l, ll r) {
    assert(l < r);
    auto litr = lower_bound(all(ranges), l);
    if (litr == ranges.end()) { ranges.pb(l); } else {
      if (*litr == l) ranges.erase(litr); else ranges.insert(litr, l);
    }
    auto ritr = lower_bound(all(ranges), r);
    if (ritr == ranges.end()) { ranges.pb(r); } else {
      if (*ritr == r) ranges.erase(ritr); else ranges.insert(ritr, r);
    }
  }

  void on(ll l, ll r) {
    assert(l < r);
    auto litr = lower_bound(all(ranges), l); if (litr == ranges.end()) { ranges.pb(l); ranges.pb(r); return; }

    if ((litr - ranges.begin()) % 2 == 0) { litr = ranges.insert(litr, l); litr++; }
    auto ritr = upper_bound(all(ranges), r); ranges.insert(ritr, r);

    if (litr == ranges.end()) return;
    auto itr = ranges.erase(litr, ritr);
    if (ranges.size() % 2 == 1) ranges.erase(itr);
  }

  bool include(ll at) {
    auto itr = upper_bound(all(ranges), at);
    if (itr == ranges.end()) return false;
    return (itr - ranges.begin()) % 2 == 1;
  }
};
