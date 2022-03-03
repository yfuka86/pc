#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>
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

const ll mod = 998244353;
using namespace atcoder;
using mint = modint998244353;
typedef vector<mint> vmi;

//------------------------------------------------------------------------------
const int max_n = 1 << 20;
mint fact[max_n], factinv[max_n];
void init_f() {
  fact[0] = 1; for (int i = 0; i < max_n - 1; i++) { fact[i + 1] = fact[i] * (i + 1); }
  factinv[max_n - 1] = mint(1) / fact[max_n - 1]; for (int i = max_n - 2; i >= 0; i--) { factinv[i] = factinv[i + 1] * (i + 1); } }
mint comb(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[b] * factinv[a - b]; }
mint combP(int a, int b) { if (a < 0 || b < 0 || a < b) return 0; return fact[a] * factinv[a - b]; }
//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, const ll &p = mod) { ll ret = 1; while(n > 0) { if(n & 1) (ret *= x) %= p; (x *= x) %= p; n >>= 1; } return ret; }
//------------------------------------------------------------------------------

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll R, G, B, K; cin >> R >> G >> B >> K;
  ll X, Y, Z; cin >> X >> Y >> Z;
  init_f();

  vmi rconv(R + G + B + 1, 0);
  vmi gconv(R + G + B + 1, 0);
  rep2(r, K - Y, R + 1) rconv[r] = comb(R, r);
  rep2(g, K - Z, G + 1) gconv[g] = comb(G, g);
  vmi rg = convolution(rconv, gconv);

  mint ans = 0;
  rep2(b, K - X, B + 1) {
    if (b > K) break;
    ans += rg[K - b] * comb(B, b);
  }
  cout << ans.val() << "\n";
}


