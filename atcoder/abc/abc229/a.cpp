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

int main()
{
  string s1, s2;
  cin >> s1 >> s2;

  if ((s1 == "#." && s2 == ".#") || (s1 == ".#" && s2 == "#.")) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}

