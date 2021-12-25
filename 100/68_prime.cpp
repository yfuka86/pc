#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main()
{
  int N;
  cin >> N;
  int n = N;
  vector<int> factors;

  float max = sqrt(n);
  rep2(i, 2, max + 1) {
    while (n % i == 0) {
      n /= i;
      factors.push_back(i);
    }
  }
  if (n != 1) {
    factors.push_back(n);
  }

  cout << N << ":";
  rep(i, factors.size()) cout << " " << factors[i];
  cout << endl;

  return 0;
}

