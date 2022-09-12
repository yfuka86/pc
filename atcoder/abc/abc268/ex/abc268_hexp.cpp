#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define vlin(name,sz,offset) vl name(sz); rep(i,sz){cin>>name[i]; name[i]-=offset;}
#define coutret(i) { cout << i << "\n"; return; }
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT; typedef tuple<ll, ll, ll, ll> LT4;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> v3l; typedef vector<v3l> v4l; typedef vector<v4l> v5l;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<LT> vlt; typedef vector<vlt> vvlt; typedef vector<LT4> vlt4; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb; typedef vector<vb> vvb;
template<typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> class infinity{ public: static constexpr T MAX=numeric_limits<T>::max(); static constexpr T MIN=numeric_limits<T>::min(); static constexpr T val=numeric_limits<T>::max()/2-1e6; static constexpr T mval=numeric_limits<T>::min()/2+1e6; };
const int INF = infinity<int>::val; const ll LINF = infinity<ll>::val; const ld DINF = infinity<ld>::val;

struct RandGen {
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll l(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  LP lp(ll a, ll b, bool rng = true) { ll x = l(a, b - 1), y = l(rng ? x + 1 : a, b - 1); return {x, y}; }
  vl vecl(ll n, ll a, ll b) { ud d(a, b - 1); vl ret(n); rep(i, n) ret[i] = d(mt); return ret; }
  vl vecperm(ll n, ll from = 0) { vl perm(n); iota(all(perm), from); shuffle(perm); return perm; }
  string str(ll n, string op) { vl fig = vecl(n, 0, op.size()); string s; rep(i, n) s.pb(op[fig[i]]); return s; }
  string straz(ll n, ll a = 0, ll z = 26) { vl az = vecl(n, a, z); string s; rep(i, n) s.pb('a' + az[i]); return s; }
  string strnum(ll n, ll zero = 0, ll ten = 10) { vl zt = vecl(n, zero, ten); string s; rep(i, n) s.pb('0' + zt[i]); return s; }
  template<typename T> void shuffle(vector<T> &a) { std::shuffle(all(a), mt); }
};

#define dout cout
template<typename T, typename=void> struct is_specialize:false_type{};
template<typename T> struct is_specialize<T, typename conditional<false,typename T::iterator, void>::type>:true_type{};
template<typename T> struct is_specialize<T, typename conditional<false,decltype(T::first), void>::type>:true_type{};
template<typename T> struct is_specialize<T, enable_if_t<is_integral<T>::value, void>>:true_type{};
void dump(const char &t) { dout<<t; } void dump(const string &t) { dout<<t; } void dump(const bool &t) { dout<<(t ? "true" : "false"); }
template<typename T, enable_if_t<!is_specialize<T>::value, nullptr_t> =nullptr> void dump(const T&t) { dout << t; }
template<typename T> void dump(const T&t, enable_if_t<is_integral<T>::value>* =nullptr) { string tmp;if(t==infinity<T>::val||t==infinity<T>::MAX)tmp="inf";if(is_signed<T>::value&&(t==infinity<T>::mval||t==infinity<T>::MIN))tmp="-inf";if(tmp.empty())tmp=to_string(t);dout<<tmp; }
template<typename T, typename U, typename V> void dump(const tuple<T, U, V>&t) { dout<<"("; dump(get<0>(t)); dout<<" "; dump(get<1>(t)); dout << " "; dump(get<2>(t)); dout << ")"; }
template<typename T,typename U> void dump(const pair<T,U>&);
template<typename T> void dump(const T&t, enable_if_t<!is_void<typename T::iterator>::value>* =nullptr) { dout << "{ "; for(auto it=t.begin();it!=t.end();){ dump(*it); dout << (++it==t.end() ? "" : " "); } dout<<" }"; }
template<typename T,typename U> void dump(const pair<T,U>&t) { dout<<"("; dump(t.first); dout<<" "; dump(t.second); dout << ")"; }
void trace() { dout << "\n"; } template<typename Head, typename... Tail> void trace(Head&&head, Tail&&... tail) { dump(head); if(sizeof...(tail)) dout<<", "; trace(forward<Tail>(tail)...); }
#ifdef ONLINE_JUDGE
#define debug(...) (void(0))
#else
#define debug(...) do {dout<<#__VA_ARGS__<<" = ";trace(__VA_ARGS__); } while(0)
#endif
template<typename T> void coutarray(vector<T>& v, int offset = 0, string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset) cout << v[i] + offset; else cout << v[i]; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v, int offset = 0) { rep(i, v.size()) { coutarray(v[i], offset); } }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<typename Q, typename A> void iquery(initializer_list<Q> q, A &a, string str = "? ") { cout << str; vector<Q> v(q); coutarray(v); cout.flush(); cin >> a; }
// template<typename Q, typename A> void iquery(initializer_list<Q> q, A &a, string str = "? ") { vector<Q> query(q); RandGen rg;
//   a = query[0] ? A() : A();
// }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll POW(__uint128_t x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template<typename T> ll digits(T n) { assert(n >= 0); ll ret = 0; while(n > 0) { ret++; n /= 10; } return ret; }
template<typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template<typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void uniq(vector<T>&a) { sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a) { vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
ll binary_search(function<bool(ll)> check, ll ok, ll ng) { assert(check(ok)); while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template<class T> vector<T> csum(vector<T> &a) { vl ret(a.size() + 1, 0); rep(i, a.size()) ret[i + 1] = ret[i] + a[i]; return ret; }
template<class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
bool is_palindrome(string s) { rep(i, (s.size() + 1) / 2) if (s[i] != s[s.size() - 1 - i]) { return false; } return true; }
const string drul = "DRUL"; vl dx = {1, 0, -1, 0}; vl dy = {0, 1, 0, -1};

//https://ei1333.github.io/library/structure/trie/trie.hpp
template < int char_size >
struct TrieNode {
  int nxt[char_size];

  int exist;
  vector< int > accept;

  TrieNode(): exist(0) {
    memset(nxt, -1, sizeof(nxt));
  }
};

template < int char_size, int margin >
struct Trie {
  using Node = TrieNode< char_size >;

  vector< Node > nodes;
  int root;

  Trie(): root(0) {
    nodes.push_back(Node());
  }

  void update_direct(int node, int id) {
    nodes[node].accept.push_back(id);
  }

  void update_child(int node, int child, int id) {
    ++nodes[node].exist;
  }

  void add(const string &str, int str_index, int node_index, int id) {
    if (str_index == str.size()) {
      update_direct(node_index, id);
    } else {
      const int c = str[str_index] - margin;
      if (nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int)nodes.size();
        nodes.push_back(Node());
      }
      add(str, str_index + 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const string &str, int id) {
    add(str, 0, 0, id);
  }

  void add(const string &str) {
    add(str, nodes[0].exist);
  }

  void query(const string &str, const function< void(int) > &f,
             int str_index, int node_index) {
    for (auto &idx: nodes[node_index].accept) f(idx);
    if (str_index == str.size()) {
      return;
    } else {
      const int c = str[str_index] - margin;
      if (nodes[node_index].nxt[c] == -1) return;
      query(str, f, str_index + 1, nodes[node_index].nxt[c]);
    }
  }

  void query(const string &str, const function< void(int) > &f) {
    query(str, f, 0, 0);
  }

  int count() const {
    return (nodes[0].exist);
  }

  int size() const {
    return ((int)nodes.size());
  }
};
//https://ei1333.github.io/library/string/aho-corasick.hpp
template < int char_size, int margin >
struct AhoCorasick: Trie< char_size + 1, margin > {
  using Trie< char_size + 1, margin >::Trie;

  const int FAIL = char_size;
  vector< int > correct;

  void build(bool heavy = true) {
    correct.resize(this->size());
    for (int i = 0; i < this->size(); i++) {
      correct[i] = (int)this->nodes[i].accept.size();
    }
    queue< int > que;
    for (int i = 0; i <= char_size; i++) {
      if (~this->nodes[0].nxt[i]) {
        this->nodes[this->nodes[0].nxt[i]].nxt[FAIL] = 0;
        que.emplace(this->nodes[0].nxt[i]);
      } else {
        this->nodes[0].nxt[i] = 0;
      }
    }
    while (!que.empty()) {
      auto &now = this->nodes[que.front()];
      int fail  = now.nxt[FAIL];
      correct[que.front()] += correct[fail];
      que.pop();
      for (int i = 0; i < char_size; i++) {
        if (~now.nxt[i]) {
          this->nodes[now.nxt[i]].nxt[FAIL] =
              this->nodes[fail].nxt[i];
          if (heavy) {
            auto &u = this->nodes[now.nxt[i]].accept;
            auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;
            vector< int > accept;
            set_union(begin(u), end(u), begin(v), end(v),
                      back_inserter(accept));
            u = accept;
          }
          que.emplace(now.nxt[i]);
        } else {
          now.nxt[i] = this->nodes[fail].nxt[i];
        }
      }
    }
  }

  map< int, int > match(const string &str, int now = 0) {
    map< int, int > result;
    for (auto &c: str) {
      now = this->nodes[now].nxt[c - margin];
      for (auto &v: this->nodes[now].accept) result[v] += 1;
    }
    return result;
  }

  pair< int64_t, int > move(const char &c, int now = 0) {
    now = this->nodes[now].nxt[c - margin];
    return {correct[now], now};
  }

  pair< int64_t, int > move(const string &str, int now = 0) {
    int64_t sum = 0;
    for (auto &c: str) {
      auto nxt = move(c, now);
      sum += nxt.first;
      now = nxt.second;
    }
    return {sum, now};
  }
};

template <size_t X = 26, char margin = 'a', typename T = ll>
struct Tri {
public:
  vector<vector<int>> nxt; vector<bool> end; vector<int> cs, fail; vector<T> node_v;
  Tri() { init_node(-1); }
  size_t size() const { return nxt.size(); }

  int add_node(int v, int n, bool isend = false, T val = T()) {
    assert(fail.size() == 0);
    int ret = -1;
    if (nxt[v][n] == -1) ret = nxt[v][n] = init_node(n);
    else ret = nxt[v][n];
    if (isend) {
      end[ret] = 1;
      node_v[ret] += val;
    }
    return ret;
  }
  int add(vector<int> &s, T val = T()) { int n = s.size(), v = 0; for (int i = 0; i < n; ++i) v = add_node(v, s[i], i == n - 1, val); return v; }
  int add(string &s, T val = T()) { int n = s.size(), v = 0; for (int i = 0; i < n; ++i) v = add_node(v, s[i] - margin, i == n - 1, val); return v; }

  int walk(int v, int n) { return nxt[v][n]; }
  int search(vector<int> &s) { int n = s.size(), v = 0; for (int i = 0; i < n; ++i) { v = walk(v, s[i]); if (v == -1) return v; } return v; }
  int search(string &s) { int n = s.size(), v = 0; for (int i = 0; i < n; ++i) { v = walk(v, s[i] - margin); if (v == -1) return v; } return v; }

  void build_fail() {
    fail.assign(nxt.size(), 0);
    vector<int> bfs; bfs.emplace_back(0);
    queue<int> que; que.push(0);
    while (!que.empty()) {
      int v = que.front(); que.pop();
      node_v[v] = node_v[v] + node_v[fail[v]];
      for (int s = 0; s < X; ++s) {
        if (nxt[v][s] == -1) continue;
        int w = nxt[v][s];
        que.push(w);
        bfs.emplace_back(w);
        if (v == 0) continue;
        int f = fail[v];
        while (f && nxt[f][s] == -1) f = fail[f];
        fail[w] = (nxt[f][s] == -1 ? 0 : nxt[f][s]);
      }
    }
    for (auto v: bfs) {
      for (int s = 0; s < X; ++s) if (nxt[v][s] == -1) {
        int f = fail[v];
        nxt[v][s] = nxt[f][s];
        if (nxt[v][s] == -1) nxt[v][s] = 0;
      }
    }
  }
  inline const vector<int> &operator[](const int &k) { return nxt[k]; }

private:
  int init_node(int n) {
    nxt.emplace_back(vector<int>(X, -1));
    cs.emplace_back(n);
    end.emplace_back(0);
    node_v.emplace_back(T());
    return nxt.size() - 1;
  }
};

vl solve(string s, vs t) {
  Tri G; rep(i, t.size()) G.add(t[i], 1);

  G.build_fail();
  // debug(G.nxt);
  // debug(G.fail);
  // debug(G.end);

  ll p = 0, cur = 0;
  vl ans;
  rep(i, s.size()) {
    p = G.walk(p, s[i] - 'a');
    // debug(p, G.end[p]);
    if (G.node_v[p]) {
      ++cur;
      p = 0;
    }
    ans.pb(cur);
  }
  return ans;
}

vl naive(string s, vs t) {
  AhoCorasick<26, 'a'> A;
  for (int i = 0; i < t.size(); i++){
    A.add(t[i]);
  }
  A.build();
  int c = 0;
  int ans = 0;
  int M = s.size();
  vl ansv;
  for (int i = 0; i < M; i++){
    pair<int, int> P = A.move(s[i], c);
    if (P.first == 0){
      c = P.second;
    } else {
      ans++;
      c = 0;
    }
    ansv.pb(ans);
  }
  return ansv;
}

void compare(bool check = true) { RandGen rg; ll c = 0, loop = 10;
  while (++c) { if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    string s = rg.straz(20, 0, 10);
    vs t;
    rep(i, 5) t.pb(rg.straz(rg.l(2, 5), 0, 10));

    auto so = solve(s, t); auto na = naive(s, t);
    if (!check || na != so) { cout << c << "times tried" << "\n";
      debug(s, t); debug(so); debug(na);
    if (check || (!check && c > loop)) break; }
  }
}

void solve() {
  string s; cin >> s;
  ll n; cin >> n;
  vs t(n); rep(i, n) cin >> t[i];
  cout << solve(s, t).back() << "\n";
}

signed main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0); cout << fixed << setprecision(15);
  int t = 1; //cin >> t;
  // while (t--) solve();
  while (t--) compare();
}
