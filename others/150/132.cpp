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
#define vi vector<int>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;

int bitcount(int n) { int c = 0; for ( ; n != 0 ; n &= n - 1 ) c++; return c;}

int N;
vi BIT;

void add(int loc, int value){
	BIT[loc] += value;
	loc += loc & -loc;

	while(loc <= N){
		BIT[loc] += value;
		loc += loc & -loc;
	}
}

int getSum(int loc){
	int sum = BIT[loc];
	loc -= loc & -loc;

	while(loc > 0){
		sum += BIT[loc];
		loc -= loc & -loc;
	}
	return sum;
}

int calc(int left, int right){
	return getSum(right) - getSum(left - 1);
}

int main()
{
  int q;
  cin >> N >> q;
  BIT.resize(N + 1);
  BIT.assign(N + 1, 0);

  rep(i, q) {
    int com, x, y; cin >> com >> x >> y;
    if (com == 0) {
      add(x, y);
    } else cout << calc(x, y) << endl;
  }
}

