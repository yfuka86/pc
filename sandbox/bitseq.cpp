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

struct BitSeq {
  vector<ll> ranges;
  BitSeq() : ranges(0) {}
  // ビット列を反転のインデックスのみで保持したいもの

  void invert(ll l, ll r) {
    assert(l < r);
    auto litr = lower_bound(all(ranges), l);
    if (litr == ranges.end()) { ranges.pb(l); } else {
      if (*litr == l) ranges.erase(litr); else ranges.insert(litr, l);
    }
    auto ritr = lower_bound(all(ranges), r);
    if (ritr == ranges.end()) { ranges.pb(r); } else {
      if (*ritr == r) ranges.erase(ritr); else ranges.insert(ritr, r);
    }
  }

  void on(ll l, ll r) {
    assert(l < r);
    auto litr = lower_bound(all(ranges), l); if (litr == ranges.end()) { ranges.pb(l); ranges.pb(r); return; }

    if ((litr - ranges.begin()) % 2 == 0) { litr = ranges.insert(litr, l); litr++; }
    auto ritr = upper_bound(all(ranges), r); ranges.insert(ritr, r);

    if (litr == ranges.end()) return;
    auto itr = ranges.erase(litr, ritr);
    if (ranges.size() % 2 == 1) ranges.erase(itr);
  }

  bool include(ll at) {
    auto itr = upper_bound(all(ranges), at);
    if (itr == ranges.end()) return false;
    return (itr - ranges.begin()) % 2 == 1;
  }
};

void solve() {
  BitSeq bs;
  bs.on(5, 8);
  // coutarray(bs.ranges);
  bs.on(7, 10);
  coutarray(bs.ranges);
  bs.on(3, 6);
  coutarray(bs.ranges);
  bs.on(-1, 200);
  coutarray(bs.ranges);
  bs.on(160, 320);
  coutarray(bs.ranges);
  bs.invert(50, 270);
  coutarray(bs.ranges);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}

