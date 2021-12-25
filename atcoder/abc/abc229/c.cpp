#include <iostream>
#include <queue>
#include <map>
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
  int N, W;
  cin >> N >> W;

  map<int, int> m;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    m[a] += b;
  }

  vector<int> keys;
  for (const auto& kv : m) {
    keys.push_back(kv.first);
  }
  sort(all(keys), greater<int>());

  ll sum = 0;

  rep(i, keys.size()) {
    ll k = keys[i];
    ll v = m[k];
    if (v <= W) {
      sum += k * v;
      W -= v;
    } else {
      sum += k * W;
      W = 0;
    }
    if (W == 0) break;
  }

  cout << sum << endl;
}

