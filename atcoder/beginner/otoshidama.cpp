#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n = 0, y = 0;
  cin >> n >> y;

  y /= 1000;

  int possible_ten = y / 10;
  int ten = 0;
  int five = 0;
  int one = 0;

  for(int i = 0; i <= possible_ten; i++) {
    int remain_n = n - i;
    int remain_y = y - (10 * i);
    ten = i;
    five = (remain_y - remain_n) / 4;
    one = remain_n - five;
    if (five >= 0 && one >= 0 && (five * 5 + one) == remain_y) {
      cout << ten << " " << five << " " << one << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
}
