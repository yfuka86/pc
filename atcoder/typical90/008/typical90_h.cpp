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
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
int ceil_pow2(int n) { int x = 0; while ((1U << x) < (unsigned int)(n)) x++; return x; }
void comp(vector<int>&a){ vector<int> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T>
void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T>
void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };
template<typename K, typename V>
void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

//------------------------------------------------------------------------------
const ll mod = 1000000007;
struct modint { int n; modint() :n(0) { ; } modint(ll m) { if (m < 0 || mod <= m) { m %= mod; if (m < 0)m += mod; } n = m; } operator int() { return n; } };
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

  ll N; string S;
  cin >> N >> S;

  vector<modint> atcoder(7, modint(0));
  vector<char> map = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

  rep_r(i, N) {
    rep(j, 7) {
      if (S[i] == map[j]) {
        if (j == 6) {
          atcoder[j] += modint(1);
        } else {
          atcoder[j] += atcoder[j + 1];
        }
      }
    }
  }
  cout << atcoder[0] << "\n";
}


