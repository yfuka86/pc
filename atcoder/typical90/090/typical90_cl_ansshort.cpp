#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<mint> inv(vector<mint> &F, int d) {
  vector<mint> G = {1};
  for(int m = 1; m <= d; m <<= 1) {
    vector<mint> P = convolution(vector<mint> (F.begin(), F.begin() + min(2 * m, (int)F.size())), G);
    vector<mint> Q(2 * m);
    Q[0] = 1;
    for(int i = m; i < 2 * m; i++) {
      Q[i] = -P[i];
    }
    G = convolution(Q, G);
  }
  G.resize(d + 1);
  return G;
}

mint poly_coeff(vector<mint> Q, vector<mint> P, long k) {
  for(; k; k >>= 1) {
    int n = Q.size();
    vector<mint> R(n);
    for(int i = 0; i < n; i++) R[i] = i & 1 ? -Q[i] : Q[i];
    P = convolution(P, R);
    Q = convolution(Q, R);
    vector<mint> S, T;
    for(int i = k & 1; i < P.size(); i += 2) S.push_back(P[i]);
    for(int i = 0; i < Q.size(); i += 2) T.push_back(Q[i]);
    swap(P, S);
    swap(Q, T);
  }
  return P[0];
}

int main() {
  long n, k;
  cin >> n >> k;
  vector<mint> F = {1, 1}, G;
  for(int m = k - 1; m >= 0; m--) {
    G.resize(F.size() + 1);
    G[0] = 1;
    for(int i = 0; i < F.size(); i++) G[i+1] = -F[i];
    if (m) {
      int c = k / m;
      F = convolution(F, inv(G, c));
      F.resize(c + 1);
    } else break;
  }
  mint ans = poly_coeff(G, F, n);
  cout << ans.val() << '\n';
}
