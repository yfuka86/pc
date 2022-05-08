#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n=0;
  cin >> n;

  vector<int> v(n);
  int t=0;
  for(int i=0;i<n;i++){
    cin >> t;
    v[i] = t;
  }

  sort(v.begin(), v.end(), greater<int>());

  int last_size = 0;
  int count = 0;
  for(int i=0;i<n;i++) {
    if (i==0 || v[i] < last_size) {
      last_size = v[i];
      count++;
    }
  }

  cout << count << endl;
}
