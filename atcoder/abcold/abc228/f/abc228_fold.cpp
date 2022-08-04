#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max(); const ll LINF = LLONG_MAX; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template <class T> T POW(T x, int n) { assert(n >= 0); T res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};

template <typename T, typename F>
struct SegmentTree2D {
 private:
  int id(int h, int w) { return h * 2 * W + w; }

 public:
  int H, W;
  vector<T> seg;
  const F f;
  const T I;

  SegmentTree2D(int h, int w, F _f, const T& i) : f(_f), I(i) { init(h, w); }

  void init(int h, int w) {
    H = W = 1;
    while (H < h) H <<= 1;
    while (W < w) W <<= 1;
    seg.assign(4 * H * W, I);
  }

  // build にのみ呼ぶ
  void set(int h, int w, const T& x) { seg[id(h + H, w + W)] = x; }

  void build() {
    // w in [W, 2W)
    for (int w = W; w < 2 * W; w++) {
      for (int h = H - 1; h; h--) {
        seg[id(h, w)] = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
      }
    }
    // h in [0, 2H)
    for (int h = 0; h < 2 * H; h++) {
      for (int w = W - 1; w; w--) {
        seg[id(h, w)] = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
      }
    }
  }

  T get(int h, int w) const { return seg[id(h + H, w + W)]; }
  T operator()(int h, int w) const { return seg[id(h + H, w + W)]; }

  void update(int h, int w, const T& x) {
    h += H, w += W;
    seg[id(h, w)] = x;
    for (int i = h >> 1; i; i >>= 1) {
      seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]);
    }
    for (; h; h >>= 1) {
      for (int j = w >> 1; j; j >>= 1) {
        seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);
      }
    }
  }

  T _inner_query(int h, int w1, int w2) {
    T res = I;
    for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
      if (w1 & 1) res = f(res, seg[id(h, w1)]), w1++;
      if (w2 & 1) --w2, res = f(res, seg[id(h, w2)]);
    }
    return res;
  }

  // [ (h1,w1), (h2,w2) ) 半開
  T query(int h1, int w1, int h2, int w2) {
    if (h1 >= h2 || w1 >= w2) return I;
    T res = I;
    h1 += H, h2 += H, w1 += W, w2 += W;
    for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
      if (h1 & 1) res = f(res, _inner_query(h1, w1, w2)), h1++;
      if (h2 & 1) --h2, res = f(res, _inner_query(h2, w1, w2));
    }
    return res;
  }
};


void solve() {
  ll H, W, h1, w1, h2, w2; cin >> H >> W >> h1 >> w1 >> h2 >> w2;

  if (h1 <= h2 && w1 <= w2) { cout << 0 << "\n"; return; }
  chmin(h2, h1); chmin(w2, w1);

  vvl a(H, vl(W, 0));
  rep(i, H) rep(j, W) cin >> a[i][j];
  vvl sum(H + 1, vl(W + 1, 0));
  rep(i, H) {
    rep(j, W) sum[i + 1][j + 1] += sum[i + 1][j] + sum[i][j + 1] + a[i][j] - sum[i][j];
  }

  SegmentTree2D seg(H - h2 + 1, W - w2 + 1, [](ll a, ll b) { return max(a, b); }, 0LL);
  rep(i, H - h2 + 1) {
    rep(j, W - w2 + 1) {
      seg.set(i, j, sum[i + h2][j + w2] + sum[i][j] - sum[i][j + w2] - sum[i + h2][j]);
    }
  }
  seg.build();
  // cout << seg.query(0, 0, H - h2 + 1, W - w2 + 1) << "\n";

  vvl t(H - h1 + 1, vl(W - w1 + 1, 0));
  rep(i, H - h1 + 1) {
    rep(j, W - w1 + 1) {
      t[i][j] = sum[i + h1][j + w1] + sum[i][j] - sum[i][j + w1] - sum[i + h1][j] - seg.query(i, j, i + h1 - h2 + 1, j + w1 - w2 + 1);
    }
  }

  ll tscore = 0; rep(i, H - h1 + 1) chmax(tscore, *max_element(all(t[i])));
  cout << tscore << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
