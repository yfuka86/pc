#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main()
{
  int n=0;
  cin >> n;

  int time=0;
  int x=0;
  int y=0;

  rep(i, n) {
    vector<int> v(3);
    int t=0;
    rep(m, 3) {
      cin >> t;
      v[m] = t;
    }

    int to_elaps = v[0] - time;
    time = v[0];
    int x_diff = abs(v[1] - x);
    x = v[1];
    int y_diff = abs(v[2] - y);
    y = v[2];

    if (to_elaps >= x_diff + y_diff && (to_elaps - (x_diff + y_diff)) % 2 == 0) {
      continue;
    } else {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
