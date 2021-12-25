#include <iostream>
#include <map>
#include <set>
#include <bitset>
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
  int N, M;
  cin >> N >> M;
  vector<vector<int>> switches(M);
  vector<int> cond(M);
  rep(i, M) {
    int k;
    cin >> k;
    rep(j, k) {
      int t;
      cin >> t; t--;
      switches[i].push_back(t);
    }
  }
  rep(i, M) {
    cin >> cond[i];
  }

  int sum = 0;
  rep(i, (1<<n)) {
    rep(j, M) {
      int x = 0;
      for(int k: switches[j]) {
        if ((i>>k) & 1) x^=1;
      }
      if (x == w[j]) sum++;
    }
  }

  cout << sum << endl;
}

