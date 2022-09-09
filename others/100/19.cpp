#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

// int binary_search(int d, int target, vector<int> stores) {
//   int size = stores.size();
//   int index = 0;
//   int cursor = size - 1;
//   int memo = min(target, d - target);

//   while(true) {
//     cursor = (cursor + 1) / 2;

//     if (target > stores[index]) {
//       index += cursor;
//     } else {
//       index -= cursor;
//     }

//     int direct = abs(target - stores[index]);
//     int diff = min(direct, d - direct);
//     if (diff < memo) memo = diff;

//     if (cursor == 1) break;
//   }
//   return memo;
// }

int dist(int d, int target, int store) {
  int direct = abs(target - store);
  return min(direct, d - direct);
}

int binary_search(int d, int target, vector<int> stores) {
  int size = stores.size();
  vector<int>::iterator iter_lower;
  ll idx;

  iter_lower = lower_bound(all(stores), target);
  if (iter_lower == stores.end()) {
    return min(dist(d, target, stores[0]), dist(d, target, stores[size - 1]));
  } else {
    idx = iter_lower - stores.begin();
    return min(dist(d, target, stores[idx]), dist(d, target, stores[idx - 1]));
  }
}

int main()
{
  // int d = 10000;
  // vector<int> v = {0,100,200,300,400,450,7000};
  // int t = 6500;
  // cout << binary_search(d, t, v) << endl;

  int d, n, m;
  cin >> d >> n >> m;

  vector<int> stores = {0};
  int t = 0;
  rep2(i, 1, n){
    cin >> t;
    stores.push_back(t);
  }
  sort(all(stores));

  vector<int> dests;
  rep(i, m) {
    cin >> t;
    dests.push_back(t);
  }
  sort(all(dests));

  int sum = 0;
  rep(i, m) {
    int target = dests[i];
    sum += binary_search(d, target, stores);
  }
  cout << sum << endl;
}

