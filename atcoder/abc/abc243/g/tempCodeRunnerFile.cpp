+ 2, 4) - 1 > X) {
      for (ll i2 = POW(i + 1, 2); POW(i2, 2) - 1 <= X; i2++) {
        ans += dpsum[i + 1];
      }
    }