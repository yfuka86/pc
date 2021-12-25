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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep_r(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(ll i=sta;i<(ll)(n);i++)
#define rep2_r(i,sta,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();
const ll mod = 1000000007;

template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  ios::sync_with_stdio(false);

  while(true) {
    ll N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    vl c(M), x(N);
    rep(i, M) cin >> c[i];
    rep(i, N) cin >> x[i];

    vector<vl> dp(N + 1, vl(256, LINF));
    dp[0][128] = 0;

    rep2(i, 1, N + 1) {
      rep(j, 256) {
        if (dp[i - 1][j] == LINF) continue;
        rep(k, M) {
          ll next = min(max(0LL, j + c[k]), 255LL);
          ll diff = pow((x[i - 1] - next), 2);
          chmin(dp[i][next], dp[i - 1][j] + diff);
        }
      }
    }

    ll mi = LINF;
    rep(i, 256) {
      chmin(mi, dp[N][i]);
    }
    cout << mi << "\n";
  }
}


