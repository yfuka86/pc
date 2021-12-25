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

int main()
{
  ll N, X;
  cin >> N >> X;

  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  ll sum = 0;
  ll num = 0;
  if (A[N - 1] < X) {
    num = X / A[N - 1];
    sum = num * A[N - 1];
  }

  while(sum != X) {
    vector<ll>::iterator itr = upper_bound(all(A), abs(sum - X));

    ll add;
    if (itr == A.end()) {
      add = A[N - 1];
    } else {
      int idx = itr - A.begin();
      ll a1 = abs(A[idx] - abs(sum - X));
      ll a2 = abs(A[idx - 1] - abs(sum - X));
      if (a1 < a2) {
        add = A[idx];
      } else {
        int n = (abs(sum - X) / A[idx - 1]);
        add = n * A[idx - 1];
        num += (n - 1);
      }
    }

    if (sum > X) {
      sum -= add;
    } else {
      sum += add;
    }
    num++;
  }
  cout << num << endl;
}

