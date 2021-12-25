#include <iostream>
#include <queue>
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
  string S;
  int K;
  cin >> S >> K;

  int count = 0;

  int dot = 0;
  queue<char> temp;
  rep(i, S.size()) {
    temp.push(S[i]);
    if (S[i] != 'X') {
      dot++;
      if (dot > K) {
        while(true) {
          if (temp.front() == '.') {
            temp.pop();
            dot--;
            break;
          } else {
            temp.pop();
          }
        }
      }
    }
    if (count < temp.size()) count = temp.size();
  }

  cout << count << endl;
}
