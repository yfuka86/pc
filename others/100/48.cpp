#pragma GCC optimize("Ofast")
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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep_r(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(int i=sta;i<(int)(n);i++)
#define rep2_r(i,sta,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<ll> vl;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();
const ll mod = 1000000007;

template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int N;
vector<int> W;
vector<vi> dp;

int calc(int start, int end) {
  if (dp[start][end] != -1) return dp[start][end];

  int num = end - start + 1;

  if (num < 2) return dp[start][end] = 0;
  if (num == 2) return abs(W[start] - W[end]) <= 1 ? 2 : 0;

  // numは3以上
  int ma = 0;
  for (int k = 1; k < num - 1; k++) {
    chmax(ma, calc(start, start + k) + calc(start + k + 1, end));
  }
  if (calc(start + 1, end - 1) == num - 2) {
    chmax(ma, calc(start + 1, end - 1) + (abs(W[start] - W[end]) <= 1 ? 2 : 0));
  }
  return dp[start][end] = ma;
}

int main()
{
  ios::sync_with_stdio(false);

  while (true) {
    cin >> N;
    if (N == 0) break;
    W.resize(N); dp.resize(N);
    dp.assign(N, vi(N, -1));
    rep(i, N) cin >> W[i];

    cout << calc(0, N - 1) << "\n";
  }

}

