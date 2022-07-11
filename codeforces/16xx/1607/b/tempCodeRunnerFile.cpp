f (n & 1) {
    ll j = (n + 1) / 2;
    cout << (x & 1 ? x + j : x - j)  << "\n";
  } else {
    ll j = n / 2;
    cout << (x & 1 ? x - j : x + j) << "\n";
  }