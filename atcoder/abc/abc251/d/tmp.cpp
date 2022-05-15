
  vl f(1000001, 0);

  rep(i, N) if (A[i] <= W) f[A[i]]++;
  rep(i, N) rep2(j, i + 1, N) if (A[i] + A[j] <= W) f[A[i] + A[j]]++;
  rep(i, N) rep2(j, i + 1, N) rep2(k, j + 1, N) if (A[i] + A[j] + A[k] <= W) f[A[i] + A[j] + A[k]]++;

  ll cnt = 0;
  rep2(i, 1, 1000001) {
    if (f[i] == 0) cnt++;
  }
  cout << cnt << "\n";