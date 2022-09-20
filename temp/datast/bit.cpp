// ----------------------------------------------------------------------
template<typename T>
struct BIT {
  int n; vector<T> bit;
  BIT(int _n = 0) : n(_n), bit(n + 1) {}
  // sum of [0, i), 0 <= i <= n
  T sum(int i) { T s = 0; while (i > 0) { s += bit[i]; i -= i & -i; } return s;}
  // 0 <= i < n
  void add(int i, T x) { ++i; while (i <= n) { bit[i] += x; i += i & -i; } }
  //[l, r) 0 <= l < r < n
  T sum(int l, int r) { return sum(r) - sum(l); }
  // smallest i, sum(i) >= w, none -> n
  int lower_bound(T w) {
    if (w <= 0) return 0; int x = 0, l = 1; while (l * 2 <= n) l <<= 1;
    for (int k = l; k > 0; k /= 2) if (x + k <= n && bit[x + k] < w) { w -= bit[x + k]; x += k; }
    return x; }
};
// ----------------------------------------------------------------------
ll inv_num(vl& v) { // comp(v);
  BIT<int> bs(v.size()); ll ans = 0;
  rep(i, v.size()) { ans += i - bs.sum(v[i] + 1); bs.add(v[i], 1); } return ans; }
// ----------------------------------------------------------------------

template<typename T = ll>
struct RangeAdd: BIT<T> {
  RangeAdd(int _n = 0) : BIT<T>(_n) {}
  T get(int i) { return this->sum(i + 1); }
  void range_add(int l, int r, T x) {
    this->add(l, x); this->add(r, -x);
  }
};
