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
template<typename T>
void coutarray(vector<T>& v) { rep(i, v.size()) { if (i > 0) cout << " "; cout << v[i];} cout << "\n"; }
template<typename T>
void coutmatrix(vector<vector<T> >& v) { rep(i, v.size()) { rep(j, v[i].size()) { if (j > 0) cout << " "; cout << v[i][j]; } cout << "\n";} };
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

template<typename T>
struct BIT {
  int n;
  vector<T> bit;

  BIT(int _n = 0) : n(_n), bit(n + 1) {}

  // sum of [0, i), 0 <= i <= n
  T sum(int i) {
    T s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  // 0 <= i < n
  void add(int i, T x) {
    ++i;
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
  }

  //[l, r) 0 <= l < r < n
  T sum(int l, int r) { return sum(r) - sum(l); }

  // smallest i, sum(i) >= w, none -> n
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0, l = 1;
    while (l * 2 <= n) l <<= 1;

    for (int k = l; k > 0; k /= 2) {
      if (x + k <= n && bit[x + k] < w) {
        w -= bit[x + k];
        x += k;
      }
    }
    return x;
  }
};

void comp(vector<int>&a){
  set<int>s(a.begin(),a.end()); map<int,int>d;
  int cnt=0; for(int x:s)d[x]=cnt++; for(int&x:a)x=d[x];
}

int main()
{
  int Q;
  cin >> Q;

  BIT<int> bs(200010);
  rep(i, Q) {
    int t, x; cin >> t >> x;
    if (t == 1) {
      bs.add(x, 1);
    } else {
      int ans = bs.lower_bound(x);
      cout << ans << endl;
      bs.add(ans, -1);
    }
  }
}


