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
  while(true) {
    int n, x;
    cin >> n >> x;
    if (n == 0 && x == 0) break;

    int count = 0;

    rep(i, n) {
      rep2(j, i + 1, n) {
        rep2(k, j + 1, n) {
          if (i + j + k + 3 == x) count++;
        }
      }
    }
    cout << count << endl;
  }
}
