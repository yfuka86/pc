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

Graph<ll> rand_tree(ll n) {
  RandGen rg; vl p = rg.vecperm(n); Graph<ll> G(n);
  for (int i = 1; i < n; ++i) G.add_edge(p[rg.l(0, i)], p[i]);
  return G;
}

