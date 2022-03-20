#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

using Fp = modint998244353;

Fp factpow(int n, int k) {
  Fp ret = 1;
  for (int i = 0; i < k; ++i) {
    ret *= n - i;
  }
  return ret;
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int& x : A) {
    cin >> x;
  }
  vector<Fp> dp = {1};
  for (int x : A) {
    vector<Fp> next(dp.size() + 1);
    for (int i = 0; i < (int)dp.size(); ++i) {
      next[i] += dp[i];
      next[i + 1] += dp[i] * x;
    }
    dp = move(next);
  }
  Fp ans = 0;
  for (int n = 0; n <= N; ++n) {
    if (N - n <= K) {
      ans += dp[n] * factpow(K, N - n) * Fp(N).pow(K - (N - n));
    }
  }
  cout << (ans / (Fp(N).pow(K))).val() << '\n';
}
