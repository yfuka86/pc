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
#define fi first
#define se second

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
  string str(ll l, vector<char> op) { vl fig = vecl(l, 0, op.size()); string s; rep(i, l) s.pb(op[fig[i]]); return s; }
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
ll binary_search(function<bool(ll)> check, ll ok, ll ng) { assert(check(ok)); while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template <class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }

template<typename T> void coutarray(vector<T>& v, int offset = 0, string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset) cout << v[i] + offset; else cout << v[i]; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v, int offset = 0) { rep(i, v.size()) { coutarray(v[i], offset); } }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T, typename S> void coutpair(pair<T, S> & p) { cout << p.first << " " << p.second << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
const string drul = "DRUL"; vl dx = {1, 0, -1, 0}; vl dy = {0, 1, 0, -1};

ll solve(ll N, vl a) {
  ll ans = -1; return ans;
}

ll naive(ll N, vl a) {
  ll ans = 1; return ans;
}

void compare() {
  RandGen rg; ll c = 0, loop = 10;
  while (true) { c++; if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll N = 10;
    vl a = rg.vecl(N, 1, 1e2);
    auto s = solve(N, a); auto n = naive(N, a);
    if (n != s) {
      cout << c << "times tried" << "\n";
      cout << N << "\n"; coutarray(a);
      cout << "solve: " << s << "\n";
      cout << "naive: " << n << "\n";
      break;
    }
  }
}

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

void solve() {
  ll N; cin >> N;
  Points p(N);
  rep(i, N) {
    ll x, y; cin >> x >> y; p[i] = {x, y};
  }

  ll ob = 0, right = 0;

  rep(i, N) {
    Points t; rep(j, N) if (i != j) t.pb(p[j] - p[i]);
    ArgumentSort(t);
    t.insert(t.end(), t.begin(), t.end());

    rep(j, N - 1) {
      t[j]

      ll over90 = binary_search([&](ll mid) {
        if (mid >= n) return true;
        if (dot(t[j], t[mid]) < 0) return true; else return false;
      }, j + N - 1, 0);
      ll less180 = binary_search([&](ll mid) {
        if (mid >= n) return true;
        if (dot(tfirst, t[mid]) > th) return true; else return false;
      }, n, 0);
    }

    ll obout = binary_search([&](ll mid) {
      if (mid >= n) return true;
      if (dot(tfirst, t[mid]) > th) return true; else return false;
    }, n, 0);
    ll ob = binary_search([&](ll mid) {
      if (mid >= n) return true;
      if (dot(tfirst, t[mid]) < 0) return true; else return false;
    }, n, 0);

    cout << (ll)tfirst.x << ":" << (ll)tfirst.y << "\n";
    cout << ob << "\n";
    ob += n - ob + 1;
    // right += ob - obin;
  }

  ll tot = N * (N - 1) * (N - 2) / 6;

  cout << tot - (ob + right) << " " << right << " " << ob << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(15);
  int t = 1; // cin >> t;
  while (t--) solve();
  // while (t--) compare();
}
