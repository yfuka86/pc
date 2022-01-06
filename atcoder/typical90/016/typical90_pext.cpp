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
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

// ap + bq = gcd(a, b)
LP extGCD(ll a, ll b) {
  ll p11 = 1, p12 = 0, p21 = 0, p22 = 1;
  while (b) {
    ll s = a / b;
    // matrix{{0, 1}, {1, -s}}
    a -= s * b; swap(a, b);

    p11 -= s * p21; p12 -= s * p22;
    swap(p11, p21); swap(p12, p22);
  }
  return {p11, p12};
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N; vl coins(3);
  cin >> N;
  rep(i, 3) cin >> coins[i];
  sort(all(coins));

  ll ans = LINF;
  ll c2max = N / coins[2];
  ll gcdrem = gcd(coins[0], coins[1]);
  auto [c0, c1] = extGCD(coins[0], coins[1]);
  ll c0dg = coins[0] / gcdrem; ll c1dg = coins[1] / gcdrem;
  // cout << "c0dg:" << c0dg << "c1dg:" << c1dg << endl;

  rep(i, c2max + 1) {
    ll rem = N - coins[2] * i;
    if (i > ans) continue;
    if (rem % gcdrem == 0) {
      ll k = rem / gcdrem;
      ll c0tmp = c0 * k;
      ll c1tmp = c1 * k;
      // cout << k << " " << c0tmp << " " << c1tmp << endl;
      if (c0tmp >= 0) {
        ll d = c0tmp / c1dg;
        c0tmp -= d * c1dg;
        c1tmp += d * c0dg;
      } else {
        ll d = (-c0tmp + c1dg - 1) / c1dg;
        c0tmp += d * c1dg;
        c1tmp -= d * c0dg;
      }
      // cout << c0tmp << " " << c1tmp << endl;

      if (c0tmp < 0 || c1tmp < 0) continue;

      chmin(ans, c0tmp + c1tmp + i);
    }
  }
  cout << ans << "\n";
}


