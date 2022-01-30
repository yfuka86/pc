#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
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
const int INF = numeric_limits<int>::max() / 3;
const ll LINF = LLONG_MAX / 3;
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

using namespace atcoder;
using S = ll;
using F = ll;

S op(S l, S r) { return max(l, r); }
S e() { return -1ll; }
S mapping(F l, S r) { if (l == -1) return r; else return max(l, r); }
F composition(F l, F r) { return max(l, r); }
F id() { return -1; }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll W, N; cin >> W >> N;
  vl L(N), R(N), V(N); rep(i, N) { cin >> L[i] >> R[i] >> V[i]; }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(W + 1);
  seg.apply(0, 0);

  rep(i, N) {
    vl dptemp(W + 1, -1);

    rep(k, W + 1) {
      if (k - L[i] < 0) continue;
      ll possiblemax = seg.prod(max(0ll, k - R[i]), k - L[i] + 1);
      if (possiblemax == -1) continue;
      dptemp[k] = possiblemax + V[i];
    }

    for(ll i = 0; i <= W; i++) {
      if (dptemp[i] == -1) continue;
      ll temp = i;
      while(i <= W && dptemp[i] == dptemp[i + 1]) {
        i++;
      }
      i++;
      // cout << temp << ":" << i << endl;
      seg.apply(temp, i, dptemp[temp]);
      i--;
    }

    // for (auto [i, value]: dptemp) {
    //   if (seg.get(i) < value) seg.apply(i, value);
    // }
    // if (W == 100) {
    //   rep(i, W + 1) {
    //     cout << seg.get(i) << " ";
    //   }
    //   cout << endl;
    // }
  }

  cout << seg.get(W) << "\n";
}


