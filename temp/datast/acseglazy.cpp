//2021/12/22-ac----------------------------------------------------------------
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
  public:
  lazy_segtree() : lazy_segtree(0) {}
  explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
  explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) { log = ceil_pow2(_n); size = 1 << log; d = std::vector<S>(2 * size, e()); lz = std::vector<F>(size, id()); for (int i = 0; i < _n; i++) d[size + i] = v[i]; for (int i = size - 1; i >= 1; i--) update(i); }
  void set(int p, S x) { assert(0 <= p && p < _n); p += size; for (int i = log; i >= 1; i--) push(p >> i); d[p] = x; for (int i = 1; i <= log; i++) update(p >> i); }
  S get(int p) { assert(0 <= p && p < _n); p += size; for (int i = log; i >= 1; i--) push(p >> i); return d[p]; }
  S prod(int l, int r) { assert(0 <= l && l <= r && r <= _n); if (l == r) return e(); l += size; r += size; for (int i = log; i >= 1; i--) { if (((l >> i) << i) != l) push(l >> i); if (((r >> i) << i) != r) push((r - 1) >> i); } S sml = e(), smr = e();
    while (l < r) { if (l & 1) sml = op(sml, d[l++]); if (r & 1) smr = op(d[--r], smr); l >>= 1; r >>= 1; } return op(sml, smr); }
  S all_prod() { return d[1]; }
  void apply(int p, F f) { assert(0 <= p && p < _n); p += size; for (int i = log; i >= 1; i--) push(p >> i); d[p] = mapping(f, d[p]); for (int i = 1; i <= log; i++) update(p >> i); }
  void apply(int l, int r, F f) { assert(0 <= l && l <= r && r <= _n); if (l == r) return; l += size; r += size; for (int i = log; i >= 1; i--) { if (((l >> i) << i) != l) push(l >> i); if (((r >> i) << i) != r) push((r - 1) >> i); }
    { int l2 = l, r2 = r; while (l < r) { if (l & 1) all_apply(l++, f); if (r & 1) all_apply(--r, f); l >>= 1; r >>= 1; } l = l2; r = r2; } for (int i = 1; i <= log; i++) { if (((l >> i) << i) != l) update(l >> i); if (((r >> i) << i) != r) update((r - 1) >> i); } }
  template <bool (*g)(S)> int max_right(int l) { return max_right(l, [](S x) { return g(x); }); }
  template <class G> int max_right(int l, G g) { assert(0 <= l && l <= _n); assert(g(e())); if (l == _n) return _n; l += size; for (int i = log; i >= 1; i--) push(l >> i); S sm = e();
    do { while (l % 2 == 0) l >>= 1; if (!g(op(sm, d[l]))) { while (l < size) { push(l); l = (2 * l); if (g(op(sm, d[l]))) { sm = op(sm, d[l]); l++; } } return l - size; } sm = op(sm, d[l]); l++; } while ((l & -l) != l); return _n; }
  template <bool (*g)(S)> int min_left(int r) { return min_left(r, [](S x) { return g(x); }); }
  template <class G> int min_left(int r, G g) { assert(0 <= r && r <= _n); assert(g(e())); if (r == 0) return 0; r += size; for (int i = log; i >= 1; i--) push((r - 1) >> i); S sm = e();
    do { r--; while (r > 1 && (r % 2)) r >>= 1; if (!g(op(d[r], sm))) { while (r < size) { push(r); r = (2 * r + 1); if (g(op(d[r], sm))) { sm = op(d[r], sm); r--; } } return r + 1 - size; } sm = op(d[r], sm); } while ((r & -r) != r); return 0; }
  private:
  int _n, size, log; std::vector<S> d; std::vector<F> lz;
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) { d[k] = mapping(f, d[k]); if (k < size) lz[k] = composition(f, lz[k]); }
  void push(int k) { all_apply(2 * k, lz[k]); all_apply(2 * k + 1, lz[k]); lz[k] = id(); }
};

// テンプレ
struct S{ ll sz, sum; }; using F = ll;
S op(S l, S r) { return {}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { if (f == -1) return x; }
F composition(F f, F g) { if (f == -1) return g; else return f; }
F id() { return -1; }

// sum
struct S {ll sum, sz;}; using F = ll;
S op(S l, S r) { return {l.sum + r.sum, l.sz + r.sz}; }
S e() { return {0, 1}; }
S mapping(F f, S x) { return {x.sum + f * x.sz, x.sz}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }


// 区間min
using S = ll; using F = ll;
S op(S l, S r) { return min(l, r); }
S e() { return LINF; }
// update ver
S mapping(F f, S x) { return f != -1 ? f : x; }
F composition(F f, F g) { return f != -1 ? f : g; }
F id() { return -1; }
// chmin ver
S mapping(F f, S x) { return f != -1 ? min(f, x) : x; }
F composition(F f, F g) { if (f == -1) return g; if (g == -1) return f; return min(f, g); }
F id() { return -1; }

// sumのk乗(ma乗まで) 二項係数を使って展開している
const ll MA = 6;
using S = array<mint, MA>;
using F = ll;
S op(S l, S r) { rep(i, MA) l[i] += r[i]; return l; }
S e() { return {0, 0, 0, 0, 0, 0}; }
S mapping(F f, S x) {
  rep_r(i, 1, MA) {
    rep(j, i) {
      x[i] += x[j] * comb(i, j) * mint(f).pow(i - j); // ここをキャッシュすると早くなる
    }
  }
  return x;
}
F composition(F f, F g) { return f + g; }
F id() { return 0ll; }

// linear_functions sum seg from here
struct S {
  mint a, b, x; int len;
  mint val() { return a * x + b; }
};
struct F { mint a, b; };
S op(S l, S r) { return {0, l.val() + r.val(), l.x + r.x, l.len + r.len}; }
S e() { return {0, 0, 0, 0}; }
S mapping(F f, S s) { return {s.a + f.a, s.b + f.b * s.len, s.x, s.len}; }
F composition(F f, F g) { { return {f.a + g.a, f.b + g.b}; } }
F id() { return {0, 0}; }
// to here

lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
ll ans = seg.max_right<function<bool(S)>>(a,
  [&b](S x) {
    if (x.a == -1) return true;
    return x.a < b;
  }
);
//------------------------------------------------------------------------------

