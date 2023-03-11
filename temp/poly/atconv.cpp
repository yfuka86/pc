// 入出力マクロの上に
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353; using vmi = vector<mint>; using vvmi = vector<vmi>; using v3mi = vector<vvmi>; using v4mi = vector<v3mi>;
const ll mod = 998244353;
istream& operator>>(istream& in, mint &a) { long long e; in >> e; a = e; return in; }
ostream& operator<<(ostream& out, mint &a) { return out << a.val(); }
template<class T> istream &operator>>(istream &is, vector<T> &v) { for (auto &e : v) is >> const_cast<T&>(e); return is; }
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << const_cast<T&>(e) << ' '; return os; }
//------------------------------------------------------------------------------
// Nlog^2Nで複数配列を効率よくたたみ込むもの
vmi all_convolution(vvmi &a) {
  multimap<ll, vmi> que;
  for (auto &v: a) que.emplace(v.size(), v);
  while (que.size() > 1) {
    vmi a = que.begin()->se; que.erase(que.begin());
    vmi b = que.begin()->se; que.erase(que.begin());
    vmi c = convolution(a, b);
    que.emplace(c.size(), c);
  }
  return que.begin()->se;
}
