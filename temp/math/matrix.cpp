template<class T> void flip(vector<vector<T>> &a) {
  assert(a.size() == a[0].size());
  rep(i, a.size()) rep(j, i) {
    swap(a[i][j], a[j][i]);
  }
}

template<typename T> vector<T> m_map(vector<vector<T>>& l, vector<T>& r) {
  assert(l.size() > 0 || r.size() > 0); assert(l[0].size() == r.size()); vector<T> ans(l.size(), 0);
  for(int i = 0; i < l.size(); i++) for (int j = 0; j < r.size(); j++) ans[i] += l[i][j] * r[j]; return ans; }
template<typename T> vector<vector<T>> m_product(vector<vector<T>>& l, vector<vector<T>>& r) {
  assert(l.size() > 0 || r.size() > 0); assert(l[0].size() == r.size());
  vector<vector<T>> ans(l.size(), vector<T>(r[0].size(), 0));
  for(int i = 0; i < l.size(); i++) { assert(l[i].size() == l[0].size());
    for(int j = 0; j < r[0].size(); j++) for(int k = 0; k < l[0].size(); k++) { assert(r[k].size() == r[0].size()); ans[i][j] += l[i][k] * r[k][j]; }
  }
  return ans; }
template <typename T> T m_pow(T m, ll n) { T res = m; n--; for(; n; n >>= 1, m = m_product(m, m)) if(n & 1) res = m_product(res, m); return res; }

// https://judge.yosupo.jp/submission/91018
template<class T>
struct Matrix{
  size_t N, M;
  vector<T> a;
  Matrix(size_t N, size_t M): N(N), M(M), a(N * M){}
  Matrix(const vector<vector<T>>& b){
    N = b.size(); M = b[0].size();
    a.resize(N * M);
    for(size_t i = 0; i < N; i++) for(size_t j = 0; j < M; j++) a[i * M + j] = b[i][j];
  }
  static Matrix e(size_t N){
    Matrix a(N, N);
    for(size_t i = 0; i < N; i++) a[i * (N + 1)] = T{1};
    return a;
  }
  auto operator[](size_t i){ return a.begin() + i * M; }
  auto operator[](size_t i) const { return a.begin() + i * M; }
  bool operator==(const Matrix& b){ return a == b.a; }
  bool operator!=(const Matrix& b){ return a != b.a; }
  Matrix& operator+=(const Matrix& b){ for(size_t i = 0; i < N * M; i++) a[i] += b[i]; return *this; }
  Matrix operator+(const Matrix& b) const { return Matrix(*this) += b; }
  Matrix& operator-=(const Matrix& b){ for(size_t i = 0; i < N * M; i++) a[i] -= b[i]; return *this; }
  Matrix operator-(const Matrix& b) const { return Matrix(*this) -= b; }
  Matrix operator*(const Matrix& b){
    assert(M == b.N); const size_t K = b.M; Matrix c(N, K);
    for(size_t i = 0; i < N; i++) for(size_t j = 0; j < M; j++) for(size_t k = 0; k < K; k++) c[i][k] += a[i * M + j] * b[j][k];
    return c;
  }
  Matrix& operator*=(const Matrix& b){ return *this = a * b; }
  Matrix pow(long long r) const {
    if(r == 0) return e(N);
    if(r < 0) return inv().pow(-r);
    Matrix ans = e(N), A = *this;
    while(1){ if(r & 1) ans *= A; if(r == 1) return ans; A *= A; r >>= 1; }
  }
  Matrix inv() const {
    Matrix A = *this, B = e();
    for(size_t i = 0; i < N; i++){
      if(A[i][i] == 0) for(size_t j = i + 1; j < N; j++) if(A[j][i] != 0){
        swap(A[i], A[j]); swap(B[i], B[j]); break;
      }
      assert("this matrix is not regular." && A[i][i] != 0);
      const T x = T{1} / A[i][i];
      for(size_t k = i; k < N; k++) A[i][k] *= x;
      for(size_t k = 0; k < N; k++) B[i][k] *= x;
      for(size_t j = 0; j < N; j++) if(i != j){
        const T x = A[j][i];
        for(size_t k = i; k < N; k++) A[j][k] -= A[i][k] * x;
        for(size_t k = 0; k < N; k++) B[j][k] -= B[i][k] * x;
      }
    }
    return B;
  }
  T det() const {
    Matrix A = *this; T ans = 1;
    for(size_t i = 0; i < N; i++){
      if(A[i][i] == 0) for(size_t j = i + 1; j < N; j++) if(A[j][i] != 0){
        for(size_t k = i; k < N; k++) swap(A[i][k], A[j][k]);
        ans = -ans; break;
      }
      if(A[i][i] == 0) return 0;
      ans *= A[i][i];
      const T x = T{1} / A[i][i];
      for(size_t k = i; k < N; k++) A[i][k] *= x;
      for(size_t j = i + 1; j < N; j++){
        const T x = A[j][i];
        for(size_t k = i; k < N; k++) A[j][k] -= A[i][k] * x;
      }
    }
    return ans;
  }
};
