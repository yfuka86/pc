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

//------------------------------------------------------------------------------
const ll mod = 998244353;
struct modint { int n; modint() :n(0) { ; } modint(ll m) { if (m < 0 || mod <= m) { m %= mod; if (m < 0)m += mod; } n = m; } operator int() { return n; } };
typedef vector<modint> vmi;
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) { if (n == 0) return modint(1); modint res = (a * a) ^ (n / 2); if (n % 2) res = res * a; return res; }
ll inv(ll a, ll p) { return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p); }
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
//------------------------------------------------------------------------------
const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = modint(1); for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * modint(i + 1); }
  factinv[max_n - 1] = modint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * modint(i + 1); } }
modint comb(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
modint combP(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, ll m = mod) {
  if (n < 0) { ll res = mod_pow(x, -n, m); return mod_pow(res, m - 2, m); }
  if (abs(x) >= m) x %= m; if (x < 0) x += m; if (x == 0) return 0;
  ll res = 1; while (n) { if (n & 1) res = res * x % m; x = x * x % m; n >>= 1; } return res; }
//------------------------------------------------------------------------------

modint combination(ll a, ll b) {
  modint n = modint(1);
  modint d = modint(1);
  rep(i, b) {
    n *= a - i;
    d *= i + 1;
  }
  return n / d;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, K; cin >> N >> K;
  vl a(N); rep(i, N) cin >> a[i];

  ll sum = accumulate(a.begin() + 1, a.end(), 0LL);
  if (sum >= a[0]) { cout << 0 << "\n"; return 0; }

  ll onenum = a[0] - K - sum;

  modint ans = modint(1);

  ll div = K - 1;

  ans *= combination(onenum + div, div);
  rep2(i, 1, N) {
    ans *= combination(a[i] + div, div);
  }
  cout << ans << "\n";
}


