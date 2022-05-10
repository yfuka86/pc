void compare() {
  RandGen rg;
  ll c = 0, loop = 10;
  while (true) {
    c++; if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n";
    ll N = rg.lint(1, 1e2);
    vl A = rg.vlint(N, 1, 1e1);
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

void enum_perm(ll N, ll from, ll to) { // [from, to)
  vl st; rep(i, N) st.pb(from);
  while (true) {
    if (1) {
      coutarray(st);
      cout << check(st) << "\n";
    }

    while (st.back() == to) st.pop_back();
    if (st.size() == 0) break;
    st.back()++;
    while (st.size() < N) st.pb(from);
  }
}
