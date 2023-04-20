// https://nyaannyaan.github.io/library/geometry/geometry.hpp
using Real = long double;
using Point = complex<Real>;
using Points = vector<Point>;
constexpr Real EPS = 1e-8;  // 問題によって変える！
constexpr Real pi = 3.141592653589793238462643383279L;
istream &operator>>(istream &is, Point &p) { Real a, b; is >> a >> b; p = Point(a, b); return is; }
ostream &operator<<(ostream &os, Point &p) { return os << real(p) << " " << imag(p); }
inline int sign(const Real &r) { return r <= -EPS ? -1 : r >= EPS ? 1 : 0; }
inline bool equals(Real a, Real b) { return fabs(b - a) < EPS; }
Point operator*(const Point &p, const Real &d) { return Point(real(p) * d, imag(p) * d); }
namespace std {
  bool operator<(const Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }
} // namespace std
Real cross(const Point &a, const Point &b) { return real(a) * imag(b) - imag(a) * real(b); }
Real dot(const Point &a, const Point &b) { return real(a) * real(b) + imag(a) * imag(b); }

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
  if (cross(b, c) > EPS) return +1;   // 反時計回り
  if (cross(b, c) < -EPS) return -1;  // 時計回り
  if (dot(b, c) < 0) return +2;       // c-a-bの順で一直線
  if (norm(b) < norm(c)) return -2;   // a-b-cの順で一直線
  return 0;                           // a-c-bの順で一直線
}
// a-bベクトルとb-cベクトルのなす角度のうち小さい方を返す
// (ベクトル同士のなす角、すなわち幾何でいうところの「外角」であることに注意！)
// rem. 凸包に対して反時計回りにこの関数を適用すると、
// 凸包の大きさにかかわらず和が360度になる(いわゆる外角の和)(AGC021-B)
Real get_angle(const Point &a, const Point &b, const Point &c) {
  const Point v(b - a), w(c - b);
  Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
  if (alpha > beta) swap(alpha, beta);
  Real theta = (beta - alpha);
  return min(theta, 2 * acos(-1) - theta);
}
// Line /////////////////////////////////////////////////////////////////////////////
struct Line {
  Point a, b;
  Line() = default;
  Line(const Point &a, const Point &b) : a(a), b(b) {}
  Line(const Real &A, const Real &B, const Real &C) { // Ax+By=C
    if(equals(A, 0)) { assert(!equals(B, 0)); a = Point(0, C / B); b = Point(1, C / B); }
    else if(equals(B, 0)) { a = Point(C / A, 0); b = Point(C / A, 1); }
    else { a = Point(0, C / B); b = Point(C / A, 0); }
  }
  friend ostream &operator<<(ostream &os, Line &l) { return os << l.a << " to " << l.b; }
  friend istream &operator>>(istream &is, Line &l) { return is >> l.a >> l.b; }
};
using Lines = vector< Line >;
// 交点
Point cross_point_ll(const Line &l, const Line &m) {
  Real A = cross(l.b - l.a, m.b - m.a), B = cross(l.b - l.a, l.b - m.a);
  if(equals(abs(A), 0) && equals(abs(B), 0)) return m.a;
  return m.a + (m.b - m.a) * B / A;
}

//　反時計回りである自己交差のない多角形のclass
using Polygon = vector<Point>;
// https://ei1333.github.io/library/geometry/contains.hppe
// in 1 on 0 out -1
int contains(const Polygon &Q, const Point &p) {
  bool in = false;
  for(int i = 0; i < Q.size(); i++) {
    Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
    if(imag(a) > imag(b)) swap(a, b);
    if(sign(imag(a)) <= 0 && 0 < sign(imag(b)) && sign(cross(a, b)) < 0) in = !in;
    if(equals(cross(a, b), 0) && sign(dot(a, b)) <= 0) return 0;
  }
  return in ? 1 : -1;
}
// 凸包
Polygon convex_hull(vector<Point> ps) {
  int n = (int)ps.size(), k = 0;
  if (n <= 2) return ps;
  sort(ps.begin(), ps.end());
  Polygon ch(2 * n);
  // 反時計周りに凸包を構築していく
  for (int i = 0; i < n; ch[k++] = ps[i++]) {
    // 条件分岐内はwhile(k >= 2 && ccw(ch[k-2],ch[k-1],ps[i]) != 1)と等価
    while (k >= 2 && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < EPS) --k;
  }
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) {
    while (k >= t && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < EPS) --k;
  }
  ch.resize(k - 1);
  return ch;
}
// 内部2, 線上1, 外部0
int convex_polygon_contains(const Polygon &Q, const Point &p) {
  int N = (int) Q.size();
  Point g = (Q[0] + Q[N / 3] + Q[N * 2 / 3]) / 3.0;
  if(equals(imag(g), imag(p)) && equals(real(g), real(p))) return 2;
  Point gp = p - g;
  int l = 0, r = N;
  while(r - l > 1) {
    int mid = (l + r) / 2;
    Point gl = Q[l] - g;
    Point gm = Q[mid] - g;
    if(cross(gl, gm) > 0) {
      if(cross(gl, gp) >= 0 && cross(gm, gp) <= 0) r = mid;
      else l = mid;
    } else {
      if(cross(gl, gp) <= 0 && cross(gm, gp) >= 0) l = mid;
      else r = mid;
    }
  }
  r %= N;
  Real v = cross(Q[l] - p, Q[r] - p);
  return sign(v) == 0 ? 1 : sign(v) == -1 ? 0 : 2;
}
Polygon convex_polygon_cut(const Polygon &U, const Line &l) {
  Polygon ret;
  for(int i = 0; i < U.size(); i++) {
    const Point &now = U[i];
    const Point &nxt = U[(i + 1) % U.size()];
    auto cf = cross(l.a - now, l.b - now);
    auto cs = cross(l.a - nxt, l.b - nxt);
    if(sign(cf) >= 0) {
      ret.emplace_back(now);
    }
    if(sign(cf) * sign(cs) < 0) {
      ret.emplace_back(cross_point_ll(Line(now, nxt), l));
    }
  }
  return ret;
}
// 多角形の面積
Real area(const Polygon &p) { Real A = 0;
  for (int i = 0; i < (int)p.size(); ++i) A += cross(p[i], p[(i + 1) % p.size()]);
  return A * 0.5;
}

struct Circle {
  Point p; Real r;
  Circle() = default;
  Circle(Point _p, Real _r) : p(_p), r(_r) {}
};
using Circles = vector<Circle>;
int intersect(Circle c1, Circle c2) {
  if (c1.r < c2.r) swap(c1, c2);
  Real d = abs(c1.p - c2.p);
  if (c1.r + c2.r < d) return 4;
  if (equals(c1.r + c2.r, d)) return 3;
  if (c1.r - c2.r < d) return 2;
  if (equals(c1.r - c2.r, d)) return 1;
  return 0;
}
pair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {
  Real d = abs(c1.p - c2.p);
  Real x = (c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d);
  if (abs(x) > 1) x = (x > 0 ? 1.0 : -1.0);
  Real a = acos(x);
  Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
  Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
  Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
  return {p1, p2};
}

///////////////////////////////////////////////////////////////////////////////////////////
// 以下自分のもの
// 三点の外接円
Circle circumcircle(const Point &p1, const Point &p2, const Point &p3) {
  // TODO 同一直線上チェック（今div == 0でやっている）
  Real a = abs(p2 - p3), b = abs(p1 - p3), c = abs(p1 - p2);
  Real a2 = a * a, b2 = b * b, c2 = c * c;
  Real ca = a2 * (b2 + c2 - a2), cb = b2 * (c2 + a2 - b2), cc = c2 * (a2 + b2 - c2);
  Real div = (ca + cb + cc);
  if (div == 0) return Circle{{LINF, LINF}, 0};
  Point ec = (p1 * ca + p2 * cb + p3 * cc) / div;
  return Circle{ec, abs(p1 - ec)};
}
