// https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <math.h>
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
  cin >> N;
  vector<ll> a(N);
  vector<ll> sorta(N);
  vector<ll> b(N);
  vector<ll> sortb(N);
  rep(i, N) {
    ll A, B;
    cin >> A >> B;
    a[i] = sorta[i] = A;
    b[i] = sortb[i] = B;
  }
  sort(all(sorta));
  sort(all(sortb));
  ll enter = sorta[N / 2];
  ll exit = sortb[N / 2];
  ll sum = 0;
  rep(i, N) {
    sum += abs(enter - a[i]);
    sum += abs(a[i] - b[i]);
    sum += abs(exit - b[i]);
  }
  cout << sum << endl;
}

