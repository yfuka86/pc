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

void solve() {
  ll n, m; cin >> n >> m;
  vector<vl> color(n, vl(m, 0));
  rep(i, n) rep(j, m) cin >> color[i][j];
  vector<pair<LP, ll>> ans;
  vector<vl> used(n, vl(m, 0));

  function<void(ll, ll)> dfs = [&](ll i, ll j) -> void {
    if (i == n - 1 || j == m - 1 || i < 0 || j < 0) return;
    if (used[i][j]) return;
    vl s = {color[i][j], color[i][j + 1], color[i + 1][j], color[i + 1][j + 1]};

    if (!(s[0] | s[1] | s[2] | s[3])) return;
    ll c = 0;
    rep(i, 4) if (c == 0) c = s[i];
    rep(i, 4) if (s[i] != 0 && s[i] != c) return;

    // cout << i << " " << j << " " << cur << endl;
    ans.pb(mp(mp(i, j), c));
    used[i][j] = 1;
    color[i][j] = 0;
    color[i][j + 1] = 0;
    color[i + 1][j] = 0;
    color[i + 1][j + 1] = 0;

    rep2(di, -1, 2) {
      rep2(dj, -1, 2) {
        ll ni = i + di;
        ll nj = j + dj;
        if (0 <= ni && ni < n-1 && 0 <= nj && nj < m-1) {
          if (used[ni][nj] == 0) {
            dfs(ni, nj);
          }
        }
      }
    }
  };
  rep(i, n) rep(j, m) { dfs(i, j); }
  rep(i, n) rep(j, m) if (color[i][j] != 0) { cout << "-1" << "\n"; return; }

  cout << ans.size() << "\n";
  reverse(all(ans));
  for(auto [c, color] : ans) {
    cout << c.first + 1 << " " << c.second + 1 << " " << color << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}

template<typename Q, typename A> A iquery(Q& q) {
  cout << "? " << q << "\n"; cout.flush();
  A a; cin >> a; return a;
}

template<typename A> void ianswer(A& a) {
  cout << "! " << a << "\n"; cout.flush();
}

