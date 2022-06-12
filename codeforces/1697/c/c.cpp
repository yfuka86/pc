#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=sta;i--)
#define all(v) (v).begin(),(v).end()
#define vlin(name,sz,offset) vl name(sz); rep(i,sz){cin>>name[i]; name[i]-=offset;}
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP; typedef map<ll, ll> LM; typedef tuple<ll, ll, ll> LT; typedef tuple<ll, ll, ll, ll> LT4;
typedef vector<int> vi; typedef vector<vi> vvi; typedef vector<ll> vl; typedef vector<vl> vvl; typedef vector<vvl> v3l; typedef vector<v3l> v4l; typedef vector<v4l> v5l;
typedef vector<LP> vlp; typedef vector<vlp> vvlp; typedef vector<string> vs; typedef vector<vs> vvs;
typedef vector<ld> vd; typedef vector<vd> vvd; typedef vector<bool> vb;
const int INF = numeric_limits<int>::max() / 2 - 1e6; const ll LINF = LLONG_MAX / 2 - 1e6; const double DINF = numeric_limits<double>::infinity();

using A = ll;
template<typename Q> A iquery(Q q, string str = "? ") { cout << str << q << "\n"; cout.flush(); A a; cin >> a; return a; }
template<typename A> void ianswer(A a, string str = "! ") { cout << str << a << "\n"; cout.flush(); }
struct RandGen {
  using ud = uniform_int_distribution<ll>; mt19937 mt; RandGen() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  ll l(ll a, ll b) { ud d(a, b - 1); return d(mt); }
  LP lp(ll a, ll b, bool rng = true) { ll x = l(a, b - 1), y = l(rng ? x + 1 : a, b - 1); return {x, y}; }
  vl vecl(ll l, ll a, ll b) { ud d(a, b - 1); vl ret(l); rep(i, l) ret[i] = d(mt); return ret; }
  vl vecperm(ll l, ll from = 0) { vl perm(l); iota(all(perm), from); shuffle(perm); return perm; }
  string str(ll l, vector<char> op) { vl fig = vecl(l, 0, op.size()); string s; rep(i, l) s.pb(op[fig[i]]); return s; }
  string straz(ll l, ll a = 0, ll z = 26) { vl az = vecl(l, a, z); string s; rep(i, l) s.pb('a' + az[i]); return s; }
  string strnum(ll l, ll zero = 0, ll ten = 10) { vl zt = vecl(l, zero, ten); string s; rep(i, l) s.pb('0' + zt[i]); return s; }
  void shuffle(vl &a) { std::shuffle(all(a), mt); }
};
template<typename T> void coutarray(vector<T>& v, int offset = 0, string sep = " ") { rep(i, v.size()) { if (i > 0) cout << sep; if (offset) cout << v[i] + offset; else cout << v[i]; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v, int offset = 0) { rep(i, v.size()) { coutarray(v[i], offset); } }
template<typename T> void coutset(set<T> & s) { for (const auto& a : s) { cout << a << " "; } cout << "\n"; }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T, typename S> void coutpair(pair<T, S> & p, string sep = " ") { cout << p.first << ":" << p.second << sep; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }

template<typename K, typename V> V safe_read(map<K, V> &m, K key) { return m.find(key) != m.end() ? m[key] : V(); }
template<typename K, typename V> V safe_read(unordered_map<K, V> &m, K key) { return m.find(key) != m.end() ? m[key] : V(); }
int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
ll digits(ll n) { ll ret = 0; while(n > 0) { ret++; n /= 10; } return ret; }
ll POW(ll x, int n) { assert(n >= 0); ll res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
ll sqrt_ceil(ll x) { ll l = -1, r = x; while (r - l > 1) { ll m = (l + r) / 2; if (m * m >= x) r = m; else l = m; } return r; }
template<typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template<typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template<typename T> void uniq(vector<T>&a){ sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; uniq(b); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
template<class T> int lbs(vector<T> &a, const T &b) { return lower_bound(all(a), b) - a.begin(); };
template<class T> int ubs(vector<T> &a, const T &b) { return upper_bound(all(a), b) - a.begin(); };
ll binary_search(function<bool(ll)> check, ll ok, ll ng) { assert(check(ok)); while (abs(ok - ng) > 1) { auto x = (ng + ok) / 2; if (check(x)) ok = x; else ng = x; } return ok; }
template<class T> vector<T> csum(vector<T> &a) { vl ret(a.size() + 1, 0); rep(i, a.size()) ret[i + 1] = ret[i] + a[i]; return ret; }
template<class S> vector<pair<S, int>> RLE(const vector<S> &v) { vector<pair<S, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
vector<pair<char, int>> RLE(const string &v) { vector<pair<char, int>> res; for(auto &e : v) if(res.empty() or res.back().first != e) res.emplace_back(e, 1); else res.back().second++; return res; }
const string drul = "DRUL"; vl dx = {1, 0, -1, 0}; vl dy = {0, 1, 0, -1};

bool solve(string s, string t) {
  ll n = s.size();
  map<char, ll> sm, tm;
  rep(i, n) {
    sm[s[i]]++;
    tm[t[i]]++;
  }
  if (sm != tm) return false;
  rep(i, n) {
    if (s[i] == 'a' && t[i] == 'c') return false;
    if (t[i] == 'a' && s[i] == 'c') return false;
  }

  {
    ll ssum = 0, tsum = 0;
    rep(i, n) {
      if (s[i] == 'c' || t[i] == 'c') {
        if (ssum != tsum) return false;
        ssum = 0; tsum = 0;
      } else {
        if (s[i] == 'a') ssum++;
        if (t[i] == 'a') {
          tsum++;
          if (tsum > ssum) return false;
        }
      }
    }
  }

  {
    ll ssum = 0, tsum = 0;
    rep_r(i, n) {
      if (s[i] == 'a' || t[i] == 'a') {
        if (ssum != tsum) return false;
        ssum = 0; tsum = 0;
      } else {
        if (s[i] == 'c') ssum++;
        if (t[i] == 'c') {
          tsum++;
          if (tsum > ssum) return false;
        }
      }
    }
  }

  return true;


  // ll scur = 0, tcur = 0, rema = 0, remc = 0;
  // while (scur < n && tcur < n) {
  //   // cout << scur << " " << tcur << " " << rema << " " << remc << "\n";
  //   if (s[scur] == t[tcur]) {
  //     scur++; tcur++; continue;
  //   }

  //   if (t[tcur] == 'a' && remc) return false;
  //   if (t[tcur] == 'a') {
  //     if (!rema) return false;
  //     rema--; tcur++; continue;
  //   }
  //   if (s[scur] == 'c' && rema) return false;
  //   if (s[scur] == 'c') {
  //     if (!remc) return false;
  //     remc--; scur++; continue;
  //   }

  //   if (s[scur] == 'a') {
  //     if (scur < n - 1 && s[scur + 1] != 'c') {
  //       rema++; scur++; continue;
  //     } else return false;
  //   }

  //   if (t[tcur] == 'c') {
  //     if (tcur < n - 1 && t[tcur + 1] != 'a') {
  //       remc++; tcur++; continue;
  //     } else return false;
  //   }
  // }
  // // cout << scur << " " << tcur << "\n";
  // if (scur + remc == n && tcur + rema == n) return true; else return false;


}

bool naive(string s, string t) {
  ll n = s.size();
  rep(i, n) {
    if (s[i] == t[i]) continue;
    if (i == n - 1) return false;
    if (s[i] == 'a' && t[i] == 'b') {
      ll ti = i;
      while (ti < n && s[ti] == 'a') ti++;
      if (ti == n) return false;
      if (s[ti] != 'b') return false;
      swap(s[i], s[ti]);
      continue;
    }
    if (s[i] == 'b' && t[i] == 'c') {
      ll ti = i;
      while (ti < n && s[ti] == 'b') ti++;
      if (ti == n) return false;
      if (s[ti] != 'c') return false;
      swap(s[i], s[ti]);
      continue;
    }
    return false;
  }
  return true;
}

void compare(bool check = true) { RandGen rg; ll c = 0, loop = 10;
  while (++c) { if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll N = 10;
    vector<char> op =  {'a', 'b', 'c'};
    string s = rg.str(N, op), t = s;
    std::shuffle(all(t), rg.mt);
    auto so = solve(s, t); auto n = naive(s, t);
    if (!check || n != so) { cout << c << "times tried" << "\n";
      cout << s << "\n";
      cout << t << "\n";
      cout << "solve: " << so << "\n";
      cout << "naive: " << n << "\n";
    if (check || (!check && c > loop)) break; }
  }
}



bool solve() {
  ll n; cin >> n;
  string s, t; cin >> s >> t;
  return solve(s, t);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(15);
  int t; cin >> t;
  while (t--) if (solve()) cout << "YES" << "\n"; else cout << "NO" << "\n";
  // while (t--) compare();
}
