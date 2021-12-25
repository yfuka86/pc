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
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
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
template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

void comp(vector<int>&a){
  set<int>s(a.begin(),a.end()); map<int,int>d;
  int cnt=0; for(int x:s)d[x]=cnt++; for(int&x:a)x=d[x];
}

template<typename T>
struct BIT {
  int n; vector<T> bit;
  BIT(int _n = 0) : n(_n), bit(n + 1) {}
  // sum of [0, i), 0 <= i <= n
  T sum(int i) { T s = 0; while (i > 0) { s += bit[i]; i -= i & -i; } return s;}
  // 0 <= i < n
  void add(int i, T x) { ++i; while (i <= n) { bit[i] += x; i += i & -i; } }
  //[l, r) 0 <= l < r < n
  T sum(int l, int r) { return sum(r) - sum(l); }
  // smallest i, sum(i) >= w, none -> n
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0, l = 1; while (l * 2 <= n) l <<= 1;
    for (int k = l; k > 0; k /= 2) if (x + k <= n && bit[x + k] < w) { w -= bit[x + k]; x += k; }
    return x;
  }
};

int main()
{
  int N;
  cin >> N;
  vi A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  comp(A); comp(B);

  vector<P> p(N);
  rep(i, N) p[i] = make_pair(A[i], -B[i]);
  sort(all(p));

  BIT<int> bs(N);
  ll ans = 0;
  ll same = 0;
  rep(i, N) {
    bs.add(-p[i].second, 1);
    ans += bs.sum(-p[i].second, N);

    if (i == 0) continue;
    if (p[i - 1] == p[i]) same++;
    if (p[i - 1] != p[i] || i == N - 1) { ans += (same + 1) * same / 2; same = 0; }
  }

  cout << ans << endl;
}

