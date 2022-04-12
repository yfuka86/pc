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
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> vvvl;
typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max() / 2 - 10; const ll LINF = LLONG_MAX / 2 - 10; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
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
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};


// Rolling hash
const ll P_B = 17, P_M = 1e9 + 7;
vl bf(1e6 + 10, -1);
ll b_fact(ll p) {
  if (bf[p] == -1) { bf[0] = 1; rep(i, 1e6 + 9) bf[i + 1] = bf[i] * P_B % P_M; }
  return bf[p];
}

vl s_hash(vl& s) {
  vl h(s.size() + 1, 0);
  rep(i, s.size()) { h[i + 1] = (P_B * h[i] + s[i]) % P_M; }
  return h;
}

ll sub_hash(vl& h, ll l, ll r) {
  assert(0 <= l && l < r && r <= h.size());
  ll ret = h[r] - (b_fact(r - l) * h[l] % P_M); if (ret < 0) ret += P_M;
  return ret;
}

void solve() {
  ll N; cin >> N;
  string S, T; cin >> S >> T;
  vl s(N), t(N);

  string kind = "RGB";
  rep(i, N) rep(j, 3) {
    if (S[i] == kind[j]) s[i] = j;
    if (T[i] == kind[j]) t[i] = j;
  }

  vl sr = s, sg = s, sb = s;
  rep(i, N) {
    if (sr[i] == 1) sr[i] = 2; else if (sr[i] == 2) sr[i] = 1;
    if (sg[i] == 0) sg[i] = 2; else if (sg[i] == 2) sg[i] = 0;
    if (sb[i] == 0) sb[i] = 1; else if (sb[i] == 1) sb[i] = 0;
  }

  vvl sh = { s_hash(sr), s_hash(sg), s_hash(sb)};
  vl th = s_hash(t);
  ll ans = 0;

  rep2(r, 1, N + 1) {
    rep(i, 3) if (sub_hash(sh[i], 0, r) == sub_hash(th, N - r, N)) { ans++; break; }
  }
  rep2(r, 1, N) {
    rep(i, 3) if (sub_hash(th, 0, r) == sub_hash(sh[i], N - r, N)) { ans++; break; }
  }
  cout << ans << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
