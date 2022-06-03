 - 2);

  // rep(i, 1 << N) {
  //   if (!(i & 1) || !(i & 1 << N - 1)) continue;

  //   vl t;
  //   rep(j, N) {
  //     if (i & 1 << j) t.pb(1); else t.pb(0);
  //   }
  //   auto rl = RLE(t);
  //   bool valid = true;
  //   for (auto[b, c]: rl) {
  //     if (b == 1 && c >= K) { valid = false; break; }
  //   }
  //   if (!valid) ans--;
  // }
  // cout << ans << "\