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

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  int N, D;
  cin >> N >> D;

  vector<pint> rls(N);
  for (auto &[r, l] : rls) {
    cin >> l >> r;
  }
  sort(rls.begin(), rls.end());
  int last_broken = -1;
  int ret = 0;
  for (auto [r, l] : rls) {
    if (l <= last_broken) continue;
    ret++;
    chmax(last_broken, r + D - 1);
  }
  cout << ret << endl;
}

