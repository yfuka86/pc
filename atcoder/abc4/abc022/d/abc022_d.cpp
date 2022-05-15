#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define vlin(name,sz) vl name(sz); rep(i,sz) cin>>name[i];
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT3; typedef tuple<ll, ll, ll> LT4;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> vvvl;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb;
const int INF = numeric_limits<int>::max() / 2 - 1e6; const ll LINF = LLONG_MAX / 2 - 1e6; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
struct RandGen {
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll l(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  vl vecl(ll l, ll a, ll b) { ud d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
  vl vecperm(ll l) { vl perm(l); iota(all(perm), 1); random_shuffle(all(perm)); return perm; }
  string straz(ll l, ll a = 0, ll z = 26) { vl az = vecl(l, a, z); string s; rep(i, l) s.pb('a' + az[i]); return s; }
  string strnum(ll l, ll zero = 0, ll ten = 10) { vl zt = vecl(l, zero, ten); string s; rep(i, l) s.pb('0' + zt[i]); return s; }
};
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void uniq(vector<T>&a){ sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
template <class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }

template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
const string drul = "DRUL"; vl dx = {1, 0, -1, 0}; vl dy = {0, 1, 0, -1};
// https://nyaannyaan.github.io/library/geometry/integer-geometry.hpp

struct Point {
  using T = __int128_t;
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}
  Point &operator+=(const Point &p) { this->x += p.x; this->y += p.y; return *this; }
  Point &operator-=(const Point &p) { this->x -= p.x; this->y -= p.y; return *this; }

  int pos() const { if (y < 0) return -1; if (y == 0 && 0 <= x) return 0; return 1; }
  Point operator+(const Point &p) const { return Point(*this) += p; }
  Point operator-(const Point &p) const { return Point(*this) -= p; }
  Point operator-() const { return Point(-this->x, -this->y); }
  bool operator==(const Point &p) const { return x == p.x && y == p.y; }
  bool operator!=(const Point &p) const { return x != p.x || y != p.y; }
  bool operator<(const Point &p) const { return x == p.x ? y < p.y : x < p.x; }
  friend istream &operator>>(istream &is, Point &p) { long long x, y; is >> x >> y; p.x = x, p.y = y; return is; }
  friend ostream &operator<<(ostream &os, const Point &p) { os << (long long)(p.x) << " " << (long long)(p.y); return os; }
};
using Points = vector<Point>;

Point::T dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
Point::T cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

// sort by argument (-Pi ~ Pi)
void ArgumentSort(Points &v) {
  sort(begin(v), end(v), [](Point a, Point b) {
    if (a.pos() != b.pos()) return a.pos() < b.pos();
    return cross(a, b) > 0;
  });
}

// 1 ... counterclockwise / 0 straight / -1 clockwise
int ccw(const Point &a, const Point &b, const Point &c) {
  Point::T t = cross(b - a, c - a);
  return t < 0 ? -1 : t == 0 ? 0 : 1;
}

Points ConvexHull(const Points &ps) {
  int N = (int)ps.size();
  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);
  if (N <= 2) return ps;
  Points convex(2 * N);
  int k = 0;
  for (int i = 0; i < N; convex[k++] = ps[i++]) {
    while (k >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i]) <= 0) --k;
  }
  for (int i = N - 2, t = k + 1; i >= 0; convex[k++] = ps[i--]) {
    while (k >= t && ccw(convex[k - 2], convex[k - 1], ps[i]) <= 0) --k;
  }
  convex.resize(k - 1);
  return convex;
}

void solve() {
  ll N; cin >> N;
  Points A(N), B(N);
  rep(i, N) {
    ll x, y; cin >> x >> y; A[i] = {x,y};
  }
  rep(i, N) {
    ll x, y; cin >> x >> y; B[i] = {x,y};
  }

  // auto a = accumulate(all(A), Point{0, 0});
  // auto b = accumulate(all(B), Point{0, 0});

  // ld centax = (ld)a.x / N, centay = (ld)a.y / N;
  // ld centbx = (ld)b.x / N, centby = (ld)b.y / N;

  // ld amax = 0, bmax = 0;
  // rep(i, N) {
  //   chmax(amax, sqrt(pow(A[i].x - centax, 2) + pow(A[i].y - centay, 2)));
  //   chmax(bmax, sqrt(pow(B[i].x - centbx, 2) + pow(B[i].y - centby, 2)));
  // }
  // cout << fixed << setprecision(10) << bmax / amax << "\n";

  sort(all(A)); sort(all(B));
  Points cha = ConvexHull(A), chb = ConvexHull(B);

  ll SA = 0, SB = 0;
  rep(i, cha.size()) { SA += cross(cha[(i + 1) % cha.size()], cha[i]); }
  rep(i, chb.size()) { SB += cross(chb[(i + 1) % chb.size()], chb[i]); }
  SA = abs(SA); SB = abs(SB);
  cout << fixed << setprecision(10) << sqrt((ld)SB / SA) << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
