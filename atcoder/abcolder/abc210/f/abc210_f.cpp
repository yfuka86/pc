#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <atcoder/twosat>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair

using namespace std;
using namespace atcoder;
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
  ll N; cin >> N;
  vl A(N), B(N);
  rep(i, N) { cin >> A[i] >> B[i]; }

  map<ll, vector<LP>> pmap;
  for(ll d = 2; d * d <= 2e6; d++) {
    rep(i, N) {
      if (A[i] % d == 0) {
        pmap[d].pb(mp(i, 0));
        while (A[i] % d == 0) A[i] /= d;
      }
      if (B[i] % d == 0) {
        pmap[d].pb(mp(i, 1));
        while (B[i] % d == 0) B[i] /= d;
      }
    }
  }
  rep(i, N) {
    if (A[i] != 1) pmap[A[i]].pb(mp(i, 0));
    if (B[i] != 1) pmap[B[i]].pb(mp(i, 1));
  }

  ll sum = 0;
  for(auto[prime, p]: pmap) if (p.size() > 1) sum += p.size();
  two_sat ts(N + sum);
  auto p_then_q = [&](ll p, ll q) { ts.add_clause(p, false, q, true); };
  auto notp_then_q = [&](ll p, ll q) { ts.add_clause(p, true, q, true); };
  auto p_q_incompatible = [&](ll p, ll q) { ts.add_clause(p, false, q, false); };
  auto notp_q_incompatible = [&](ll p, ll q) { ts.add_clause(p, true, q, false); };

  ll cur = N;
  // PiがfalseならA、trueならB
  for (auto[prime, p]: pmap) {
    if (p.size() == 1) continue;
    ll clause = p.size();

    // cout << prime << "\n";
    // rep(i, clause) {
    //   cout << p[i].first << ":" << p[i].second << " ";
    // }
    // cout << "\n";

    rep(i, clause) {
      auto [Pi, b] = p[i];
      ll Qi = cur + i;
      if (b) p_then_q(Pi, Qi); else notp_then_q(Pi, Qi);
      if (i > 0) { if (b) p_q_incompatible(Pi, Qi - 1); else notp_q_incompatible(Pi, Qi - 1); }
      if (i < clause - 1) p_then_q(Qi, Qi + 1);
    }
    cur += p.size();
  }

  if (ts.satisfiable()) {
    cout << "Yes" << "\n";
    // for (bool b: ts.answer()) {
    //   cout << b << "\n";
    // }
  } else {
    cout << "No" << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
