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

  while (s.size() > 0) {
    if (s.find("eraser") == 0){
      s = s.substr(6);
    } else if (s.find("erase") == 0){
      s = s.substr(5);
    } else if (s.find("dreamer") == 0){
      if (s[7] == 'a') {
        s = s.substr(5);
      } else {
        s = s.substr(7);
      }
    } else if (s.find("dream") == 0){
      s = s.substr(5);
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
