namespace FastFourierTransform {
  using real = double;

  struct C {
    real x, y;

    C() : x(0), y(0) {}

    C(real x, real y) : x(x), y(y) {}

    inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

    inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

    inline C operator*(const C &c) const { return C(x * c.x - y * c.y, x * c.y + y * c.x); }

    inline C conj() const { return C(x, -y); }
  };

  const real PI = acosl(-1);
  int base = 1;
  vector< C > rts = { {0, 0},
                     {1, 0} };
  vector< int > rev = {0, 1};


  void ensure_base(int nbase) {
    if(nbase <= base) return;
    rev.resize(1 << nbase);
    rts.resize(1 << nbase);
    for(int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    while(base < nbase) {
      real angle = PI * 2.0 / (1 << (base + 1));
      for(int i = 1 << (base - 1); i < (1 << base); i++) {
        rts[i << 1] = rts[i];
        real angle_i = angle * (2 * i + 1 - (1 << base));
        rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
      }
      ++base;
    }
  }

  void fft(vector< C > &a, int n) {
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for(int i = 0; i < n; i++) {
      if(i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for(int k = 1; k < n; k <<= 1) {
      for(int i = 0; i < n; i += 2 * k) {
        for(int j = 0; j < k; j++) {
          C z = a[i + j + k] * rts[j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] = a[i + j] + z;
        }
      }
    }
  }

  vector< int64_t > multiply(const vector< int > &a, const vector< int > &b) {
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 1;
    while((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    vector< C > fa(sz);
    for(int i = 0; i < sz; i++) {
      int x = (i < (int) a.size() ? a[i] : 0);
      int y = (i < (int) b.size() ? b[i] : 0);
      fa[i] = C(x, y);
    }
    fft(fa, sz);
    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
    for(int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
      fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
      fa[i] = z;
    }
    for(int i = 0; i < (sz >> 1); i++) {
      C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
      C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
      fa[i] = A0 + A1 * s;
    }
    fft(fa, sz >> 1);
    vector< int64_t > ret(need);
    for(int i = 0; i < need; i++) {
      ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
    }
    return ret;
  }
};

template< typename T >
struct ArbitraryModConvolution {
  using real = FastFourierTransform::real;
  using C = FastFourierTransform::C;

  ArbitraryModConvolution() = default;

  static vector< T > multiply(const vector< T > &a, const vector< T > &b, int need = -1) {
    if(need == -1) need = a.size() + b.size() - 1;
    int nbase = 0;
    while((1 << nbase) < need) nbase++;
    FastFourierTransform::ensure_base(nbase);
    int sz = 1 << nbase;
    vector< C > fa(sz);
    for(int i = 0; i < a.size(); i++) {
      fa[i] = C(a[i].x & ((1 << 15) - 1), a[i].x >> 15);
    }
    fft(fa, sz);
    vector< C > fb(sz);
    if(a == b) {
      fb = fa;
    } else {
      for(int i = 0; i < b.size(); i++) {
        fb[i] = C(b[i].x & ((1 << 15) - 1), b[i].x >> 15);
      }
      fft(fb, sz);
    }
    real ratio = 0.25 / sz;
    C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
    for(int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      C a1 = (fa[i] + fa[j].conj());
      C a2 = (fa[i] - fa[j].conj()) * r2;
      C b1 = (fb[i] + fb[j].conj()) * r3;
      C b2 = (fb[i] - fb[j].conj()) * r4;
      if(i != j) {
        C c1 = (fa[j] + fa[i].conj());
        C c2 = (fa[j] - fa[i].conj()) * r2;
        C d1 = (fb[j] + fb[i].conj()) * r3;
        C d2 = (fb[j] - fb[i].conj()) * r4;
        fa[i] = c1 * d1 + c2 * d2 * r5;
        fb[i] = c1 * d2 + c2 * d1;
      }
      fa[j] = a1 * b1 + a2 * b2 * r5;
      fb[j] = a1 * b2 + a2 * b1;
    }
    fft(fa, sz);
    fft(fb, sz);
    vector< T > ret(need);
    for(int i = 0; i < need; i++) {
      int64_t aa = llround(fa[i].x);
      int64_t bb = llround(fb[i].x);
      int64_t cc = llround(fa[i].y);
      aa = T(aa).x, bb = T(bb).x, cc = T(cc).x;
      ret[i] = aa + (bb << 15) + (cc << 30);
    }
    return ret;
  }
};
