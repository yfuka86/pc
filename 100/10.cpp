#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

using namespace std;

vector<int> A;

bool solve(int idx, int sum) {
  if (sum - A[idx] == 0) return true;
  if (idx < A.size() - 1) {
    if (sum - A[idx] > 0 && solve(idx + 1, sum - A[idx])) return true;
    if (solve(idx + 1, sum)) return true;
  }
  return false;
}

int main()
{
  int n, q;
  cin >> n;
  A.resize(n);
  rep(i, n) cin >> A[i];

  cin >> q;
  rep(i, q) {
    int m;
    cin >> m;
    cout << (solve(0, m) ? "yes" : "no") << endl;
  }
}

