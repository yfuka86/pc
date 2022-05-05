{
    ll x = 2;
    while (x * i <= K) {
      cnt[i] -= cnt[x * i];
      x++;
    }
  }