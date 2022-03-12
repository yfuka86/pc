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
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
typedef pair<int, int> P; typedef pair<ll, ll> LP;
typedef vector<int> vi; typedef vector<ll> vl; typedef vector<LP> vlp; typedef vector<bool> vb; typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template <typename T, typename S> T ceil(T x, S y) { assert(y); return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y)); }
template <typename T, typename S> T floor(T x, S y) { assert(y); return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : (x - y + 1) / y)); }
template <class T> T POW(T x, int n) { assert(n >= 0); T res = 1; for(; n; n >>= 1, x *= x) if(n & 1) res *= x; return res; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<typename T> void coutarray(vector<T>& v, int offset = 0) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i] + offset; } cout << "\n"; }
template<typename T> void coutmatrix(vector<vector<T>>& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} }
template<typename K, typename V> void coutmap(map<K, V> & m) { for (const auto& kv : m) { cout << kv.first << ":" << kv.second << " "; } cout << "\n"; }
template<typename T> void coutbin(T &a, int d) { for (int i = d - 1; i >= 0; i--) cout << ((a >> i) & (T)1); cout << "\n"; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

bool is_prime(long long N) {
  if (N == 1) return false; for (long long i = 2; i * i <= N; ++i) if (N % i == 0) return false; return true;
}

vector<ll> primes_below(const ll N) {
  vector<bool> is_prime(N + 1, true); for(ll i = 2; i * i <= N; i++) { if ((i > 2 && i % 2 == 0) || !is_prime[i]) continue; for(ll j = i * i; j <= N; j += i) is_prime[j] = false; }
  vector<ll> ret; for(ll i = 2; i <= N; i++) if (is_prime[i]) ret.emplace_back(i); return ret; }

map<long long, long long> prime_factorize(long long N) {
  map<long long, long long> res;
  for (long long a = 2; a * a <= N; ++a) { if (N % a != 0) continue; long long ex = 0; while (N % a == 0) { ++ex; N /= a; } res[a]= ex; }
  if (N != 1) res[N] = 1; return res; }

vector<long long> divisor(long long n) {
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++) { if (n % i == 0) { ret.push_back(i); if (i * i != n) ret.push_back(n / i); } }
  sort(ret.begin(), ret.end()); return ret; }



bool solve() {
  ll x, d; cin >> x >> d;
  ll xx = x;
  ll dcount = 0;
  while (xx % d == 0) {
    xx /= d;
    dcount++;
  }

  if (dcount <= 1) return false;
  if (is_prime(d)) {
    // dが素数のケース
    if (xx != 1 && !is_prime(xx)) return true; else return false;
  } else {
    map<ll, ll> dfactor = prime_factorize(d);
    map<ll, ll> xfactor = prime_factorize(xx);
    // xxが2つ以上の素数の合成数のケースはOK
    if (xfactor.size() > 1) return true;

    // dは合成数、xxは素数のn乗
    // dcountが4だと必ず一つのdを潰して分離できる
    if (dcount >= 4) return true;
    // dcountが2だとxxが素数の2乗以上であることで必要十分
    if (dcount == 2) {
      if (xfactor.size() && xfactor.begin()->second > 1) return true;
      return false;
    }

    // 残り、dcount == 3、つまりx = d^3 * xx(xx = p^n)
    // dが複数の素数の合成数のケースはOK（dcountが2の時は片方のdを潰せないのでだめ）
    if (dfactor.size() > 1) return true;
    // dは素数のx乗　xxは素数のy乗か1
    if (xx == 1 || dfactor.begin()->first != xfactor.begin()->first) return true;

    // dとxxは同一素数のx, y乗
    ll x = dfactor.begin()->second;
    ll y = xfactor.begin()->second;
    // 3項のままyの配分を変えられるケース
    if (y > 1) return true;
    // 3項は1通り、2項にする時にdを約数に含まざるを得ないケース、大丈夫なケース
    if ((x - 1) * 2 < x + y) return false; else return true;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t; cin >> t;
  while (t--) if (solve()) cout << "YES" << "\n"; else cout << "NO" << "\n";
}

using A = ll;
template<typename Q> A iquery(Q q, string str = "?") {
  cout << str <<  " " << q << "\n"; cout.flush();
  A a; cin >> a; return a;
}

template<typename A> void ianswer(A a) {
  cout << "! " << a << "\n"; cout.flush();
}
