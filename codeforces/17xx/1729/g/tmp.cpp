
// template<typename T>
// struct incr_csum {
//   int n, upd = -1; vector<T> a, asum;
//   explicit incr_csum(int _n): n(_n), a(n), asum(n + 1) {}
//   explicit incr_csum(const vector<T> &v): n(v.size()) { a = v; asum(n + 1); rep(i, n) asum[i + 1] = asum[i] + a[i]; }
//   T &operator[](int k) { if (upd != -1) { rep(i, upd, k) asum[i + 1] = asum[i] + a[i]; upd = k; } return asum[k]; }
//   T &operator[]=(int k, T x) { if (a[k] != x) chmin(upd, k); return a[k] = x; }
//   T &operator[]+=(int k) { if (x) chmin(upd, k) return a[k] += x; }
//   T sum(int l, int r) { return asum[r] - asum[l]; }
//   void update_all() { rep(i, n) asum[i + 1] = asum[i] + a[i]; upd = -1; }
// };