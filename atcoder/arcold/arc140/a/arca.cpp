#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define vlin(name,sz) vl name(sz); rep(i,sz) cin>>name[i];
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT3; typedef tuple<ll, ll, ll> LT4;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> vvvl;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb;
const int INF = numeric_limits<int>::max() / 2 - 1e6; const ll LINF = LLONG_MAX / 2 - 1e6; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
struct RandGen {
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll l(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  vl vecl(ll l, ll a, ll b) { ud d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
  vl vecperm(ll l) { vl perm(l); iota(all(perm), 1); random_shuffle(all(perm)); return perm; }
  string str(ll l, vl op, char lead = 'A') { vl fig = vecl(l, 0, op.size()); string s; rep(i, l) s.pb(lead + op[fig[i]]); return s; }
  string straz(ll l, ll a = 0, ll z = 26) { vl az = vecl(l, a, z); string s; rep(i, l) s.pb('a' + az[i]); return s; }
  string strnum(ll l, ll zero = 0, ll ten = 10) { vl zt = vecl(l, zero, ten); string s; rep(i, l) s.pb('0' + zt[i]); return s; }
};
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void uniq(vector<T>&a){ sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
ll binary_search(function<bool(ll)> check, ll ok, ll ng) { assert(check(ok)); while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template <class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }

template<typename T> void coutarray(vector<T>& v, int offset = 0, string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset) cout << v[i] + offset; else cout << v[i]; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v, int offset = 0) { rep(i, v.size()) { coutarray(v[i], offset); } }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T, typename S> void coutpair(pair<T, S> & p) { cout << p.first << " " << p.second << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
const string drul = "DRUL"; vl dx = {1, 0, -1, 0}; vl dy = {0, 1, 0, -1};

vl divisor(ll n) {
  vl ret; for (ll i = 1; i * i <= n; i++) { if (n % i == 0) { ret.pb(i); if (i * i != n) ret.pb(n / i); } }
  sort(all(ret)); return ret; }

void solve() {
  ll N; cin >> N;
}

ll solve(ll N, ll K, string S) {
  ll ans = LINF;

  vl d = divisor(N); reverse(all(d));
  for (ll div: d) {
    ll cycle = N / div;
    ll cur = 0;
    do {
      map<string, ll> freq;
      for (ll i = 0; i < N; i += cycle) {
        freq[S.substr(i, cycle)]++;
      }
      // coutmap(freq);

      string mas = ""; ll cnt = 0; for(auto[k, c]: freq) if (chmax(cnt, c)) mas = k;
      ll need = 0;
      for (auto [k, c]: freq) {
        rep(i, cycle) if (mas[i] != k[i]) need += c;
      }
      if (need <= K) { chmin(ans, cycle); }

      rotate(S.begin(), S.begin() + 1, S.end()); cur++;
    } while (cur < cycle);
  }
  return ans;
}

void enum_check(ll N, ll from, ll to, function<bool(vl&)> check) { // size, [from, to)
  to--; vl st(N, from);
  while (true) {
    assert(st.size() == N); if (!check(st)) break;

    while (st.back() == to) st.pop_back(); if (st.size() == 0) break;
    st.back()++; while (st.size() < N) st.pb(from);
  }
}

ll naive(ll N, ll K, string S) {
  map<char,ll> freq;
  rep(i, N) freq[S[i]]++;
  vector<char> cand;
  for (auto [c, cnt]: freq) cand.pb(c);

  ll ans = LINF;
  rep(ST, 1 << N) {
    ll k = __builtin_popcount(ST);
    if (k > K || k == 0) continue;

    enum_check(k, 0, cand.size(), [&](vl &en) {
      string stmp = S;
      auto itr = en.begin();
      rep(i, N) {
        if (ST & 1 << i) {
          stmp[i] = cand[*itr];
          itr++;
        }
      }
      set<string> fs;
      rep(_, N) {
        fs.insert(stmp);
        rotate(stmp.begin(), stmp.begin() + 1, stmp.end());
      }
      chmin<ll>(ans, fs.size());
      return true;
    });
  }
  return ans;

  // vl d = divisor(N);
  // ll ans = N;
  // for (ll div: d) {
  //   ll cycle = div;
  //   div = N / div;
  //   if (N - cycle <= K) { chmin(ans, cycle); continue; }

  //   vector<map<char, ll>> freq(cycle);

  //   rep(i, N) freq[i % cycle][S[i]]++;
  //   ll need = 0;
  //   rep(i, cycle) {
  //     ll ma = 0;
  //     for (auto [_, c]: freq[i]) chmax(ma, c);
  //     need += N / cycle - ma;
  //   }
  //   if (need <= K) chmin(ans, cycle);
  // }
  // return ans;
}

void execute() {
  // solve(); return;
  RandGen rg; ll c = 0, loop = 10;
  while (true) {
    c++; if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll N = 6;
    ll K = 2;
    string S = rg.straz(N);
    auto s = solve(N, K, S); auto n = naive(N, K, S);
    if (n != s) {
      cout << c << "times tried" << "\n";
      cout << N << " " << K << " " << S << "\n";
      cout << "solve: " << s << "\n";
      cout << "naive: " << n << "\n";
      break;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(12);
  int t = 1; //cin >> t;
  while (t--) execute();
}
