dexOf;
  // vmi dp(N, modint(0));
  // vmi dpsum(N + 1, modint(0));
  // dp[0] = modint(1); dpsum[1] = modint(1);
  // rep2(i, 1, N) {
  //   ll lasti = lastIndexOf.count(csum[i]) ? lastIndexOf[csum[i]] : 0;
  //   dp[i] += dpsum[i] - dpsum[lasti];
  //   dpsum[i + 1] = dpsum[i] + dp[i];
  //   lastIndexOf[csum[i]] = i;
  // }