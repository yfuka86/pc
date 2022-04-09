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
template<typename T, typename K> void coutbin(T a, K d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & 1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

const ll mod = 1000000007;
//------------------------------------------------------------------------------
template< int mod >
struct ModInt {
  int x; ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) { if((x += p.x) >= mod) x -= mod; return *this; }
  ModInt &operator-=(const ModInt &p) { if((x += mod - p.x) >= mod) x -= mod; return *this; }
  ModInt &operator*=(const ModInt &p) { x = (int) (1LL * x * p.x % mod); return *this; }
  ModInt &operator/=(const ModInt &p) { *this *= p.inverse(); return *this; }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const { int a = x, b = mod, u = 1, v = 0, t; while(b > 0) { t = a / b; swap(a -= t * b, b); swap(u -= t * v, v); } return ModInt(u); }
  ModInt pow(int64_t n) const { ModInt ret(1), mul(x); while(n > 0) { if(n & 1) ret *= mul; mul *= mul; n >>= 1; } return ret; }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) { int64_t t; is >> t; a = ModInt< mod >(t); return (is); }
  static int get_mod() { return mod; }
};
using modint = ModInt< mod >;
typedef vector<modint> vmi;
//------------------------------------------------------------------------------
const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = 1; for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * (i + 1); }
  factinv[max_n - 1] = modint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * (i + 1); } }
modint comb(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
modint combP(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, const ll &p = mod) { ll ret = 1; while(n > 0) { if(n & 1) (ret *= x) %= p; (x *= x) %= p; n >>= 1; } return ret; }
//------------------------------------------------------------------------------

bool check(ll j, ll &W, ll &S) {
  if (S >> (W - 1) & 1) return false;
  if (j != 0 && (S >> W & 1 || S & 1)) return false;
  if (j != W - 1 && S >> (W - 2) & 1) return false;
  return true;
}

void solve() {
  ll H, W; cin >> H >> W;
  vector<vb> c(H, vb(W, 1));
  rep(i, H) {
    string s; cin >> s;
    rep(j, W) if (s[j] == '#') c[i][j] = 0;
  }
  ll filter = (1 << (W + 1)) - 1;

  ll pos = 0;
  vl state; map<ll, ll> stateinv;
  function<void(ll)> dfs = [&](ll S) -> void {
    S &= filter;
    if (__builtin_popcount((S << 1) & S) > 1) return;
    if (stateinv.count(S)) return;

    state.pb(S);
    stateinv[S] = pos;
    pos++;

    dfs(S << 1 | 1);
    dfs(S << 1);
  };
  dfs(0);
  ll sc = state.size();

  vl ltr, tr, rtr, tr0;
  rep(i, sc) {
    ll S = state[i];
    tr0.pb(stateinv[S << 1 & filter]);
    ll n = stateinv[(S << 1 | 1) & filter];
    if (check(0, W, S)) ltr.pb(n); else ltr.pb(-1);
    if (check(1, W, S)) tr.pb(n); else tr.pb(-1);
    if (check(W - 1, W, S)) rtr.pb(n); else rtr.pb(-1);
  }


  // vector<vmi> dp(H * W, vmi(sc, 0));
  vmi dp(sc, 0);
  vmi dptemp(sc, 0);

  rep(i, H) {
    rep(j, W) {
      if (i == 0 && j == 0) {
        dp[0] = 1;
        dp[1] = c[0][0] ? 1 : 0;
        continue;
      }

      // ll next = i * W + j, now = next - 1;
      rep(sn, sc) {
        if (dp[sn] == 0) continue;
        ll S = state[sn];

        if (c[i][j]) {
          if (j == 0) {
            if (ltr[sn] != -1) dptemp[ltr[sn]] += dp[sn];
          } else if (j == W - 1) {
            if (rtr[sn] != -1) dptemp[rtr[sn]] += dp[sn];
          } else {
            if (tr[sn] != -1) dptemp[tr[sn]] += dp[sn];
          }
        }
        dptemp[tr0[sn]] += dp[sn];
      }

      dp = dptemp; dptemp.clear(); dptemp.resize(sc, 0);
    }
  }
  cout << accumulate(all(dp), (modint)0) << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; // cin >> t;
  while (t--) solve();
}
