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

struct Segment {
  ll l, r, i;
};

void solve() {
  ll n;
  cin >> n;
  map<ll, Segment> lm, rm, lrm;
  ll minl=LINF, maxr=0;
  rep(i, n) {
    ll l, r, c; cin >> l >> r >> c;
    Segment s = {l, r, i};

    if (l <= minl) {
      if (l < minl) { lm.clear(); lrm.clear(); }
      minl = l;
      lm[c] = s;
    }
    if (r >= maxr) {
      if (r > maxr) { rm.clear(); lrm.clear(); }
      maxr = r;
      rm[c] = s;
    }

    if (r == maxr && l == minl) {
      lrm[c] = s;
    }

    ll single = lrm.size() > 0 ? lrm.begin()->first : LINF;
    ll mi = lm.begin()->first;
    ll ma = rm.begin()->first;

    if (mi + ma > single) {
      cout << single << "\n";
    } else {
      cout << mi + ma << "\n";
    }


    // auto litr = lp.begin();
    // vector<LP> lv = litr->second;
    // sort(all(lv));
    // LP anslp = lv[0];

    // auto ritr = rp.begin();
    // vector<LP> rv = ritr->second;
    // sort(all(rv));
    // LP ansrp = rv[0];

    // if (anslp.second == ansrp.second) {
    //   cout << anslp.first << "\n";
    // } else {
    //   cout << anslp.first + ansrp.first << "\n";
    // }
  }
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
