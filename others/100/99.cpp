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
typedef pair<int, int> P;
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
  ll M;
  cin >> M;

  ll count = 0;
  vector<int> lasts(M);
  rep(i, M) {
    ll d, c;
    cin >> d >> c;

    if (d == 0) {
      count += (c - 1);
      lasts[i] = 0;
    } else {
      ll last = d * c % 9 == 0 ? 9 : d * c % 9;
      ll carry = (d * c - last) / 9;
      count += c - 1 + carry;
      lasts[i] = last;
    }
  }

  ll lastsum = accumulate(all(lasts), 0LL);
  ll last = lastsum % 9 == 0 ? 9 : lastsum % 9;
  ll carry = (lastsum - last) / 9;
  count += carry + M - 1;

  cout << count << endl;
}

