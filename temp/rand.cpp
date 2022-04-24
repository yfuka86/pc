void compare() {
  RandGen rg;
  while (true) {
    ll N = rg.lint(1, 1e2);
    vl A = rg.vlint(1, 1e5, N);
    ll s = solve(N, A); ll n = naive(N, A);
    if (s != n) {
      cout << N << "\n";
      coutarray(A);
      cout << "naive:" << n << "\n";
      cout << "solve:" << s << "\n";
      break;
    }
  }
}

ll solve(ll N, vl A) {
}

