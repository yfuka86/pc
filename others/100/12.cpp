#include <iostream>
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

vector<vector<int>> graph_input(int n, int m) {
  vector<vector<int>> G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  return G;
}

int main()
{
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N);
  G = graph_input(N, M);

  int max = 0;
  rep(i, 1 << N) {
    int group = 0;
    bool valid = true;
    rep(j, N) {
      if ((i >> j) & 1) {
        group++;
        rep(k, N) {
          if (j == k) continue;
          if ((i >> k) & 1) {
            if (find(all(G[j]), k) == G[j].end()) {
              valid = false;
              break;
            }
          }
        }
      }
      if (!valid) break;
    }
    if (valid && (group > max)) max = group;
  }
  cout << max << endl;
}

