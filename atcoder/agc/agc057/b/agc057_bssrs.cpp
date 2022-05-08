#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
  for (int i = 0; i < N; i++){
    pq.push(make_pair(A[i], A[i]));
  }
  multiset<long long> mn, mx;
  for (int i = 0; i < N; i++){
    mn.insert(A[i]);
    mx.insert(A[i]);
  }
  long long ans = max(*prev(mn.end()) - *mx.begin(), (long long) 0);
  for (int i = 0; i < N * 32; i++){
    long long cmx = pq.top().first;
    long long cmn = pq.top().second;
    pq.pop();
    mn.erase(mn.find(cmn));
    mx.erase(mx.find(cmx));
    cmn = cmn * 2;
    cmx = cmx * 2 + X;
    pq.push(make_pair(cmx, cmn));
    mn.insert(cmn);
    mx.insert(cmx);
    ans = min(ans, max(*prev(mn.end()) - *mx.begin(), (long long) 0));
  }
  cout << ans << endl;
}
