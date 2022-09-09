#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

const int SEARCH_TO = 100001;

vector<bool> is_prime(SEARCH_TO, false);

void enum_prime() {
  rep2(i, 2, SEARCH_TO) {
    is_prime[i] = true;
    for(int j = 2; j * j <= i; j++) {
      if (is_prime[j] && i % j == 0) {
        is_prime[i] = false;
        break;
      }
    }
  }
}

int main()
{
  enum_prime();
  vector<int> nums;
  rep(i, SEARCH_TO) {
    if (is_prime[i] & is_prime[(i + 1) / 2]) nums.push_back(i);
  }

  int Q;
  cin >> Q;

  rep(i, Q) {
    int l, r;
    cin >> l >> r;
    cout << upper_bound(all(nums), r) - lower_bound(all(nums), l) << endl;
    // 本来はある数までの個数をメモして、sum[r+1] - sum[l]とやるのが速いみたい
  }

  return 0;
}

