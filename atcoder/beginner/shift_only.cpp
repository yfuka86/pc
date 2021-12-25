#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> vec;

  for (int i = 0; i < n; i++) {
    int target, count = 0;
    cin >> target;
    while (target % 2 == 0) {
      target /= 2;
      count++;
    }
    vec.push_back(count);
  }

  int min = *min_element(vec.begin(), vec.end());
  cout << min;
}
