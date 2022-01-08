#pragma GCC optimize("Ofast")
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cassert>
#include <bitset>
#include <numeric>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max() / 3;
const ll LINF = LLONG_MAX / 3;
const double DINF = numeric_limits<double>::infinity();

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
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
const ll mod = 1000000007;
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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll H, W; cin >> H >> W;

  vector<vl> board(H, vl(W));
  rep(i, H) {
    string s; cin >> s;
    rep(j, W) board[i][j] = s[j] == '.' ? 0 : 1;
  }

  // vl states, put, noput;
  // rep(i, 1 << W + 1) {
  //   if (i & i << 1 == 0) states.pb(i);
  //   noput.pb(i << 1);
  //   if (i & 1 == 0) {
  //     put.pb(i << 1 & 1);
  //   } else {
  //     put.pb(-1);
  //   }
  // }
  // cout << states.size() << endl;

  vector<vmi> dp(H * W + 1, vmi(1 << (W + 1), modint(0)));

  int filter = 0; rep(i, W + 2) filter |= 1 << i;
  dp[0][0] = modint(1);
  rep2(i, 1, H * W + 1) {
    rep(j, 1 << (W + 1)) {
      // cout << i << endl;
      if ((j & j << 1) != 0) continue;

      bool available = true;
      if (i != H * W && board[i / W][i % W]) available = false;

      bool upleft = j >> W & 1;
      bool up = j >> (W - 1) & 1;
      bool upright = j >> (W - 2) & 1;
      bool left = j & 1;
      if (i % W == 0) { // 左端の場合
        if (up || upright) available = false;
      } else if ((i + 1) % W == 0) { // 右端の場合
        if (upleft || up || left) available = false;
      } else {
        if (upleft || up || upright || left) available = false;
      }

      if (available) {
        dp[i][(j << 1 & filter) | 1] += dp[i - 1][j];
      }
      dp[i][(j << 1 & filter)] += dp[i - 1][j];
    }
  }


  modint ans = accumulate(all(dp[H * W]), modint(0));

  cout << ans << "\n";
}


