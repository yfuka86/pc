
  // vector<FPS<mint>> fps(N);
  // rep(i, N) { FPS<mint> t(a[i] + 1, 1); fps[i] = t; }
  // vector<FPS<mint>> cum, rcum;
  // cum.pb(FPS<mint>{1});
  // rcum.pb(FPS<mint>{1});

  // rep(i, N) {
  //   cum.pb(cum.back() * fps[i]);
  //   if (cum.back().size() > M + 1) cum.back().resize(M + 1);
  // }
  // rep_r(i, N) {
  //   rcum.pb(rcum.back() * fps[i]);
  //   if (rcum.back().size() > M + 1) rcum.back().resize(M + 1);
  // }

  // rep(_, Q) {
  //   ll k, x; cin >> k >> x; k--;

  //   auto ans = cum[k] * rcum[N - k - 1];
  //   coutarray(ans);
  //   if (ans.size() <= M - x) cout << 0 << "\n";
  //   else cout << ans[M - x] << "\n";
  