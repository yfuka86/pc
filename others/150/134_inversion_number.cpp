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
	vector<T> node; int n;

	BIT(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, T w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	T sum(int a) {
		T ret = 0;
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	T sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

template <typename T>
vector<T> comp(vector<T> &X) {
  vector<T> vals = X;
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  for (int i = 0; i < (int)X.size(); i++) {
      X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
  }
  return vals;
}

int main()
{
  int N = 50;
  cin >> N;
  vi A(N);
  rep(i, N) cin >> A[i];
  // for (int i = 0; i < N; i++) A[i] = rand() % 50 + 1;
  comp(A);
  // coutarray(A);

  BIT<int> bs(N);
  ll ans = 0;
  rep(i, N) {
    ans += i - bs.sum(A[i]);
    // cout << ans << endl;
    bs.add(A[i], 1);

    // rep(i, N) {
    //   cout << bs.sum(i, i + 1) << " ";
    // }
    // cout << endl;
  }
  cout << ans << endl;
  return 0;
}


