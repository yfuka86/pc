template<class T> void flip(vector<vector<T>> &a) {
  assert(a.size() == a[0].size());
  rep(i, a.size()) rep(j, i) {
    swap(a[i][j], a[j][i]);
  }
}
// template<class T> vector<vector<T>> rotate(vector<vector<T>> &a) {
//   assert(a.size() == a[0].size());
//   ll n = a.size();
//   vector<vector<T>> ret(n, vector<T>(n, 0));
//   rep(i, n) rep(j, n) ret[j][n - 1 - i] = a[i][j];
//   return ret;
// }

template<class T> vector<vector<T>> rotate(vector<vector<T>> &a) {
  ll n = a.size(), m = a[0].size();
  vector<vector<T>> ret(m, vector<T>(n, 0));
  rep(i, n) rep(j, m) ret[j][n - 1 - i] = a[i][j];
  return ret;
}

template<typename T> vector<vector<T>> m_e(ll sz) { assert(sz > 0); vector<vector<T>> ret(sz, vector<T>(sz, T())); rep(i, sz) ret[i][i] = 1; return ret; }
template<typename T> vector<T> m_map(vector<vector<T>> l, vector<T> r) {
  assert(l.size() > 0 || r.size() > 0); assert(l[0].size() == r.size()); vector<T> ans(l.size(), 0);
  for(int i = 0; i < l.size(); i++) for (int j = 0; j < r.size(); j++) ans[i] += l[i][j] * r[j]; return ans; }
template<typename T> vector<vector<T>> m_product(vector<vector<T>> l, vector<vector<T>> r) {
  assert(l.size() > 0 || r.size() > 0); assert(l[0].size() == r.size());
  vector<vector<T>> ans(l.size(), vector<T>(r[0].size(), 0));
  for(int i = 0; i < l.size(); i++) { assert(l[i].size() == l[0].size());
    for(int j = 0; j < r[0].size(); j++) for(int k = 0; k < l[0].size(); k++) { assert(r[k].size() == r[0].size()); ans[i][j] += l[i][k] * r[k][j]; }
  }
  return ans; }
template <typename T> vector<vector<T>> m_pow(vector<vector<T>> m, ll n) { assert(n >= 0); if (!n) return m_e<T>((ll)m.size()); vector<vector<T>> res = m; n--; for(; n; n >>= 1, m = m_product(m, m)) if(n & 1) res = m_product(res, m); return res; }

// https://nyaannyaan.github.io/library/matrix/matrix.hpp
template <class T>
struct Matrix {
  vector<vector<T> > A;

  Matrix() = default;
  Matrix(int n, int m) : A(n, vector<T>(m, T())) {}
  Matrix(int n) : A(n, vector<T>(n, T())){};
  Matrix(vector<vector<T>> &a) { A = a; }
  int H() const { return A.size(); }
  int W() const { return A[0].size(); }
  int size() const { return A.size(); }
  inline const vector<T> &operator[](int k) const { return A[k]; }
  inline vector<T> &operator[](int k) { return A[k]; }
  static Matrix I(int n) {
    Matrix mat(n);
    for (int i = 0; i < n; i++) mat[i][i] = 1;
    return (mat);
  }
  Matrix &operator+=(const Matrix &B) {
    int n = H(), m = W();
    assert(n == B.H() && m == B.W());
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];
    return (*this);
  }
  Matrix &operator-=(const Matrix &B) {
    int n = H(), m = W();
    assert(n == B.H() && m == B.W());
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];
    return (*this);
  }
  Matrix &operator*=(const Matrix &B) {
    int n = H(), m = B.W(), p = W();
    assert(p == B.H());
    vector<vector<T> > C(n, vector<T>(m, T{}));
    for (int i = 0; i < n; i++)
      for (int k = 0; k < p; k++)
        for (int j = 0; j < m; j++) C[i][j] += (*this)[i][k] * B[k][j];
    A.swap(C);
    return (*this);
  }
  Matrix &operator^=(long long k) {
    Matrix B = Matrix::I(H());
    while (k > 0) {
      if (k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }
  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }
  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }
  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }
  Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }
  bool operator==(const Matrix &B) const {
    assert(H() == B.H() && W() == B.W());
    for (int i = 0; i < H(); i++)
      for (int j = 0; j < W(); j++)
        if (A[i][j] != B[i][j]) return false;
    return true;
  }
  bool operator!=(const Matrix &B) const {
    assert(H() == B.H() && W() == B.W());
    for (int i = 0; i < H(); i++)
      for (int j = 0; j < W(); j++)
        if (A[i][j] != B[i][j]) return true;
    return false;
  }
  friend ostream &operator<<(ostream &os, const Matrix &p) {
    int n = p.H(), m = p.W();
    for (int i = 0; i < n; i++) {
      os << (i ? "   " : "") << "[";
      for (int j = 0; j < m; j++) {
        os << p[i][j] << (j + 1 == m ? "]\n" : ",");
      }
    }
    return (os);
  }
  T determinant() const {
    Matrix B(*this);
    assert(H() == W());
    T ret = 1;
    for (int i = 0; i < H(); i++) {
      int idx = -1;
      for (int j = i; j < W(); j++) {
        if (B[j][i] != 0) {
          idx = j;
          break;
        }
      }
      if (idx == -1) return 0;
      if (i != idx) {
        ret *= T(-1);
        swap(B[i], B[idx]);
      }
      ret *= B[i][i];
      T inv = T(1) / B[i][i];
      for (int j = 0; j < W(); j++) {
        B[i][j] *= inv;
      }
      for (int j = i + 1; j < H(); j++) {
        T a = B[j][i];
        if (a == 0) continue;
        for (int k = i; k < W(); k++) {
          B[j][k] -= B[i][k] * a;
        }
      }
    }
    return ret;
  }
};
