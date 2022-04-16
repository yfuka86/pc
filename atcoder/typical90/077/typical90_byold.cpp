#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <atcoder/maxflow>
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
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
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

using namespace atcoder;
vl dx = {1, 1, 0, -1, -1, -1, 0, 1};
vl dy = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
  ll N, T; cin >> N >> T;
  vector<LP> a(N), b(N);
  rep(i, N) {
    ll x, y; cin >> x >> y;
    a[i] = mp(x, y);
  }
  map<ll, map<ll, ll>> bmap;
  rep(i, N) {
    ll x, y; cin >> x >> y;
    b[i] = mp(x, y);
    bmap[x][y] = i;
  }

  mf_graph<ll> mf(N * 2 + 2);
  ll s = N * 2, g = N * 2 + 1;

  rep(i, N) {
    mf.add_edge(s, i, 1);
    mf.add_edge(N + i, g, 1);
  }

  rep(i, N) {
    rep(j, 8) {
      ll x = a[i].first + dx[j] * T;
      ll y = a[i].second + dy[j] * T;
      if (bmap[x].count(y)) {
        mf.add_edge(i, bmap[x][y] + N, 1);
      }
    }
  }

  if (mf.flow(s, g) == N) {
    cout << "Yes" << "\n";
    vector<LP> dv(8); rep(i, 8) dv[i] = mp(dx[i],dy[i]);
    vl dir(N);
    auto edges = mf.edges();

    for (auto e : edges) {
      if (e.from == s || e.to == g || e.flow == 0) continue;
      LP ai = a[e.from], bi = b[e.to - N];
      LP v = mp((bi.first - ai.first) / T, (bi.second - ai.second) / T);
      rep(i, 8) {
        if (dv[i] == v) { dir[e.from] = i + 1; break; }
      }
    }
    coutarray(dir);
  } else cout << "No" << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
