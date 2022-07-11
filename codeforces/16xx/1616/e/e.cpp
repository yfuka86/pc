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

// ----------------------------------------------------------------------
template<typename T>
struct BIT {
  int n; vector<T> bit;
  BIT(int _n = 0) : n(_n), bit(n + 1) {}
  // sum of [0, i), 0 <= i <= n
  T sum(int i) { T s = 0; while (i > 0) { s += bit[i]; i -= i & -i; } return s;}
  // 0 <= i < n
  void add(int i, T x) { ++i; while (i <= n) { bit[i] += x; i += i & -i; } }
  //[l, r) 0 <= l < r < n
  T sum(int l, int r) { return sum(r) - sum(l); }
  // smallest i, sum(i) >= w, none -> n
  int lower_bound(T w) {
    if (w <= 0) return 0; int x = 0, l = 1; while (l * 2 <= n) l <<= 1;
    for (int k = l; k > 0; k /= 2) if (x + k <= n && bit[x + k] < w) { w -= bit[x + k]; x += k; }
    return x; }
};
// ----------------------------------------------------------------------

void solve() {
  ll n; cin >> n;
  string s1, s2; cin >> s1 >> s2;
  if (s1 < s2) { cout << "0" << "\n"; return; }
  ll mi = LINF;
  BIT<int> bs(n);
  map<char, queue<ll>> dict;
  rep(i, n) {
    dict[s1[i]].push(i);
  }

  ll sofar = 0;
  rep(i, n) {
    for (char c = 'a'; c < s2[i]; c++) {
      if (dict[c].empty()) continue;
      ll idx = dict[c].front();
      chmin(mi, sofar + idx - bs.sum(idx));
    }

    if (!dict[s2[i]].empty()) {
      ll idx = dict[s2[i]].front(); dict[s2[i]].pop();
      bs.add(idx, 1);
      sofar += idx - bs.sum(idx);
    } else break;
  }
  if (mi == LINF) cout << "-1" << "\n"; else cout << mi << "\n";
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



// void solve() {
//   ll n; cin >> n;
//   string s1, s2; cin >> s1 >> s2;
//   if (s1 < s2) { cout << "0" << "\n"; return; }
//   ll mi = LINF;

//   ll sofar = 0;
//   rep(i, n) {
//     if (s1[i] < s2[i]) { chmin(mi, sofar); break; }

//     rep2(j, i + 1, n) {
//       if (s1[j] < s2[i]) { chmin(mi, sofar + j - i); break; }
//     }

//     if (s1[i] > s2[i]) {
//       auto itrsame = find(s1.begin() + i + 1, s1.end(), s2[i]);
//       if (itrsame != s1.end()) {
//         sofar += (itrsame - s1.begin() - i);
//         s1.erase(itrsame);
//         s1.insert(s1.begin() + i, s2[i]);
//       } else break;
//     }
//     // cout << s1 << endl;
//   }
//   if (mi == LINF) cout << "-1" << "\n"; else cout << mi << "\n";
// }
