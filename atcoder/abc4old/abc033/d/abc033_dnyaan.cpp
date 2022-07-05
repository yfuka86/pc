#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i,N) for(long long i = 0; i < (long long)(N); i++)
#define repr(i,N) for(long long i = (long long)(N) - 1; i >= 0; i--)
#define rep1(i,N) for(long long i = 1; i <= (long long)(N) ; i++)
#define repr1(i,N) for(long long i = (N) ; (long long)(i) > 0 ; i--)
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
using namespace std; void solve();
using ll = long long; template<class T = ll> using V = vector<T>;
using vi = V<int>; using vl = V<>; using vvi = V< V<int> >;
constexpr int inf = 1001001001; constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(7);} } iosetupnya;
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { int s = (int)v.size(); rep(i,s) os << (i ? " " : "") << v[i]; return os; }
template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &x : v) is >> x; return is; }
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}
#ifdef NyaanDebug
  #include "NyaanDebug.h"
  #define trc(...) do { cerr << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,N) do { cerr << #v << " = "; array_out(v , N);cout << endl;} while(0)
#else
  #define trc(...)
  #define trca(...)
  int main(){solve();}
#endif

using P = pair<ll,ll>; using vp = V<P>;
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
//////////

using Real = long double;
using Point = complex< Real >;
using Points = vector< Point >;
constexpr Real EPS = 1e-15; // 問題によって変える！
constexpr Real pi = 3.141592653589793238462643383279L;
istream &operator>>(istream &is, Point &p) {
  Real a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}
ostream &operator<<(ostream &os, Point &p) {
  return os << real(p) << " " << imag(p);
}
inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

Point operator*(const Point &p, const Real &d) {
  return Point(real(p) * d, imag(p) * d);
}

namespace std {
  bool operator<(const Point &a, const Point &b) {
    return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
  }
}

Real cross(const Point &a, const Point &b) {
  return real(a) * imag(b) - imag(a) * real(b);
}
Real dot(const Point &a, const Point &b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

// 偏角ソート
// 与えられた中心と点集合に対して、偏角のリストを返す
vector<Real> arg_sort(Point &a , Points ps){
  vector<Real> ret;
  for(Point& p : ps) if(a != p) ret.push_back(atan2(p.imag() - a.imag(), p.real() - a.real()));
  sort(begin(ret) , end(ret));
  return ret;
};

// ccw 点の進行方向
int ccw(const Point &a, Point b, Point c) {
  b = b - a, c = c - a;
  if(cross(b, c) > EPS) return +1;  // 反時計回り
  if(cross(b, c) < -EPS) return -1; // 時計回り
  if(dot(b, c) < 0) return +2;      // c-a-bの順で一直線
  if(norm(b) < norm(c)) return -2;  // a-b-cの順で一直線
  return 0;                         // a-c-bの順で一直線
}

// a-bベクトルとb-cベクトルのなす角度のうち小さい方を返す
// (ベクトル同士のなす角、すなわち幾何でいうところの「外角」であることに注意！)
// rem. 凸包に対して反時計回りにこの関数を適用すると、
// 凸包の大きさにかかわらず和が360度になる(いわゆる外角の和)(AGC021-B)
Real get_angle(const Point &a, const Point &b, const Point &c) {
  const Point v(b - a), w(c - b);
  Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
  if(alpha > beta) swap(alpha, beta);
  Real theta = (beta - alpha);
  return min(theta, 2 * acos(-1) - theta);
}

//　反時計回りである自己交差のない多角形のclass
using Polygon = vector<Point>;

// 凸包
Polygon convex_hull(vector<Point> ps){
int n = (int) ps.size(), k = 0;
  if(n <= 2) return ps;
  sort(ps.begin(), ps.end());
  vector< Point > ch(2 * n);
  // 反時計周りに凸包を構築していく
  for(int i = 0; i < n; ch[k++] = ps[i++]) {
    // 条件分岐内はwhile(k >= 2 && ccw(ch[k-2],ch[k-1],ps[i]) != 1)と等価
    while(k >= 2 && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < EPS) --k;
  }
  for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) {
    while(k >= t && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < EPS) --k;
  }
  ch.resize(k - 1);
  return ch;
}

// 多角形の面積
Real area(const Polygon &p) {
  Real A = 0;
  for(int i = 0; i < (int)p.size(); ++i) {
    A += cross(p[i], p[(i + 1) % p.size()]);
  }
  return A * 0.5;
}

void solve(){
  inl(N);
  Points ps(N); in(ps);
  ll cho = 0 , don = 0;
  trc(ps);
  rep(i , N){
    auto arg = arg_sort(ps[i] , ps);
    assert((int)arg.size() == N - 1);

    rep(i , N - 1) arg.pb(arg[i] + 2 * pi);
    trc(i , arg);
    rep(j , N - 1){
      // a[i]を中心、arg[j]を時計回り手前側の端点とする
      // ちょうど90度をなす…直角
      // ちょうど90 ~ 180度をなす... 鈍角
      auto it1 = upper_bound(begin(arg) + j , begin(arg) + j + N - 1 , arg[j] + pi / 2 - EPS);
      auto it2 = upper_bound(begin(arg) + j , begin(arg) + j + N - 1 , arg[j] + pi - EPS);
      don += (it2 - it1);
      if( *it1 - arg[j] - pi / 2 < EPS) cho++ , don--;
    }
  }
  out(N * (N - 1) * (N - 2) / 6 - cho - don , cho , don);

}
