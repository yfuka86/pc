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
  ll N, P, K; cin >> N >> P >> K;
  vector<vl> A(N, vl(N)); rep(i, N) rep(j, N) cin >> A[i][j];

  vector<vector<map<ll, ll>>> c(N, vector<map<ll, ll>>(N));
  rep(i, N) rep(j, N) {
    if (A[i][j] == -1) {
      c[i][j][1] = 0;
    } else {
      c[i][j][0] = A[i][j];
    }
  }

  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        for (auto [x1, c1]: c[i][k]) {
          for (auto [x2, c2]: c[k][j]) {
            if (x1 + x2 > N) continue;
            if (!c[i][j].count(x1 + x2)) {
              c[i][j][x1 + x2] = c1 + c2;
            } else {
              chmin(c[i][j][x1 + x2], c1 + c2);
            }
          }
        }
      }
    }
  }

  map<ll, ll> ans;
  rep(i, N) {
    rep2(j, i + 1, N) {
      ll st = 0, en = 0;
      for (auto [x, c]: c[i][j]) {
        if (P - c < 0) continue;
        // cout << i << ":" << j << " x:" << x << "rem" << P - c << endl;
        if (x == 0) en = LINF; else chmax(en, (P - c) / x);
      }
      // cout << st << ":" << en << endl;
      ans[st]++;
      if (en != LINF) ans[en]--;
    }
  }
  // coutmap(ans);

  ll ansc = 0;
  ll cur = 0;
  ll sum = 0;
  for(auto [x, count]: ans) {
    if (sum == K) {
      ansc += x - cur;
    }
    sum += count;
    cur = x;
  }
  if (sum == K) cout << "Infinity" << "\n"; else cout << ansc << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
