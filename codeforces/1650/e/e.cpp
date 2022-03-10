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
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
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

void solve() {
  ll n, d; cin >> n >> d;
  vl a(n); rep(i, n) cin >> a[i];

  vl diff(n, 0);
  ll cur = 0;
  rep(i, n) { diff[i] = a[i] - 1 - cur; cur = a[i]; }
  ll lastdiff = d - a[n - 1];

  vector<LP> sorteddiff(n);
  rep(i, n) { sorteddiff[i] = mp(diff[i], i); }
  sort(all(sorteddiff));

  ll ok = 0, ng = d;
  while(ng - 1 > ok) {
    ll mid = (ok + ng) / 2;
    if (sorteddiff.size() > 2 && sorteddiff[2].first < mid) { ng = mid; continue; }

    auto [d0, d0i] = sorteddiff[0];
    auto [d1, d1i] = sorteddiff[1];
    if (d0 < mid && d1 < mid) {
      if (abs(d0i - d1i) != 1 || d0 + d1 + 1 < mid) { ng = mid; continue; }
      if (find_if(sorteddiff.begin() + 2, sorteddiff.end(), [&](LP diff){ return diff.first > mid * 2; }) != sorteddiff.end() || lastdiff > mid) { ok = mid; continue; }
      ng = mid; continue;
    }

    if (d0 < mid) {
      if (find_if(sorteddiff.begin() + 1, sorteddiff.end(), [&](LP diff){ return diff.first > mid * 2; }) != sorteddiff.end() || lastdiff > mid) { ok = mid; continue; }
      if (d0i > 0 && diff[d0i - 1] + d0 + 1 > mid * 2) { ok = mid; continue; }
      if (d0i < n - 1 && diff[d0i + 1] + d0 + 1 > mid * 2) { ok = mid; continue; }
      if (d0i == n - 1 && lastdiff + d0 + 1 > mid) { ok = mid; continue; }
      ng = mid; continue;
    }

    ok = mid;
  }

  cout << ok << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t; cin >> t;
  while (t--) solve();
}

using A = ll;
template<typename Q> A iquery(Q q, string str = "?") {
  cout << str <<  " " << q << "\n"; cout.flush();
  A a; cin >> a; return a;
}

template<typename A> void ianswer(A a) {
  cout << "! " << a << "\n"; cout.flush();
}
