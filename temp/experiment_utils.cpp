void enum_check(ll N, ll from, ll to, function<bool(vl&)> check, bool inc = false) { // size, [from, to)
  to--; vl st(N, from);
  while (1) {
    assert(st.size() == N); if (!check(st)) break;
    while (st.size() && st.back() == to) st.pop_back(); if (st.size() == 0) break;
    st.back()++;
    while (st.size() < N) if (inc) st.pb(st.back()); else st.pb(from);
  }
}

struct Timer {
  private:
    chrono::high_resolution_clock::time_point start, end;

  public:
    Timer() { set(); }
    void set() { start = chrono::high_resolution_clock::now(); }
    int time() {
        end = chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    }
    bool before(double T) { return time() < (int)(T * 1000); }
    void print() { cerr << "elapsed time: " << (double)time() / 1000 << " sec" << endl; }
} timer;

// ダイクストラでの用法
// while(!que.empty() && timer.before(1.5)) {
// }
// if (!timer.before(1.5)) cout << "Infinity" << "\n";

vlp rand_tree(ll n) {
  RandGen rg; vl p = rg.vecperm(n); vlp ret;
  for (int i = 1; i < n; ++i) ret.pb({p[rg.l(0, i)], p[i]});
  return ret;
}

// 連結とは限らない && テストケース用O(N^2)
vlp rand_dag(ll n, ll m = -1) { RandGen rg;
  vlp ret; rep(i, n) rep(j, i + 1, n) ret.pb({i, j}); rg.shuffle(ret);
  if (m == -1) m = rg.l(0, n*(n-1)/2+1);
  while(ret.size() > m) ret.pop_back();
  return ret;
}

// 連結とは限らない && テストケース用O(N^2)
vlp rand_dg(ll n, ll m = -1) { RandGen rg;
  vlp ret; rep(i, n) rep(j, n) if (i != j) ret.pb({i, j}); rg.shuffle(ret);
  if (m == -1) m = rg.l(0, n*(n-1)+1);
  while(ret.size() > m) ret.pop_back();
  return ret;
}

vlp rand_undir_connected_graph(ll n, ll m) {
  assert(n - 1 <= m && m <= n * (n - 1) / 2);
  set<LP> S;
  for (auto p: rand_tree(n)) S.insert({p.fi, p.se});

  RandGen rg; vlp ret;
  if (n * (n - 1) / 4 < m) {
    vlp t;
    rep(v, n) rep(u, v) if (S.find({u, v}) == S.end()) t.pb({u, v});
    rg.shuffle(t); rep(i, m - n + 1) S.insert(t[i]);
  } else {
    while (S.size() < m) {
      ll u = rg.l(0, n), v = rg.l(0, n); if (u == v) continue;
      if (u > v) swap(u, v); S.insert({u, v});
    }
  }
  assert(S.size() == m);
  for (auto p: S) ret.pb(p);
  return ret;
}
