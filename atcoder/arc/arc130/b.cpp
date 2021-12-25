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

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  int H, W, C, Q;
  cin >> H >> W >> C >> Q;
  vector<vector<int>> p;
  set<int> h;
  set<int> w;
  vector<ll> counts(C, 0);

  rep(i, Q) {
    int t, n, c;
    cin >> t >> n >> c; t--; n--; c--;
    p.push_back({t, n, c});
  }

  for (int i = Q - 1; i >= 0; i--){
    vector<int> v = p[i];
    if (v[0] == 0) {
      if (h.find(v[1]) == h.end()) {
        h.insert(v[1]);
        counts[v[2]] += W - w.size();
      }
    } else if (v[0] == 1) {
      if (w.find(v[1]) == w.end()) {
        w.insert(v[1]);
        counts[v[2]] += H - h.size();
      }
    }
  }

  rep(i, C) {
    cout << counts[i] << " ";
  }
  cout << endl;
}

