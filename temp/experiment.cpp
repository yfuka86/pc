vl naive(ll N, vl a) {
  vl ans;
  return ans;
}

vl solve(ll N, vl a) {
  // ll N; cin >> N;
  // vl a(N); rep(i, N) cin >> a[i];
  vl ans;
  return ans;
}

void compare() {
  RandGen rg;
  ll c = 0, loop = 10;
  while (true) {
    c++; if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll N = 15;
    vl a = rg.vlint(N, 1, 1e1);
    vl b = rg.vlint(N, 1, 1e1);
    vl n = naive(N, a);
    vl s = solve(N, a);
    if (n != s) {
      cout << c << "times tried" << "\n";
      cout << N << "\n";
      coutarray(a);
      cout << "naive:" << "\n";
      coutarray(n);
      cout << "solve:" << "\n";
      coutarray(s);
      break;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1; //cin >> t;
  while (t--) compare();
}
