
  // rep(i, N) {
  //   rep(k, kfreq + 1) {
  //     rep(e, efreq + 1) {
  //       ll offset = 0;
  //       rep(kk, k) { if (index[0][kk] >= i) offset++; }
  //       rep(ee, e) { if (index[1][ee] >= i) offset++; }
  //       rep(yy, i - k - e) { if (index[2][yy] >= i) offset++; }
  //       ll d = offset - i;

  //       rep(n, 499) {
  //         if (!dp[i][k][e][n]) continue;
  //         if (k < kfreq) dp[i + 1][k + 1][e][n + index[0][k] + d] += dp[i][k][e][n];
  //         if (e < efreq) dp[i + 1][k][e + 1][n + index[1][e] + d] += dp[i][k][e][n];
  //         if (i - k - e < yfreq) dp[i + 1][k][e][n + index[2][i - k - e] + d] += dp[i][k][e][n];
  //       }
  //     }
  //   }
  // }