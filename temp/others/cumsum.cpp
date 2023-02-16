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

template<typename T>
struct csum2d {
  int h, w, cur = 0; vector<vector<T>> a, asum;
  explicit csum2d(int _h, int _w): h(_h), w(_w), a(h, vector(w, T(0))), asum(h + 1, vector<T>(w + 1, T(0))) {}
  explicit csum2d(vector<vector<T>> &v): h(v.size()), w(v[0].size()) { a = v; asum.assign(h + 1, vector<T>(w + 1, T(0))); update_all(); }
  // 関数以外の代入禁止
  vector<T> &operator[](int k) { if (cur < k) for(int i = cur; i < k; ++i) update_column(i); return asum[k]; }
  void set(int x, int y, T k) { if (a[x][y] != k) chmin(cur, x); a[x][y] = k; }
  T query(int x1, int y1, int x2, int y2) { return asum[x2][y2] + asum[x1][y1] - asum[x1][y2] - asum[x2][y1]; }
  void update_column(int i) { for(int j = 0; j < w; ++j) asum[i + 1][j + 1] += asum[i + 1][j] + asum[i][j + 1] + a[i][j] - asum[i][j]; chmax(cur, i + 1); }
  void update_all() { for(int i = 0; i < h; ++i) update_column(i); }
};

template<typename T>
struct imos2d {
  int h, w; vector<vector<T>> a;
  imos2d(int _h, int _w): h(_h), w(_w) { a.assign(h + 1, vector<T>(w + 1, T(0))); }
  vector<T> &operator[](int k) { return a[k]; }
  void add(int x1, int y1, int x2, int y2, T x) {
    a[x1][y1] += x; a[x2][y2] += x; a[x1][y2] -= x; a[x2][y1] -= x;
  }
  void build() {
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) a[i + 1][j] += a[i][j];
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) a[i][j + 1] += a[i][j];
  }
};

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

