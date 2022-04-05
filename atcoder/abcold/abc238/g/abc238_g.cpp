#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx512f")
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
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();

int ceil_pow2(ll n) { int x = 0; while ((1ULL << x) < (unsigned long long)(n)) x++; return x; }
int floor_pow2(ll n) { int x = 0; while ((1ULL << (x + 1)) <= (unsigned long long)(n)) x++; return x; }
template<typename T> void comp(vector<T>&a){ vector<T> b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); rep(i, a.size()) a[i] = lower_bound(all(b), a[i]) - b.begin(); }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T> bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }
struct Mo {
  int width;
  vector<int> left, right, order;

  Mo(int N, int Q) : order(Q) {
    width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));
    iota(begin(order), end(order), 0);
  }

  void insert(int l, int r) { /* [l, r) */
    left.emplace_back(l);
    right.emplace_back(r);
  }

  template <typename AL, typename AR, typename DL, typename DR, typename REM>
  void run(const AL &add_left, const AR &add_right, const DL &delete_left,
           const DR &delete_right, const REM &rem) {
    assert(left.size() == order.size());
    sort(begin(order), end(order), [&](int a, int b) {
      int ablock = left[a] / width, bblock = left[b] / width;
      if (ablock != bblock) return ablock < bblock;
      if (ablock & 1) return right[a] < right[b];
      return right[a] > right[b];
    });
    int nl = 0, nr = 0;
    for (auto idx : order) {
      while (nl > left[idx]) add_left(--nl);
      while (nr < right[idx]) add_right(nr++);
      while (nl < left[idx]) delete_left(nl++);
      while (nr > right[idx]) delete_right(--nr);
      rem(idx);
    }
  }
};

//-------------------------------------------------------
// https://atcoder.jp/contests/abc238/submissions/29086825
// https://cp-algorithms.com/algebra/prime-sieve-linear.html
const int PSX = 1e6 + 1;
struct PrimeSieve {
  bitset<PSX> is_prime; vector<int> pr;
  int mu[PSX];  // moebius
  int pf[PSX];  // pf[i] := smallest prime p s.t. p | i
  PrimeSieve(){
    is_prime.flip(); is_prime[0] = is_prime[1] = false; mu[1] = 1;
    for (int i = 2; i < PSX; i++) {
      if (is_prime[i]) { pr.push_back(i); pf[i] = i; mu[i] = -1; }
      for (int p : pr) {
        if (ll(i) * p >= PSX) break;
        is_prime[i * p] = false; mu[i * p] = -mu[i]; pf[i * p] = p;
        if (i % p == 0) { mu[i * p] = 0; break; }
      }
    }
  }
  vector<pair<int, int>> factorize(int x) { vector<pair<int, int>> vec; while (pf[x] > 1) { int d = pf[x], c = 0; while (x % d == 0) { x /= d; c++; } vec.emplace_back(d, c); } if (x != 1) vec.emplace_back(x, 1); return vec; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, Q; cin >> N >> Q;
  vl a(N); rep(i, N) cin >> a[i];

  vector<vector<P>> pf(N);
  PrimeSieve ps;

  rep(i, N) {
    pf[i] = ps.factorize(a[i]);
  }

  Mo mo(N, Q);
  vb ans(Q);
  rep(i, Q) {
    int l, r; cin >> l >> r; l--; mo.insert(l, r);
  }

  vi primetable(1000000, 0);
  ll c = 0;
  auto add = [&](int i) {
    for (auto [p, n]: pf[i]) {
      if (primetable[p] % 3 == 0) c++;
      primetable[p] += n;
      if (primetable[p] % 3 == 0) c--;
    }
  };
  auto erase = [&](int i) {
    for (auto [p, n]: pf[i]) {
      if (primetable[p] % 3 == 0) c++;
      primetable[p] -= n;
      if (primetable[p] % 3 == 0) c--;
    }
  };
  auto rem = [&](int idx) {
    ans[idx] = c == 0;
  };
  mo.run(add, add, erase, erase, rem);
  for (auto p: ans) cout << (p ? "Yes" : "No") << "\n";
}


