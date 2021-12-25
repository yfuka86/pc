#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int> > v;
  int t = 0;
  rep(i, n){
    vector<int> temp;
    rep(j, m) {
      cin >> t;
      temp.push_back(t);
    }
    v.push_back(temp);
  }

  ll rec = 0;
  rep(i, m) {
    rep(j, m) {
      ll sum = 0;
      rep(k, n) {
        sum += max(v[k][i], v[k][j]);
      }
      if (sum > rec) rec = sum;
    }
  }

  cout << rec << endl;
}

