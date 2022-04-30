rep(i, 3) {
    ll t = min(a[i], b[i]);
    a[i] -= t;
    b[i] -= t;
    ret += t;
  }