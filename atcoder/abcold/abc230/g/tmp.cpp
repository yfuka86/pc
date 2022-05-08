
  // vl c2(n + 1);
  // rep(i, n + 1) c2[i] = ll(i + 1) * i / 2;

  // ll ans = 0;
  // rep2(k, 2, n + 1) {
  //   if (mu[k] == 0) continue;
  //   ll now = 0;
  //   map<ll, ll> s;
  //   for (ll i = k; i <= n; i += k) {
  //     for (ll x: ds[p[i]]) s[x]++;
  //   }
  //   for (auto [_, cnt]: s) now += c2[cnt];
  //   ans += now * mu[k];
  // }
  // cout << ans << 