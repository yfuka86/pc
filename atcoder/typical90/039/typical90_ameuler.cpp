#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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
template< typename T = ll > struct Edge {
  int from, to; T cost; int idx; Edge() = default; Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}
  operator int() const { return to; } bool operator<(const struct Edge& other) const { return cost < other.cost; } };
template< typename T = ll > struct Graph {
  vector< vector< Edge< T > > > g; int es; Graph() = default; explicit Graph(int n) : g(n), es(0) {}
  size_t size() const { return g.size(); }
  void add_directed_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es++); }
  void add_edge(int from, int to, T cost = 1) { g[from].emplace_back(from, to, cost, es); g[to].emplace_back(to, from, cost, es++); }
  inline vector< Edge< T > > &operator[](const int &k) { return g[k]; } inline const vector< Edge< T > > &operator[](const int &k) const { return g[k]; } };
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


template< typename T = ll >
struct EulerTour : Graph<T> {
public:
  using Graph<T>::Graph; using Graph<T>::g; vector< int > in, out, dep, par, node, edge, edgew; WaveletMatrix<ll, 20> wmnode, wmedge;
  void build() {
    ll n = g.size(); in.assign(n, 0); out.assign(n, 0); dep.assign(n, -1); par.assign(n, 0); node.assign(n * 2 - 1, 0); edge.assign(n * 2 - 1, 0); edgew.assign(n * 2 - 1, 0);
    int t = 0; dfs(Edge<T>(-1, 0, 0), 0, t);
  }
  // int lca(int u, int v) const { for(;; v = par[head[v]]) { if(in[u] > in[v]) swap(u, v); if(head[u] == head[v]) return u; } }
  // int dist(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

private:
  void dfs(Edge<T> e, int d, int &cur) {
    int p = e.from, v = e.to; dep[v] = d; par[v] = p; node[cur] = v; edge[cur] = v; edgew[cur] = e.cost; in[v] = cur++;
    for(Edge<T> &next : g[v]) {
      if(next.to == p) continue;
      dfs(next, d + 1, cur);
      cur++;
    }
    out[v] = cur; node[cur] = v; edge[cur] = -e.to; edgew[cur] = -e.cost;
  }
};


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N; cin >> N;
  EulerTour<ll> G(N);
  rep(i, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    G.add_edge(a, b);
  }
  G.build();

  ll ans = 0;
  rep2(i, 1, N) {
    // その点を含む部分木の頂点数
    ll part = (G.out[i] - G.in[i]) / 2 + 1;
    // その点から頂点0へ遡る辺の寄与計算
    ans += (N - part) * part;
  }

  cout << ans << "\n";
}



