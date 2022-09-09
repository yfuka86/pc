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
  int n;
  cin >> n;

  int count = 0;

  rep(i, n + 1) {
    if (i % 2 == 0) continue;

    int each_count = 0;
    rep2(m, 1, i + 1) {
      if (i % m == 0) each_count++;
    }
    if (each_count == 8) count++;
  }

  cout << count << endl;
}
