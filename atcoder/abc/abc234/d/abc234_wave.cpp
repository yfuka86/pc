#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = 0; i < d; i++) cout << (a >> d) & 1; cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

//-------------------------------------------------
struct SuccinctIndexableDictionary {
  size_t length, blocks; vector<unsigned> bit, sum;
  SuccinctIndexableDictionary() = default;
  SuccinctIndexableDictionary(size_t length) : length(length), blocks((length + 31) >> 5) {
    bit.assign(blocks, 0U); sum.assign(blocks, 0U); }

  void set(int k) { bit[k >> 5] |= 1U << (k & 31); }
  void build() { sum[0] = 0U; for(int i = 1; i < blocks; i++) { sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]); } }
  bool operator[](int k) { return (bool((bit[k >> 5] >> (k & 31)) & 1)); }
  int rank(int k) { return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1))); }
  int rank(bool val, int k) { return (val ? rank(k) : k - rank(k)); } };

template< typename T, int MAXLOG >
struct WaveletMatrix {
  size_t length; SuccinctIndexableDictionary matrix[MAXLOG]; int mid[MAXLOG]; WaveletMatrix() = default;
  WaveletMatrix(vector< T > v) : length(v.size()) { vector< T > l(length), r(length);
    for(int level = MAXLOG - 1; level >= 0; level--) {
      matrix[level] = SuccinctIndexableDictionary(length + 1); int left = 0, right = 0;
      for(int i = 0; i < length; i++) { if(((v[i] >> level) & 1)) { matrix[level].set(i); r[right++] = v[i]; } else { l[left++] = v[i]; } }
      mid[level] = left; matrix[level].build(); v.swap(l); for(int i = 0; i < right; i++) v[left + i] = r[i]; } }
  pair< int, int > succ(bool f, int l, int r, int level) { return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f, r) + mid[level] * f}; }
  // v[k]
  T access(int k) { T ret = 0; for(int level = MAXLOG - 1; level >= 0; level--) { bool f = matrix[level][k]; if(f) ret |= T(1) << level; k = matrix[level].rank(f, k) + mid[level] * f; } return ret; }
  T operator[](const int &k) { return access(k); }
  // count i s.t. (0 <= i < r) && v[i] == x
  int rank(const T &x, int r) { int l = 0; for(int level = MAXLOG - 1; level >= 0; level--) { tie(l, r) = succ((x >> level) & 1, l, r, level); } return r - l; }
  // k-th(0-indexed) smallest number in v[l,r)
  T kth_smallest(int l, int r, int k) { assert(0 <= k && k < r - l); T ret = 0;
    for(int level = MAXLOG - 1; level >= 0; level--) { int cnt = matrix[level].rank(false, r) - matrix[level].rank(false, l); bool f = cnt <= k; if(f) { ret |= T(1) << level; k -= cnt; } tie(l, r) = succ(f, l, r, level); } return ret; }
  // k-th(0-indexed) largest number in v[l,r)
  T kth_largest(int l, int r, int k) { return kth_smallest(l, r, r - l - k - 1); }
  // count i s.t. (l <= i < r) && (v[i] < upper)
  int range_freq(int l, int r, T upper) { int ret = 0; for(int level = MAXLOG - 1; level >= 0; level--) { bool f = ((upper >> level) & 1); if(f) ret += matrix[level].rank(false, r) - matrix[level].rank(false, l); tie(l, r) = succ(f, l, r, level); } return ret; }
  // count i s.t. (l <= i < r) && (lower <= v[i] < upper)
  int range_freq(int l, int r, T lower, T upper) { return range_freq(l, r, upper) - range_freq(l, r, lower); }
  // max v[i] s.t. (l <= i < r) && (v[i] < upper)
  T prev_value(int l, int r, T upper) { int cnt = range_freq(l, r, upper); return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1); }
  // min v[i] s.t. (l <= i < r) && (lower <= v[i])
  T next_value(int l, int r, T lower) { int cnt = range_freq(l, r, lower); return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt); } };

template< typename T, int MAXLOG >
struct CompressedWaveletMatrix {
  WaveletMatrix< int, MAXLOG > mat; vector< T > ys;
  CompressedWaveletMatrix(const vector< T > &v) : ys(v) { sort(begin(ys), end(ys)); ys.erase(unique(begin(ys), end(ys)), end(ys)); vector< int > t(v.size()); for(int i = 0; i < v.size(); i++) t[i] = get(v[i]); mat = WaveletMatrix< int, MAXLOG >(t); }
  inline int get(const T& x) { return lower_bound(begin(ys), end(ys), x) - begin(ys); }
  T access(int k) { return ys[mat.access(k)]; }
  T operator[](const int &k) { return access(k); }
  int rank(const T &x, int r) { auto pos = get(x); if(pos == ys.size() || ys[pos] != x) return 0; return mat.rank(pos, r); }
  T kth_smallest(int l, int r, int k) { return ys[mat.kth_smallest(l, r, k)]; }
  T kth_largest(int l, int r, int k) { return ys[mat.kth_largest(l, r, k)]; }
  int range_freq(int l, int r, T upper) { return mat.range_freq(l, r, get(upper)); }
  int range_freq(int l, int r, T lower, T upper) { return mat.range_freq(l, r, get(lower), get(upper)); }
  T prev_value(int l, int r, T upper) { auto ret = mat.prev_value(l, r, get(upper)); return ret == -1 ? T(-1) : ys[ret]; }
  T next_value(int l, int r, T lower) { auto ret = mat.next_value(l, r, get(lower)); return ret == -1 ? T(-1) : ys[ret]; } };

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, K; cin >> N >> K;
  vl p(N); rep(i, N) { cin >> p[i]; }

  CompressedWaveletMatrix<ll, 20> wm(p);

  rep2(i, K, N + 1) {
    cout << wm.kth_largest(0, i, K - 1) << "\n";
  }
}


