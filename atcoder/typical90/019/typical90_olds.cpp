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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N; cin >> N;
  vl a(2 * N);
  rep(i, 2 * N) cin >> a[i];

  vector<vl> dp(2 * N + 1, vl(2 * N + 1, -1));

  function<ll(ll, ll)> calc = [&](ll start, ll end) -> ll {
    if (dp[start][end] != -1) return dp[start][end];
    if (end == start) return dp[start][end] = 0;
    if (end - start == 2) return dp[start][end] = abs(a[start] - a[end - 1]);

    ll mi = LINF;

    // Slow part once I came up with
    // for(int i = start; i < end; i += 2) {
    //   for(int j = i + 2; j <= end; j += 2) {
    //     if ((i - start) % 2 == 1 || (end - j) % 2 == 1) continue;
    //     chmin(mi, calc(start, i) + calc(j, end) + calc(i + 1, j - 1) + abs(a[i] - a[j - 1]));
    //   }
    // }

    chmin(mi, calc(start + 1, end - 1) + abs(a[start] - a[end - 1]));
    for(int i = start + 2; i < end; i += 2) {
      chmin(mi, calc(start, i) + calc(i, end));
    }

    return dp[start][end] = mi;
  };

  cout << calc(0, 2 * N) << "\n";
}


