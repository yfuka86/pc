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
#include <bitset>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

template <class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

template <class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }

int main()
{
  int N, M, D;
  cin >> N >> M >> D;

  vector<ll> r(M + 1);
  vector<ll> s(M + 1);
  rep(i, M + 1) {
    cin >> r[i];
  }
  rep(i, M) {
    cin >> s[i];
  }
  s[M] = 0;

  int minr = INF;
  rep2(i, 1, M + 1) {
    ll diff = (r[i] - r[i - 1]);
    if (diff > INF) continue;
    chmin(minr, int(diff));
  }

  ll max = 0;
  rep(j, min(minr, D) + 1) {
    int center = j;
    int negcenter = -center;
    ll sum = s[0];
    rep2(i, 1, N / 2 + 1) {
      auto itr = lower_bound(all(r), center + (i * D));
      auto nitr = lower_bound(all(r), negcenter + (i * D));
      if (itr == r.end() && nitr == r.end()) break;
      ll s1 = s[itr - r.begin() - 1];
      ll s2 = s[nitr - r.begin() - 1];

      if (i == N / 2 && N % 2 == 0) {
        sum += s2;
      } else {
        sum += (s1 + s2);
      }
    }
    chmax(max, sum);
  }
  cout << max << endl;
}
