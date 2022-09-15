// https://nyaannyaan.github.io/library/geometry/geometry.hpp

using Real = long double;
using Point = complex<Real>;
using Points = vector<Point>;
constexpr Real EPS = 1e-8;  // 問題によって変える！
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
}  // namespace std

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

// 以下は出現頻度少なめ
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

//　反時計回りである自己交差のない多角形のclass
using Polygon = vector<Point>;

// 凸包
Polygon convex_hull(vector<Point> ps) {
  int n = (int)ps.size(), k = 0;
  if (n <= 2) return ps;
  sort(ps.begin(), ps.end());
  vector<Point> ch(2 * n);
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

// 多角形の面積
Real area(const Polygon &p) {
  Real A = 0;
  for (int i = 0; i < (int)p.size(); ++i) {
    A += cross(p[i], p[(i + 1) % p.size()]);
  }
  return A * 0.5;
}

struct Circle {
  Point p;
  Real r;

  Circle() = default;
  Circle(Point _p, Real _r) : p(_p), r(_r) {}
};

using Circles = vector<Circle>;

int intersect(Circle c1, Circle c2) {
  if (c1.r < c2.r) swap(c1, c2);
  Real d = abs(c1.p - c2.p);
  if (c1.r + c2.r < d) return 4;
  if (eq(c1.r + c2.r, d)) return 3;
  if (c1.r - c2.r < d) return 2;
  if (eq(c1.r - c2.r, d)) return 1;
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


// 以下yfuka86
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

// 直線系
// https://github.com/noshi91/NoshiMochiLibrary/blob/master/Geometory/Geometry.Kutimoti.cpp
struct Line {
  Point from, to;
  Line(Point from = Point(), Point to = Point()) : from(from), to(to) {}
};

struct Segment {
  Point from, to;
  Segment(Point from = Point(), Point to = Point()) : from(from), to(to) {}
};

bool is_orthogonal(const Line& la, const Line& lb) {
  return eq(0.0, dot(la.from - la.to, lb.from - lb.from));
}
bool is_parallel(const Line& la, const Line& lb) {
  return eq(0.0, cross(la.from - la.to, lb.from - lb.from));
}
bool is_Point_on(const Line& l, const Point& p) {
  return eq(0.0, cross(l.to - l.from, p - l.from));
}
bool is_Point_on(const Segment& s, const Point& p) {
  return (s.from - p).abs() + (p - s.to).abs() < (s.from - s.to).abs() + EPS;
}
ld distance(const Line& l, const Point& p) {
  return abs(cross(l.to - l.from, p - l.from)) / (l.to - l.from).abs();
}
ld distance(const Segment& s, const Point& p) {
  if (dot(s.to - s.from, p - s.from) < EPS) return (p - s.from).abs();
  if (dot(s.from - s.to, p - s.to) < EPS) return (p - s.to).abs();
  return abs(cross(s.to - s.from, p - s.from)) / (s.to - s.from).abs();
}
ld is_intersected(const Segment& a, const Segment& b) {
  return (cross(a.to - a.from, b.from - a.from) *
              cross(a.to - a.from, b.to - a.from) <
          EPS) &&
          (cross(b.to - b.from, a.from - b.from) *
              cross(b.to - b.from, a.to - b.from) <
          EPS);
}

Point intersection_point(const Segment& a, const Segment& b) {
  Point bp = b.to - b.from;
  ld d1 = abs(cross(bp, a.from - b.from));
  ld d2 = abs(cross(bp, a.to - b.from));
  ld t = d1 / (d1 + d2);
  return a.from + (a.to - a.from) * t;
}

Point intersection_point(const Line& a, const Line& b) {
  Point ap = a.to - a.from;
  Point bp = b.to - b.from;
  return a.from + ap * cross(bp, b.from - a.from) / cross(bp, ap);
}
