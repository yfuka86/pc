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

  while (true) {
    int N; cin >> N;
    if (N == 0) break;

    vi day(86400, 0);
    rep(i, N * 2) {
      string s; cin >> s;
      int h = (s[0] - '0') * 10 + (s[1] - '0');
      int m = (s[3] - '0') * 10 + (s[4] - '0');
      int ss = (s[6] - '0') * 10 + (s[7] - '0');
      day[h * 3600 + m * 60 + ss] += (i % 2 == 0 ? 1 : -1);
    }

    int ans = 0;
    int sum = 0;
    rep(i, 86400) {
      sum += day[i];
      chmax(ans, sum);
    }
    cout << ans << "\n";
  }
}
