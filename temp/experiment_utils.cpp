void enum_check(ll N, ll from, ll to, function<bool(vl&)> check) { // size, [from, to)
  to--; vl st(N, from);
  while (1) {
    assert(st.size() == N); if (!check(st)) break;
    while (st.size() && st.back() == to) st.pop_back(); if (st.size() == 0) break;
    st.back()++; while (st.size() < N) st.pb(from);
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
