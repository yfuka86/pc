#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main()
{
  string s;
  cin >> s;

  char list[] = {'A', 'C', 'G', 'T'};

  int max = 0, temp = 0;

  rep(i, s.size()) {
    if(find(list, list + 4, s[i]) != list + 4) {
      temp++;
      if (temp > max) max = temp;
    } else {
      temp = 0;
    }
  }

  cout << max << endl;
}
