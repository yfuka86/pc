ll solve(ll N, vl a) {
  ll ans; return ans;
}

ll naive(ll N, vl a) {
  ll ans; return ans;
}

void execute() {
  solve(); return;
  RandGen rg; ll c = 0, loop = 10;
  while (true) {
    c++; if (c % loop == 0) cout << "reached " << c / loop << "loop" <<  "\n", cout.flush();
    ll N = 10;
    vl a = rg.vecl(N, 1, 1e2);
    auto s = solve(N, a); auto n = naive(N, a);
    if (n != s) {
      cout << c << "times tried" << "\n";
      cout << N << "\n"; coutarray(a);
      cout << "solve: " << s << "\n";
      cout << "naive: " << n << "\n";
      break;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(12);
  int t = 1; //cin >> t;
  while (t--) execute();
}
