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
  cin >> N;

  vector<int> S(N), P(N), Q(N);

  rep(i, N) S[i] = i + 1;
  rep(i, N) cin >> P[i];
  rep(i, N) cin >> Q[i];

  int counter = 0, pcount = 0, qcount = 0;

  do {
    counter++;
    if (S == P) pcount = counter;
    if (S == Q) qcount = counter;
  } while ((pcount == 0 || qcount == 0) && next_permutation(all(S)));

  cout << abs(pcount - qcount) << endl;
}

