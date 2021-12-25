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
#define rep(i,n) for (ll i=0; i<(ll)(n); ++i)
#define rep2(i,x,n) for(ll i=x; i<(ll)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  ll N, A, B;
  cin >> N >> A >> B;

  // vector<vector<bool>> dp(N, vector<bool>(N, false));

  // rep2(k, max(1 - A, 1 - B), min(N - A, N - B) + 1) {
  //   dp[A+k][B+k] = true;
  // }
  // rep2(k, max(1 - A, B - N), min(N - A, B - 1) + 1) {
  //   dp[A+k][B-k] = true;
  // }

  ll P, Q, R, S;
  cin >> P >> Q >> R >> S;

  ll mi = max(1 - A, 1 - B);
  ll ma = min(N - A, N - B);
  ll mi2 = max(1 - A, B - N);
  ll ma2 = min(N - A, B - 1);

  rep2(i, P, Q+1) {
    rep2(j, R, S+1) {
      ll t1 = i - A;
      ll t2 = j - B;
      ll t3 = B - j;

      if (j - i == B - A) {
        if (t1 >= mi && t1 <= ma && t2 >= mi && t2 <= ma) {
          cout << "#";
          continue;
        }
      }

      if (i + j == A + B) {
        if (t1 >= mi2 && t1 <= ma2 && t3 >= mi2 && t3 <= ma2) {
          cout << "#";
          continue;
        }
      }

      cout << ".";
    }
    cout << endl;
  }
}

