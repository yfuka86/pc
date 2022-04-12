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
typedef long long ll; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max() / 3;
const ll LINF = LLONG_MAX / 3;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template <class T> T POW(T x, int n) { T res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

LP subt(LP a, LP b) { return mp(a.first - b.first, a.second - b.second); }
ll crs(LP p1, LP p2) {
  return p1.first * p2.second - p1.second * p2.first;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N; cin >> N;
  vector<LP> c(N);
  rep(i, N) { ll x, y; cin >> x >> y; c[i] = mp(x, y); }
  sort(all(c));

  stack<LP> upper, lower;
  rep(i, N) {
    if (i == 0) { upper.push(c[i]); lower.push(c[i]); continue; }

    LP up, lp;
    do {
      up = upper.top(); upper.pop(); if (upper.size() == 0) break;
    } while (crs(subt(up, upper.top()), subt(c[i], up)) >= 0);
    upper.push(up); upper.push(c[i]);

    do {
      lp = lower.top(); lower.pop(); if (lower.size() == 0) break;
    } while (crs(subt(lp, lower.top()), subt(c[i], lp)) <= 0);
    lower.push(lp); lower.push(c[i]);
  }

  vector<LP> g;
  while(!upper.empty()) { g.pb(upper.top()); upper.pop(); }
  reverse(all(g));
  g.pop_back();
  while(!lower.empty()) { g.pb(lower.top()); lower.pop(); }

  // for (LP p: g) {
  //   cout << p.first << ":" << p.second << endl;
  // }

  ll S = 0, b = 0;
  rep(i, g.size() - 1) {
    S += (g[i].first - g[i + 1].first) * (g[i].second + g[i + 1].second);
    auto [x, y] = subt(g[i + 1], g[i]);
    b += gcd(x, y);
  }
  S = abs(S) / 2;

  cout << (S - b / 2 + 1) + b - c.size() << "\n";

  // vl miny;
  // auto litr = lv.begin();
  // auto uitr = uv.begin();
  // rep2(x, c[0].first, c.back().first) {
  //   auto [x1, y1] = *litr; auto [x2, y2] = *(litr + 1);
  //   if (x + 1 > x2) litr++;

  //   if (x2 - x1 == 0) {
  //     miny.pb(min(y1, y2));
  //   } else {
  //     miny.pb(y1 + ceil((y2 - y1) * (x - x1), x2 - x1));
  //   }
  // }
  // vl maxy;
  // rep2(x, c[0].first, c.back().first) {
  //   auto [x1, y1] = *uitr; auto [x2, y2] = *(uitr + 1);
  //   if (x + 1 > x2) uitr++;

  //   if (x2 - x1 == 0) {
  //     maxy.pb(max(y1, y2));
  //   } else {
  //     maxy.pb(y1 + floor((y2 - y1) * (x - x1), x2 - x1));
  //   }
  // }

  // ll ans = 1; // 最後のものだけ足しておく
  // rep(i, miny.size()) {
  //   // cout << maxy[i] << ":" << miny[i] << endl;
  //   ans += maxy[i] - miny[i] + 1;
  // }
  // cout << ans - c.size() << "\n";
}


