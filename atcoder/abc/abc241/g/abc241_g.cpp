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
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
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

void solve() {
  ll N, M; cin >> N >> M;

  ll game = N * (N - 1) / 2;
  ll s = N + game;
  ll g = N + game + 1;

  vector<LP> finished(M);
  vl maxwin(N, N - 1);
  rep(i, M) {
    ll a, b; cin >> a >> b; a--; b--; finished[i] = mp(a, b);
    maxwin[b]--;
  }
  sort(all(finished));

  vector<LP> edges;
  ll c = 0;
  rep(i, N) {
    rep2(j, i + 1, N) {
      edges.pb(mp(s, c + N));
      if (binary_search(all(finished), mp(i, j))) {
        edges.pb(mp(c + N, i));
      } else if (binary_search(all(finished), mp(j, i))) {
        edges.pb(mp(c + N, j));
      } else {
        edges.pb(mp(c + N, i));
        edges.pb(mp(c + N, j));
      }
      c++;
    }
  }

  vl possible;
  rep(i, N) {
    mf_graph<ll> mf(N + game + 2);

    if (maxwin[i] == 0) continue;
    rep(j, N) {
      if (i == j) mf.add_edge(j, g, maxwin[i]); else mf.add_edge(j, g, maxwin[i] - 1);
    }
    for (auto [f, t]: edges) mf.add_edge(f, t, 1);
    if (mf.flow(s, g) == game) possible.pb(i + 1);
  }
  coutarray(possible);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
