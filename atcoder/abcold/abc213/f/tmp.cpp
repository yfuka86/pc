ep(i, N - 1) {
    d.add(-lcpa[i], 1);
    // cout << d.tot << "\n";
    dp[i] -= d.tot;
  }