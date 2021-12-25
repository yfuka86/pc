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
#include <bitset>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = numeric_limits<int>::max();

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int main()
{
  int H, W;
  cin >> H >> W;

  vector<vector<int>> S(H, vector<int>(W, 0));

  rep(i, H) {
    string s; cin >> s;
    rep(j, W) {
      if (s[j] == '.') {
        S[i][j] = 0;
      } else {
        S[i][j] = s[j] - '0';
      }
    }
  }

  rep(i, H) {
    rep(j, W) {
      if (S[i][j] != 0) continue;
      bool colors[6];
      rep(t, 6) colors[t] = false;
      if (i > 0 && S[i - 1][j] != 0) colors[S[i - 1][j]] = true;
      if (i < H-1 && S[i + 1][j] != 0) colors[S[i + 1][j]] = true;
      if (j > 0 && S[i][j - 1] != 0) colors[S[i][j - 1]] = true;
      if (j < W-1 && S[i][j + 1] != 0) colors[S[i][j + 1]] = true;
      rep2(k, 1, 6) {
        if (!colors[k]) S[i][j] = k;
      }
    }
  }

  rep(i, H) {
    rep(j, W) {
      cout << (S[i][j] == 0 ? '.' : S[i][j]);
    }
    cout << endl;
  }
}

