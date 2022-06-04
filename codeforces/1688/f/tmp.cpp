
  rep_r(i, m) {
    auto [r, l] = rng[i];
    if (aseg.prod(l, r).a + bseg.prod(l, r).a == csum[r] - csum[l]) {
      // cout << i << "applied" << "\n";
      aseg.apply(l, r, 0);
      bseg.apply(l, r, 1);
    }
  }