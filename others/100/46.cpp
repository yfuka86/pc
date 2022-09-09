// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <bitset>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

template <class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }

vector<vector<int> > dp;
vector<P> M;

int times(P m1, P m2) {
  return (m1.first * m2.second) * m1.second;
}

int cost(int start, int end) {
  if (start == end) return dp[start][end];
  if (dp[start][end]) return dp[start][end];
  if (end - start == 1) return times(M[start], M[end]);

  int ret = INF;
  rep2(i, start, end) {
    int c1 = cost(start, i);
    int c2 = cost(i + 1, end);
    int csum = c1 + c2 + times(make_pair(M[start].first, M[i].second), make_pair(M[i + 1].first, M[end].second));
    chmin(ret, csum);
  }
  return dp[start][end] = ret;
}

int main()
{
  int n;
  cin >> n;
  M.resize(n);
  dp.resize(n);
  dp.assign(n, vector<int>(n, 0));

  rep(i, n) {
    int r, c;
    cin >> r >> c;
    M[i] = make_pair(r, c);
  }

  cout << cost(0, n - 1) << endl;
}

