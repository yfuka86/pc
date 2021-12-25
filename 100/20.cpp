#include <iostream>
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
  int n;
  cin >> n;

  vector<int> a = vec_input(n), b = vec_input(n), c = vec_input(n);
  sort(all(a));
  sort(all(b));
  sort(all(c));

  ll sum = 0;
  rep(i, n) {
    auto a_itr = lower_bound(all(a), b[i]);
    ll possible_a = a_itr == a.end() ? n : distance(a.begin(), lower_bound(all(a), b[i]));
    auto c_itr = upper_bound(all(c), b[i]);
    ll possible_c = c_itr == c.end() ? 0 : n - distance(c.begin(), c_itr);
    sum += possible_a * possible_c;
  }
  cout << sum << endl;
}

