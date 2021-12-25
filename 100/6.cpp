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
  int N;
  string S;
  cin >> N >> S;

  int count = 0;

  vector<bool> first(10, false);
  rep(i, N) {
    int d = S[i] - '0';
    if (first[d]) continue;
    first[d] = true;

    vector<bool> second(10, false);
    rep2(j, i + 1, N) {
      int d = S[j] - '0';
      if (second[d]) continue;
      second[d] = true;

      vector<bool> third(10, false);
      rep2(k, j + 1, N) {
        int d = S[k] - '0';
        if (third[d]) continue;
        third[d] = true;
        count++;
      }
    }
  }

  cout << count << endl;
}

