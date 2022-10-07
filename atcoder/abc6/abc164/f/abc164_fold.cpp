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
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> vvvl;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb;
const int INF = numeric_limits<int>::max() / 2 - 1e6; const ll LINF = LLONG_MAX / 2 - 1e6; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
vl dx = {1, 0, -1, 0}; vl dy = {0, -1, 0, 1};

template<class T> void flip(vector<vector<T>> &a) {
  rep(i, a.size()) rep(j,i) {
    swap(a[i][j], a[j][i]);
  }
}


void solve() {
  ll N; cin >> N;
  vvl s(2, vl(N, 0));
  vector<vector<ull>> val(2, vector<ull>(N, 0));
  rep(i, N) cin >> s[0][i];
  rep(i, N) cin >> s[1][i];
  rep(i, N) cin >> val[0][i];
  rep(i, N) cin >> val[1][i];
  function<vvl(ll)> bit = [&](ll b)-> vvl {
    vvl ret(N, vl(N, -1));
    vvl uv(2, vl(N, 0));
    rep(i, 2) rep(j, N) uv[i][j] = 1 & (val[i][j] >> b);

    rep(t, 2) {
      rep(i, N) {
        if (s[t][i]) {
          if (!uv[t][i]) rep(j, N) ret[i][j] = 0;
        } else {
          if (uv[t][i]) rep(j, N) ret[i][j] = 1;
        }
      }
      flip(ret);
    }

    rep(t, 2) {
      rep(i, N) {
        if (s[t][i]) {
          if (uv[t][i]) {
            rep(j, N) if (ret[i][j] == -1) { ret[i][j] = 1; break; }
          }
        }
      }
      flip(ret);
    }

    set<ll> iss, jss;
    rep(i, N) rep(j, N) if (ret[i][j] == -1) { iss.insert(i); jss.insert(j); }
    vl is, js;
    for (auto i: iss) is.pb(i);
    for (auto j: jss) js.pb(j);

    if (is.size() > 1 && js.size() > 1) {
      rep(i, is.size()) rep(j, js.size()) {
        ret[is[i]][js[j]] = (i + j) % 2;
      }
      return ret;
    }
    if (is.size() == 0 && js.size() == 0) return ret;

    if (is.size() == 1) {
      ll i = is[0];
      rep(jj, js.size()) {
        ll j = js[jj];
        if (s[1][j] && uv[1][j]) {
          ll ok = false;
          rep(ii, N) if (ret[ii][j]) { ok = true; break; }
          if (ok) {
            if (s[0][i] && uv[0][i]) ret[i][j] = 1; else ret[i][j] = 0;
          } else {
            ret[i][j] = 1;
          }
        }
      }
    } else {
      ll j = js[0];
      rep(ii, is.size()) {
        ll i = is[ii];
        if (s[0][i] && uv[0][i]) {
          ll ok = false;
          rep(jj, N) if (ret[i][jj]) { ok = true; break; }
          if (ok) {
            if (s[1][j] && uv[1][j]) ret[i][j] = 1; else ret[i][j] = 0;
          } else {
            ret[i][j] = 1;
          }
        }
      }
    }

    return ret;
  };

  vvl ans(N, vl(N, 0));
  rep(b, 64) {
    vvl bans = bit(b);
    // coutmatrix(bans);
    rep(i, N) rep(j, N) {
      ans[i][j] |= (bans[i][j] == 1 ? 1ull : 0ull) << b;
    }
  }
  rep(t, 2) {
    rep(i, N) {
      if (s[t][i]) {
        ull sum = 0;
        rep(j, N) sum |= ans[i][j];
        if (sum != val[t][i]) { cout << -1 << "\n"; return; }
      } else {
        ull sum = ans[i][0];
        rep2(j, 1, N) sum &= ans[i][j];
        if (sum != val[t][i]) { cout << -1 << "\n"; return; }
      }
    }
    flip(ans);
  }
  coutmatrix(ans);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) solve();
}
