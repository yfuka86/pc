#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max() / 3;
const ll LINF = LLONG_MAX / 3;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

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

using S = ll;
using F = ll;

S op(S l, S r) { return max(l, r); }
S e() { return 0ll; }
S mapping(F l, S r) { if (l == -1) return r; else return l; }
F composition(F l, F r) { return max(l, r); }
F id() { return -1; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll W, N; cin >> W >> N;

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(W + 1);

  rep(i, N) {
    ll l, r; cin >> l >> r; l--;
    ll next = seg.prod(l, r) + 1;
    cout << next << "\n";
    seg.apply(l, r, next);

    // if (W < 200) {
    //   rep(i, W) cout << seg.get(i) << " ";
    //   cout << endl;
    // }
  }
}


