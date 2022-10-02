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
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

void solve() {
  ll N; cin >> N;
  vl a(N), b(N);
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];

  map<ll, ll> am, bm; rep(i, N) {am[a[i]]++; bm[b[i]]++; }
  if (am != bm) { cout << "No" << "\n"; return; }

  map<ll, vl> as; rep(i, N) {as[a[i]].pb(i); }
  for (auto [k, v]: as) {
    bool odd = false, even = false;
    for (ll i: v) {
      if (i % 2 == 0) even = true;
      if (i % 2 == 1) odd = true;
    }
    if (odd && even)  { cout << "Yes" << "\n"; return; }
  }

  rep(i, N - 3) {
    auto itr = find(all(a), b[i]);
    ll dist = itr - a.begin();
    a.erase(itr);
    if (dist % 2 != 0) swap(a[0], a[1]);
  }
  if (a.size() != 3) { cout << "No" << "\n"; return; }

  rep(i, 3) { a.pb(a[i]); }
  rep(i, 3) {
    if (a[i] == b[N - 3] && a[i + 1] == b[N - 2] && a[i + 2] == b[N - 1]) { cout << "Yes" << "\n"; return; }
  }
  cout << "No" << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
