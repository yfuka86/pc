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
#include <climits>
#include <bitset>
#include <numeric>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> IP;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const ll MOD = 1000000007;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}
template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
template<class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }
template<class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }

int main()
{
  vector<int> tri(10000, 0);
  rep2(i, 1, 10001) {
    tri[i] = tri[i - 1] + i;
  }

  int N; cin >> N;
  vector<int>::iterator itr = find(all(tri), N);

  if (itr == tri.end()) { cout << "No" << endl; return 0;}

  int setcount = itr - tri.begin() + 1;
  int elmcount = N * 2 / setcount;

  vector<vector<int>> sets(setcount, vector<int>(elmcount, 0));

  cout << "Yes" << endl;
  cout << setcount << endl;

  int used = 1;
  rep(i, setcount) {
    cout << elmcount << " ";
    rep(j, elmcount) {
      if (i > j) {
        sets[i][j] = sets[j][i - 1];
      } else {
        sets[i][j] = used;
        used++;
      }
      cout << sets[i][j] << ((j == elmcount - 1) ? "\n" : " ");
    }
  }
}

