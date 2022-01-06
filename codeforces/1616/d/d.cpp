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
int ceil_pow2(int n) { int x = 0; while ((1U << x) < (unsigned int)(n)) x++; return x; }
int floor_pow2(int n) { int x = 0; while ((1U << (x + 1)) <= (unsigned int)(n)) x++; return x; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

void solve() {
  ll n; cin >> n;
  vl a(n); rep(i, n) cin >> a[i];
  ll x; cin >> x;
  vl asx(n); rep(i, n) asx[i] = a[i] - x;

  // vl S(n + 1, 0); rep(i, n) S[i + 1] = S[i] + a[i];
  // vl sx(n + 1, 0); rep(i, n) sx[i + 1] = x * (i + 1);

  ll last_ns = -1;
  ll ns_count = 0;
  ll min_sum = 0;

  rep(i, n) {
    if (i == last_ns + 1) { min_sum = asx[i]; continue; }

    min_sum = min(min_sum + asx[i], asx[i - 1] + asx[i]);
    if (min_sum < 0) {
      last_ns = i;
      ns_count++;
      // cout << i << ":" << min_sum << endl;
      min_sum = 0;
    }

    // rep2(j, last_ns + 1, i + 1) {
    //   if (i == j) continue;
    //   if (S[i + 1] - S[j] < sx[i + 1] - sx[j]) {
    //     last_ns = i;
    //     // cout << i << ":" << S[i + 1] - S[j] << " < " << sx[i + 1] - sx[j] << endl;
    //     ns_count++;
    //     break;
    //   }
    // }
  }
  cout << n - ns_count << "\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
