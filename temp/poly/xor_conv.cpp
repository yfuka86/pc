/**
 * @brief Fast Walsh Hadamard Transform (高速ウォルシュアダマール変換)
 */
template< typename T >
void fast_walsh_hadamard_transform(vector< T > &f, bool inv = false) {
  const int n = (int) f.size();
  assert((n & (n - 1)) == 0);
  for(int i = 1; i < n; i <<= 1) {
    for(int j = 0; j < n; j += i << 1) {
      for(int k = 0; k < i; k++) {
        T s = f[j + k], t = f[j + k + i];
        f[j + k] = s + t;
        f[j + k + i] = s - t;
      }
    }
  }
  if(inv) {
    T inv_n = T(1) / n;
    for(auto &x : f) x *= inv_n;
  }
}

/**
 * @brief Bitwise Xor Convolution (Bitwise-XOR畳み込み)
 */
template< typename T >
vector< T > bitwise_xor_convolution(vector< T > f, vector< T > g) {
  const int n = (int) f.size();
  assert(f.size() == g.size());
  assert((n & (n - 1)) == 0);
  fast_walsh_hadamard_transform(f, false);
  fast_walsh_hadamard_transform(g, false);
  for(int i = 0; i < n; i++) f[i] *= g[i];
  fast_walsh_hadamard_transform(f, true);
  return f;
}
