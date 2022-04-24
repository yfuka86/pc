#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> t(N + 1), y(N + 1);
  t[0] = 1;
  y[0] = 0;
  for (int i = 1; i <= N; i++){
    cin >> t[i] >> y[i];
  }
  priority_queue<long long> pq;
  long long sum = 0;
  long long ans = -INF;
  for (int i = N; i >= 0; i--){
    if (t[i] == 1){
      ans = max(ans, y[i] + sum);
      K--;
    }
    if (t[i] == 2){
      if (y[i] > 0){
        sum += y[i];
      } else {
        pq.push(y[i]);
      }
    }
    if (K < 0){
      break;
    }
    while (pq.size() > K){
      sum += pq.top();
      pq.pop();
    }
  }
  cout << ans << endl;
}
