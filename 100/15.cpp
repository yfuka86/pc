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

using namespace std;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

double distance(P c1, P c2) {
  return sqrt(pow(c2.first - c1.first, 2) + pow(c2.second - c1.second, 2));
}

int main()
{
  int N;
  cin >> N;
  vector<P> v;
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }

  vector<vector<double>> dists(N, vector<double>(N));
  rep(i, N) {
    rep(j, N) {
      if (i==j) dists[i][j] = 0;
      dists[i][j] = distance(v[i], v[j]);
    }
  }

  vector<int> nums(N);
  rep(i, N) nums[i] = i;
  int count = 0;
  double sum = 0;
  do {
    count++;
    rep2(i, 1, N) {
      sum += dists[nums[i - 1]][nums[i]];
    }
  } while (next_permutation(all(nums)));

  cout << fixed << setprecision(10) << (sum / count) << endl;
}


