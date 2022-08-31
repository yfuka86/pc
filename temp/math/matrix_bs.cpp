
using bs = bitset<128>;
using mat = array<bs, 100>;

mat mat_mul(mat A, mat B, int n) {
  mat C;
  rep(i, n) C[i].reset();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i].test(j)) C[i] |= B[j];
    }
  }
  return C;
}

mat mat_pow(mat a, int L, int n) {
  mat c;
  rep(i, n) {
    c[i].reset();
    c[i][i] = true;
  }
  while (L) {
    if (L & 1) c = mat_mul(a, c, n);
    L >>= 1;
    if (L) a = mat_mul(a, a, n);
  }
  return c;
}
