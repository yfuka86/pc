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
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int sum = 0;

  if (C * 2 < A) {
    sum += C * 2 * X;
    Y -= X;
    X = 0;
    if (Y <= 0) {cout << sum << endl; return 0;}
  }
  if (C * 2 < B) {
    sum += C * 2 * Y;
    X -= Y;
    Y = 0;
    if (X <= 0) {cout << sum << endl; return 0;}
  }

  if (C * 2 < A + B) {
    int mi = min(X, Y);
    sum += mi * 2 * C;
    X -= mi;
    Y -= mi;
  }

  sum += X * A;
  sum += Y * B;

  cout << sum << endl;
}

