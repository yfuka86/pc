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

vector<int> vec_input(int n) {
  vector<int> v;
  int t = 0;
  for(int i = 0;i < n;i++){
    cin >> t;
    v.push_back(t);
  }
  return v;
}

int main()
{
  string a, b;
  cin >> a >> b;
  reverse(all(a));
  reverse(all(b));

  int size = min(a.size(), b.size());

  rep(i, size) {
    int r = int(a[i] - '0') + int(b[i] - '0');
    if (r >= 10) {
      cout << "Hard" << endl;
      return 0;
    }
  }
  cout << "Easy" << endl;
}

