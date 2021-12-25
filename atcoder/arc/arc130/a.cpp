#include <iostream>
#include <map>
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

ll cases(ll n) {
  return (n * (n - 1)) / 2;
}

int main()
{
  int N;
  string S;
  cin >> N >> S;

  ll sum = 0;
  ll temp = 1;
  rep(i, N - 1) {
    if (S[i] == S[i + 1]) {
      temp++;
    } else {
      sum += cases(temp);
      temp = 1;
    }
  }
  // last
  if (temp >= 2) {
    sum += cases(temp);
  }

  cout << sum << endl;
}

