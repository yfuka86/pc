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
const ll mod = 1000000007;

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

double adiff(double a1, double a2) {
  double diff = a1 >= a2 ? a1 - a2 : a2 - a1;
  return diff > 180 ? 360 - diff : diff;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N;
  cin >> N;
  vector<LP> V(N);
  rep(i, N) {
    ll x, y; cin >> x >> y;
    V[i] = make_pair(x, y);
  }

  double maangle = 0;
  rep(i, N) {
    vector<double> angles;
    rep(j, N) {
      if (i == j) continue;
      ll y = V[j].second - V[i].second;
      ll x = V[j].first - V[i].first;
      angles.pb(atan2(y, x) * (double)180 / M_PI);
    }
    sort(all(angles));
    rep(j, angles.size()) {
      double a = angles[j] >= 180 ? angles[j] - 180 : angles[j] + 180;
      ll idx = upper_bound(all(angles), a) - angles.begin();
      if (idx == angles.size()) idx = 0;
      double l = idx == 0 ? angles[angles.size() - 1] : angles[idx - 1];
      double r = angles[idx];

      // cout << idx << ":" << j << endl;
      // cout << adiff(l, angles[j]) << ":" << adiff(r, angles[j]) << endl;

      chmax(maangle, max(adiff(l, angles[j]), adiff(r, angles[j])));
    }
  }
  cout << fixed << setprecision(7) << maangle << "\n";
}


