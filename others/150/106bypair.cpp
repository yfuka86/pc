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
#include <bitset>
#include <numeric>
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define vi vector<int>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
void comp(vector<int>&a){ vector<int> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T>
void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename K, typename V>
void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T>
void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, W;
  cin >> N >> W;
  vector<ll> v(N), w(N);
  rep(i, N) cin >> v[i] >> w[i];

  vector<LP> dp;
  dp.pb(make_pair(0, 0));

  rep(i, N) {
    int prev_size = dp.size();
    rep(j, prev_size) dp.pb(make_pair(dp[j].first + w[i], dp[j].second + v[i]));
    sort(all(dp));

    // 枝刈り
    ll v_sofar = -1;
    for (auto itr = dp.begin(); itr != dp.end();) {
      LP lp = *itr;
      if (lp.second <= v_sofar || lp.first > W) {
        itr = dp.erase(itr);
      } else {
        v_sofar = lp.second; itr++;
      }
    }

    for (LP lp : dp) cout << lp.first << ":" << lp.second << " ";
    cout << "\n";
  }

  auto itr = upper_bound(all(dp), make_pair(W, LINF));
  itr--;
  cout << itr->second << "\n";
}

// sortの関係なのか、mapのパターンよりかなり遅くなってしまった
