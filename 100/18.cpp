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

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

int main()
{
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, n) {
    cin >> s[i];
  }
  int q;
  cin >> q;
  int count = 0;
  rep(i, q) {
    int t;
    cin >> t;
    vector<int>::iterator itr = lower_bound(all(s), t);
    if (itr != s.end() && s[itr - s.begin()] == t) count++;
  }
  cout << count << endl;
}

