
    // 2つ一気に満たせるケース
    rep(i, n) rep(j, n) if (a[i][j] == -1) {
      if (s1.count(i) && t1.count(j)) {
        a[i][j] = 1; s1.erase(i); t1.erase(j);
      }
      if (s0.count(i) && t0.count(j)) {
        a[i][j] = 0; s0.erase(i); t0.erase(j);
      }
    }