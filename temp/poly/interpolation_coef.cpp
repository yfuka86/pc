/**
 * @brief Lagrange Polynomial(多項式補間, 係数)
 */
template< typename mint >
vector< mint > lagrange_polynomial(const vector< mint > &x, const vector< mint > &y) {
  int k = (int) x.size() - 1;

  vector< mint > f(k + 1), dp(k + 2);
  dp[0] = 1;
  for(int j = 0; j <= k; j++) {
    for(int l = k + 1; l > 0; l--) {
      dp[l] = dp[l] * -x[j] + dp[l - 1];
    }
    dp[0] *= -x[j];
  }

  for(int i = 0; i <= k; i++) {
    mint d = 1;
    for(int j = 0; j <= k; j++) {
      if(i != j) {
        d *= x[i] - x[j];
      }
    }
    mint mul = y[i] / d;
    if(x[i] == 0) {
      for(int j = 0; j <= k; j++) {
        f[j] += dp[j + 1] * mul;
      }
    } else {
      mint inv = mint(1) / (-x[i]), pre = 0;
      for(int j = 0; j <= k; j++) {
        mint cur = (dp[j] - pre) * inv;
        f[j] += cur * mul;
        pre = cur;
      }
    }
  }
  return f;
}
