#line 1 "test/library_checker/convolution/contolution_mod_2_64.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_2_64"
#line 1 "my_template.hpp"
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

using ll = long long;
using ll8 = __int128;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using uint = unsigned int;
using ull = unsigned long long;

template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size) \
  vector<type> name(size);    \
  IN(name)
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  IN(name)
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR_(n) for (ll _ = 0; (_) < (ll)(n); ++(_))
#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return 31 - __builtin_clz(x); }
int topbit(uint x) { return 31 - __builtin_clz(x); }
int topbit(ll x) { return 63 - __builtin_clzll(x); }
int topbit(ull x) { return 63 - __builtin_clzll(x); }
// (0, 1, 2, 3, 4) -> (32 or 64, 0, 1, 0, 2)
int lowbit(int x) { return 31 - __builtin_clz(x); }
int lowbit(uint x) { return 31 - __builtin_clz(x); }
int lowbit(ll x) { return 63 - __builtin_clzll(x); }
int lowbit(ull x) { return 63 - __builtin_clzll(x); }

ll ceil(ll x, ll y) { return (x > 0 ? (x + y - 1) / y : x / y); }
ll floor(ll x, ll y) { return (x > 0 ? x / y : (x - y + 1) / y); }
pi divmod(ll x, ll y) {
  ll q = floor(x, y);
  return {q, x - q * y};
}

namespace yosupo_IO {

template <class T>
using is_signed_int128 =
    typename std::conditional<is_same<T, __int128_t>::value
                                  || is_same<T, __int128>::value,
                              true_type, false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<is_same<T, __uint128_t>::value
                                  || is_same<T, unsigned __int128>::value,
                              true_type, false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<is_same<T, __int128_t>::value, __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value
                                  || is_signed_int128<T>::value
                                  || is_unsigned_int128<T>::value,
                              true_type, false_type>::type;

template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value
                               && std::is_signed<T>::value)
                                  || is_signed_int128<T>::value,
                              true_type, false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value
                               && std::is_unsigned<T>::value)
                                  || is_unsigned_int128<T>::value,
                              true_type, false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value, make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

template <class T>
using is_integral_t = enable_if_t<is_integral<T>::value>;

template <class T>
using is_signed_int_t = enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = enable_if_t<is_unsigned_int<T>::value>;

namespace detail {
template <typename T, decltype(&T::is_modint) = &T::is_modint>
std::true_type check_value(int);
template <typename T>
std::false_type check_value(long);
} // namespace detail

template <typename T>
struct is_modint : decltype(detail::check_value<T>(0)) {};

template <typename T>
using is_modint_t = enable_if_t<is_modint<T>::value>;

template <class T>
using to_unsigned_t = typename to_unsigned<T>::type;

struct Scanner {
public:
  Scanner(const Scanner &) = delete;
  Scanner &operator=(const Scanner &) = delete;

  Scanner(FILE *fp) : fd(fileno(fp)) { line[0] = 127; }

  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }

  int read_unsafe() { return 0; }
  template <class H, class... T>
  int read_unsafe(H &h, T &... t) {
    bool f = read_single(h);
    if (!f) return 0;
    return 1 + read_unsafe(t...);
  }

  int close() { return ::close(fd); }

private:
  static constexpr int SIZE = 1 << 15;

  int fd = -1;
  array<char, SIZE + 1> line;
  int st = 0, ed = 0;
  bool eof = false;

  bool read_single(string &ref) {
    if (!skip_space()) return false;
    ref = "";
    while (true) {
      char c = top();
      if (c <= ' ') break;
      ref += c;
      st++;
    }
    return true;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }

  template <class T, enable_if_t<is_same<T, char>::value> * = nullptr>
  bool read_single(T &ref) {
    if (!skip_space<50>()) return false;
    ref = top();
    st++;
    return true;
  }

  template <class T, is_signed_int_t<T> * = nullptr,
            enable_if_t<!is_same<T, char>::value> * = nullptr>
  bool read_single(T &sref) {
    using U = to_unsigned_t<T>;
    if (!skip_space<50>()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    U ref = 0;
    do { ref = 10 * ref + (line[st++] & 0x0f); } while (line[st] >= '0');
    sref = neg ? -ref : ref;
    return true;
  }
  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<!is_same<U, char>::value> * = nullptr>
  bool read_single(U &ref) {
    if (!skip_space<50>()) return false;
    ref = 0;
    do { ref = 10 * ref + (line[st++] & 0x0f); } while (line[st] >= '0');
    return true;
  }

  bool reread() {
    if (ed - st >= 50) return true;
    if (st > SIZE / 2) {
      std::memmove(line.data(), line.data() + st, ed - st);
      ed -= st;
      st = 0;
    }
    if (eof) return false;
    auto u = ::read(fd, line.data() + ed, SIZE - ed);
    if (u == 0) {
      eof = true;
      line[ed] = '\0';
      u = 1;
    }
    ed += int(u);
    line[ed] = char(127);
    return true;
  }

  char top() {
    if (st == ed) {
      bool f = reread();
      assert(f);
    }
    return line[st];
  }

  template <int TOKEN_LEN = 0>
  bool skip_space() {
    while (true) {
      while (line[st] <= ' ') st++;
      if (ed - st > TOKEN_LEN) return true;
      if (st > ed) st = ed;
      for (auto i = st; i < ed; i++) {
        if (line[i] <= ' ') return true;
      }
      if (!reread()) return false;
    }
  }
};

struct Printer {
public:
  template <char sep = ' ', bool F = false>
  void write() {}
  template <char sep = ' ', bool F = false, class H, class... T>
  void write(const H &h, const T &... t) {
    if (F) write_single(sep);
    write_single(h);
    write<true>(t...);
  }
  template <char sep = ' ', class... T>
  void writeln(const T &... t) {
    write<sep>(t...);
    write_single('\n');
  }

  Printer(FILE *_fp) : fd(fileno(_fp)) {}
  ~Printer() { flush(); }

  int close() {
    flush();
    return ::close(fd);
  }

  void flush() {
    if (pos) {
      auto res = ::write(fd, line.data(), pos);
      assert(res != -1);
      pos = 0;
    }
  }

private:
  static array<array<char, 2>, 100> small;
  static array<unsigned long long, 20> tens;

  static constexpr size_t SIZE = 1 << 15;
  int fd;
  array<char, SIZE> line;
  size_t pos = 0;
  std::stringstream ss;

  template <class T, enable_if_t<is_same<char, T>::value> * = nullptr>
  void write_single(const T &val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }

  template <class T, is_signed_int_t<T> * = nullptr,
            enable_if_t<!is_same<char, T>::value> * = nullptr>
  void write_single(const T &val) {
    using U = to_unsigned_t<T>;
    if (val == 0) {
      write_single('0');
      return;
    }
    if (pos > SIZE - 50) flush();
    U uval = val;
    if (val < 0) {
      write_single('-');
      uval = -uval;
    }
    write_unsigned(uval);
  }

  template <class T, is_modint_t<T> * = nullptr>
  void write_single(const T &val) {
    write_single(val.val);
  }

  static int bsr(unsigned int n) {
    return 8 * (int)sizeof(unsigned int) - 1 - __builtin_clz(n);
  }
  static int bsr(unsigned long n) {
    return 8 * (int)sizeof(unsigned long) - 1 - __builtin_clzl(n);
  }
  static int bsr(unsigned long long n) {
    return 8 * (int)sizeof(unsigned long long) - 1 - __builtin_clzll(n);
  }

  template <class U, is_unsigned_int_t<U> * = nullptr>
  void write_single(U uval) {
    if (uval == 0) {
      write_single('0');
      return;
    }
    if (pos > SIZE - 50) flush();

    write_unsigned(uval);
  }

  template <class U, is_unsigned_int_t<U> * = nullptr>
  static int calc_len(U x) {
    int i = (bsr(1ULL * x) * 3 + 3) / 10;
    if (x < tens[i])
      return i;
    else
      return i + 1;
  }

  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<2 >= sizeof(U)> * = nullptr>
  void write_unsigned(U uval) {
    size_t len = calc_len(uval);
    pos += len;

    char *ptr = line.data() + pos;
    while (uval >= 100) {
      ptr -= 2;
      memcpy(ptr, small[uval % 100].data(), 2);
      uval /= 100;
    }
    if (uval >= 10) {
      memcpy(ptr - 2, small[uval].data(), 2);
    } else {
      *(ptr - 1) = char('0' + uval);
    }
  }

  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<4 == sizeof(U)> * = nullptr>
  void write_unsigned(U uval) {
    array<char, 8> buf;
    memcpy(buf.data() + 6, small[uval % 100].data(), 2);
    memcpy(buf.data() + 4, small[uval / 100 % 100].data(), 2);
    memcpy(buf.data() + 2, small[uval / 10000 % 100].data(), 2);
    memcpy(buf.data() + 0, small[uval / 1000000 % 100].data(), 2);

    if (uval >= 100000000) {
      if (uval >= 1000000000) {
        memcpy(line.data() + pos, small[uval / 100000000 % 100].data(), 2);
        pos += 2;
      } else {
        line[pos] = char('0' + uval / 100000000);
        pos++;
      }
      memcpy(line.data() + pos, buf.data(), 8);
      pos += 8;
    } else {
      size_t len = calc_len(uval);
      memcpy(line.data() + pos, buf.data() + (8 - len), len);
      pos += len;
    }
  }

  template <class U, is_unsigned_int_t<U> * = nullptr,
            enable_if_t<8 == sizeof(U)> * = nullptr>
  void write_unsigned(U uval) {
    size_t len = calc_len(uval);
    pos += len;

    char *ptr = line.data() + pos;
    while (uval >= 100) {
      ptr -= 2;
      memcpy(ptr, small[uval % 100].data(), 2);
      uval /= 100;
    }
    if (uval >= 10) {
      memcpy(ptr - 2, small[uval].data(), 2);
    } else {
      *(ptr - 1) = char('0' + uval);
    }
  }

  template <class U, enable_if_t<is_unsigned_int128<U>::value> * = nullptr>
  void write_unsigned(U uval) {
    static array<char, 50> buf;
    size_t len = 0;
    while (uval > 0) {
      buf[len++] = char((uval % 10) + '0');
      uval /= 10;
    }
    std::reverse(buf.begin(), buf.begin() + len);
    memcpy(line.data() + pos, buf.data(), len);
    pos += len;
  }

  void write_single(const std::string &s) {
    for (char c: s) write_single(c);
  }
  void write_single(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write_single(s[i]);
  }
  template <class T>
  void write_single(const std::vector<T> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write_single(' ');
      write_single(val[i]);
    }
  }
};

array<array<char, 2>, 100> Printer::small = [] {
  array<array<char, 2>, 100> table;
  for (int i = 0; i <= 99; i++) {
    table[i][1] = char('0' + (i % 10));
    table[i][0] = char('0' + (i / 10 % 10));
  }
  return table;
}();
array<ull, 20> Printer::tens = [] {
  array<ull, 20> table;
  for (int i = 0; i < 20; i++) {
    table[i] = 1;
    for (int j = 0; j < i; j++) { table[i] *= 10; }
  }
  return table;
}();

} // namespace yosupo_IO

using namespace yosupo_IO;
Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);

#define INT(...)   \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...)    \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...)           \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)
void scan(int &a) { scanner.read(a); }
void scan(ll &a) { scanner.read(a); }
void scan(ull &a) { scanner.read(a); }
void scan(char &a) { scanner.read(a); }
void scan(double &a) { scanner.read(a); }
// void scan(long double &a) { scanner.read(a); }
void scan(string &a) { scanner.read(a); }
template <class T>
void scan(pair<T, T> &p) {
  scan(p.first), scan(p.second);
}
template <class T>
void scan(tuple<T, T, T> &p) {
  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p));
}
template <class T>
void scan(tuple<T, T, T, T> &p) {
  scan(get<0>(p)), scan(get<1>(p)), scan(get<2>(p)), scan(get<3>(p));
}
template <class T>
void scan(vector<T> &a) {
  for (auto &&i: a) scan(i);
}
template <class T> // modint
void scan(T &a) {
  ll x;
  scanner.read(x);
  a = x;
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &... tail) {
  scan(head);
  IN(tail...);
}

vi s_to_vi(string S, char first_char = 'a') {
  vi A(S.size());
  FOR(i, S.size()) { A[i] = S[i] - first_char; }
  return A;
}

void print() { printer.writeln(); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  print(forward<Tail>(tail)...);
}

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }

template <typename T>
vector<T> cumsum(vector<T> &A) {
  int N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  return B;
}

vc<int> bin_count(vi &A, int size) {
  vc<int> C(size);
  for (auto &x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(vector<T> &A) {
  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
#line 3 "test/library_checker/convolution/contolution_mod_2_64.test.cpp"

#line 2 "mod/modint.hpp"
template <int mod>
struct modint {
  static constexpr bool is_modint = true;
  int val;

  constexpr modint(const ll val = 0) noexcept
      : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}

  bool operator<(const modint &other) const {
    return val < other.val;
  } // To use std::map

  modint &operator+=(const modint &p) {
    if ((val += p.val) >= mod) val -= mod;
    return *this;
  }
  modint &operator-=(const modint &p) {
    if ((val += mod - p.val) >= mod) val -= mod;
    return *this;
  }
  modint &operator*=(const modint &p) {
    val = (int)(1LL * val * p.val % mod);
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inverse();
    return *this;
  }
  modint operator-() const { return modint(-val); }
  modint operator+(const modint &p) const { return modint(*this) += p; }
  modint operator-(const modint &p) const { return modint(*this) -= p; }
  modint operator*(const modint &p) const { return modint(*this) *= p; }
  modint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const modint &p) const { return val == p.val; }
  bool operator!=(const modint &p) const { return val != p.val; }

  modint inverse() const {
    int a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return modint(u);
  }

  modint pow(int64_t n) const {
    modint ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  static constexpr int get_mod() { return mod; }
};

struct ArbitraryModInt {
  static constexpr bool is_modint = true;
  int val;
  ArbitraryModInt() : val(0) {}
  ArbitraryModInt(int64_t y)
      : val(y >= 0 ? y % get_mod()
                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}

  bool operator<(const ArbitraryModInt &other) const {
    return val < other.val;
  } // To use std::map<ArbitraryModInt, T>

  static int &get_mod() {
    static int mod = 0;
    return mod;
  }
  static void set_mod(int md) { get_mod() = md; }
  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if ((val += p.val) >= get_mod()) val -= get_mod();
    return *this;
  }
  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();
    return *this;
  }
  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    unsigned long long a = (unsigned long long)val * p.val;
    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(get_mod()));
    val = m;
    return *this;
  }
  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  ArbitraryModInt operator-() const { return ArbitraryModInt(-val); }
  ArbitraryModInt operator+(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) += p;
  }
  ArbitraryModInt operator-(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) -= p;
  }
  ArbitraryModInt operator*(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) *= p;
  }

  ArbitraryModInt operator/(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) /= p;
  }

  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }
  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }
  ArbitraryModInt inverse() const {
    int a = val, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }
  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
    return os << p.val;
  }
  friend istream &operator>>(istream &is, ArbitraryModInt &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }
};

template<typename mint>
tuple<mint, mint, mint> get_factorial_data(int n){
  static constexpr int mod = mint::get_mod();
  assert(0 <= n && n < mod);

  static vector<mint> fact = {1, 1};
  static vector<mint> fact_inv = {1, 1};
  static vector<mint> inv = {0, 1};
  while(len(fact) <= n){
    int k = len(fact);
    fact.eb(fact[k - 1] * mint(k));
    auto q = ceil(mod, k);
    int r = k * q - mod;
    inv.eb(inv[r] * mint(q));
    fact_inv.eb(fact_inv[k - 1] * inv[k]);
  }
  return {fact[n], fact_inv[n], inv[n]};
}

template<typename mint>
mint fact(int n){
  static constexpr int mod = mint::get_mod();
  assert(0 <= n);
  if(n >= mod) return 0;
  return get<0>(get_factorial_data<mint>(n));
}

template<typename mint>
mint fact_inv(int n){
  static constexpr int mod = mint::get_mod();
  assert(0 <= n && n < mod);
  return get<1>(get_factorial_data<mint>(n));
}

template<typename mint>
mint inv(int n){
  static constexpr int mod = mint::get_mod();
  assert(0 <= n && n < mod);
  return get<2>(get_factorial_data<mint>(n));
}

template<typename mint>
mint C(ll n, ll k, bool large = false) {
  assert(n >= 0);
  if (k < 0 || n < k) return 0;
  if (!large) return fact<mint>(n) * fact_inv<mint>(k) * fact_inv<mint>(n - k);
  k = min(k, n - k);
  mint x(1);
  FOR(i, k) {
    x *= mint(n - i);
  }
  x *= fact_inv<mint>(k);
  return x;
}

template<typename mint>
vc<mint> power_table(mint a, ll N) {
  vc<mint> f(N, 1);
  FOR(i, N - 1) f[i + 1] = a * f[i];
  return f;
}

using modint107 = modint<1'000'000'007>;
using modint998 = modint<998'244'353>;
using amint = ArbitraryModInt;
#line 3 "polynomial/convolution.hpp"
template <class T>
vector<T> convolution_naive(const vector<T>& a, const vector<T>& b) {
  int n = int(a.size()), m = int(b.size());
  vector<T> ans(n + m - 1);
  if (n < m) {
    FOR(j, m) FOR(i, n) ans[i + j] += a[i] * b[j];
  } else {
    FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];
  }
  return ans;
}

template <class mint>
struct fft_info {
  static constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
  }

  static constexpr int rank2 = bsf_constexpr(mint::get_mod() - 1);
  array<mint, rank2 + 1> root;
  array<mint, rank2 + 1> iroot;
  array<mint, max(0, rank2 - 1)> rate2;
  array<mint, max(0, rank2 - 1)> irate2;
  array<mint, max(0, rank2 - 2)> rate3;
  array<mint, max(0, rank2 - 2)> irate3;

  fft_info() {
    int g = primitive_root(mint::get_mod());
    root[rank2] = mint(g).pow((mint::get_mod() - 1) >> rank2);
    iroot[rank2] = mint(1) / root[rank2];
    FOR_R(i, rank2) {
      root[i] = root[i + 1] * root[i + 1];
      iroot[i] = iroot[i + 1] * iroot[i + 1];
    }
    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 2; i++) {
        rate2[i] = root[i + 2] * prod;
        irate2[i] = iroot[i + 2] * iprod;
        prod *= iroot[i + 2];
        iprod *= root[i + 2];
      }
    }
    {
      mint prod = 1, iprod = 1;
      for (int i = 0; i <= rank2 - 3; i++) {
        rate3[i] = root[i + 3] * prod;
        irate3[i] = iroot[i + 3] * iprod;
        prod *= iroot[i + 3];
        iprod *= root[i + 3];
      }
    }
  }

  constexpr int primitive_root(int m) {
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 880803841) return 26;
    if (m == 998244353) return 3;
  }
};

template <class mint>
void ntt(vector<mint>& a, bool inverse) {
  int n = int(a.size());
  int h = topbit(n);
  assert(n == 1 << h);
  static const fft_info<mint> info;
  if (!inverse) {
    int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
    while (len < h) {
      if (h - len == 1) {
        int p = 1 << (h - len - 1);
        mint rot = 1;
        FOR(s, 1 << len) {
          int offset = s << (h - len);
          FOR(i, p) {
            auto l = a[i + offset];
            auto r = a[i + offset + p] * rot;
            a[i + offset] = l + r;
            a[i + offset + p] = l - r;
          }
          rot *= info.rate2[topbit(~s & -~s)];
        }
        len++;
      } else {
        int p = 1 << (h - len - 2);
        mint rot = 1, imag = info.root[2];
        for (int s = 0; s < (1 << len); s++) {
          mint rot2 = rot * rot;
          mint rot3 = rot2 * rot;
          int offset = s << (h - len);
          for (int i = 0; i < p; i++) {
            auto mod2 = 1ULL * mint::get_mod() * mint::get_mod();
            auto a0 = 1ULL * a[i + offset].val;
            auto a1 = 1ULL * a[i + offset + p].val * rot.val;
            auto a2 = 1ULL * a[i + offset + 2 * p].val * rot2.val;
            auto a3 = 1ULL * a[i + offset + 3 * p].val * rot3.val;
            auto a1na3imag = 1ULL * mint(a1 + mod2 - a3).val * imag.val;
            auto na2 = mod2 - a2;
            a[i + offset] = a0 + a2 + a1 + a3;
            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
          }
          rot *= info.rate3[topbit(~s & -~s)];
        }
        len += 2;
      }
    }
  } else {
    mint coef = mint(1) / mint(len(a));
    FOR(i, len(a)) a[i] *= coef;
    int len = h;
    while (len) {
      if (len == 1) {
        int p = 1 << (h - len);
        mint irot = 1;
        FOR(s, 1 << (len - 1)) {
          int offset = s << (h - len + 1);
          FOR(i, p) {
            auto l = a[i + offset];
            auto r = a[i + offset + p];
            a[i + offset] = l + r;
            a[i + offset + p]
                = (unsigned long long)(mint::get_mod() + l.val - r.val)
                  * irot.val;
            ;
          }
          irot *= info.irate2[topbit(~s & -~s)];
        }
        len--;
      } else {
        int p = 1 << (h - len);
        mint irot = 1, iimag = info.iroot[2];
        FOR(s, (1 << (len - 2))) {
          mint irot2 = irot * irot;
          mint irot3 = irot2 * irot;
          int offset = s << (h - len + 2);
          for (int i = 0; i < p; i++) {
            auto a0 = 1ULL * a[i + offset + 0 * p].val;
            auto a1 = 1ULL * a[i + offset + 1 * p].val;
            auto a2 = 1ULL * a[i + offset + 2 * p].val;
            auto a3 = 1ULL * a[i + offset + 3 * p].val;

            auto a2na3iimag
                = 1ULL * mint((mint::get_mod() + a2 - a3) * iimag.val).val;

            a[i + offset] = a0 + a1 + a2 + a3;
            a[i + offset + 1 * p]
                = (a0 + (mint::get_mod() - a1) + a2na3iimag) * irot.val;
            a[i + offset + 2 * p]
                = (a0 + a1 + (mint::get_mod() - a2) + (mint::get_mod() - a3))
                  * irot2.val;
            a[i + offset + 3 * p]
                = (a0 + (mint::get_mod() - a1) + (mint::get_mod() - a2na3iimag))
                  * irot3.val;
          }
          irot *= info.irate3[topbit(~s & -~s)];
        }
        len -= 2;
      }
    }
  }
}

template <class mint>
vector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {
  int n = int(a.size()), m = int(b.size());
  int sz = 1;
  while (sz < n + m - 1) sz *= 2;
  a.resize(sz), b.resize(sz);
  bool same = a == b;
  ntt(a, 0);
  if(same){
    b = a;
  } else {
    ntt(b, 0);
  }
  FOR(i, sz) a[i] *= b[i];
  ntt(a, 1);
  a.resize(n + m - 1);
  return a;
}

template <typename mint>
vector<mint> convolution_garner(const vector<mint>& a, const vector<mint>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  static const long long nttprimes[] = {754974721, 167772161, 469762049};
  using mint0 = modint<754974721>;
  using mint1 = modint<167772161>;
  using mint2 = modint<469762049>;
  vc<mint0> a0(n), b0(m);
  vc<mint1> a1(n), b1(m);
  vc<mint2> a2(n), b2(m);
  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;
  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;
  auto c0 = convolution_ntt<mint0>(a0, b0);
  auto c1 = convolution_ntt<mint1>(a1, b1);
  auto c2 = convolution_ntt<mint2>(a2, b2);
  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];
  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;
  static const long long m01_inv_m2 = mint2(m01).inverse().val;
  static const int mod = mint::get_mod();
  auto garner = [&](mint0 x0, mint1 x1, mint2 x2) -> mint {
    int r0 = x0.val, r1 = x1.val, r2 = x2.val;
    int v1 = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];
    auto v2 = (mint2(r2) - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);
    return mint(r0 + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val);
  };
  vc<mint> c(len(c0));
  FOR(i, len(c)) c[i] = garner(c0[i], c1[i], c2[i]);
  return c;
}

namespace CFFT {
using real = double;

struct C {
  real x, y;

  C() : x(0), y(0) {}

  C(real x, real y) : x(x), y(y) {}
  inline C operator+(const C& c) const { return C(x + c.x, y + c.y); }
  inline C operator-(const C& c) const { return C(x - c.x, y - c.y); }
  inline C operator*(const C& c) const {
    return C(x * c.x - y * c.y, x * c.y + y * c.x);
  }

  inline C conj() const { return C(x, -y); }
};

const real PI = acosl(-1);
int base = 1;
vector<C> rts = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

void ensure_base(int nbase) {
  if (nbase <= base) return;
  rev.resize(1 << nbase);
  rts.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++) {
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
  }
  while (base < nbase) {
    real angle = PI * 2.0 / (1 << (base + 1));
    for (int i = 1 << (base - 1); i < (1 << base); i++) {
      rts[i << 1] = rts[i];
      real angle_i = angle * (2 * i + 1 - (1 << base));
      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
    }
    ++base;
  }
}

void fft(vector<C>& a, int n) {
  assert((n & (n - 1)) == 0);
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; i++) {
    if (i < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }
  }
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        C z = a[i + j + k] * rts[j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] = a[i + j] + z;
      }
    }
  }
}

template <typename R>
vc<double> convolution_fft(const vc<R>& a, const vc<R>& b) {
  int need = (int)a.size() + (int)b.size() - 1;
  int nbase = 1;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int sz = 1 << nbase;
  vector<C> fa(sz);
  for (int i = 0; i < sz; i++) {
    int x = (i < (int)a.size() ? a[i] : 0);
    int y = (i < (int)b.size() ? b[i] : 0);
    fa[i] = C(x, y);
  }
  fft(fa, sz);
  C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
    fa[i] = z;
  }
  for (int i = 0; i < (sz >> 1); i++) {
    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
    C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
    fa[i] = A0 + A1 * s;
  }
  fft(fa, sz >> 1);
  vector<double> ret(need);
  for (int i = 0; i < need; i++) {
    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
  }
  return ret;
}
} // namespace CFFT


vector<ll> convolution(vector<ll>& a, vector<ll>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 60) return convolution_naive(a, b);
  ll abs_sum_a = 0, abs_sum_b = 0;
  FOR(i, n) abs_sum_a += abs(a[i]);
  FOR(i, n) abs_sum_b += abs(b[i]);
  assert(abs_sum_a * abs_sum_b < 1e15);
  vc<double> c = CFFT::convolution_fft(a, b);
  vc<ll> res(len(c));
  FOR(i, len(c)) res[i] = ll(floor(c[i] + .5));
  return res;
}

template<typename mint>
enable_if_t<is_same<mint, modint998>::value, vc<mint>> convolution(vc<mint>& a, vc<mint>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  // if (min(n, m) <= 60) return convolution_naive(a, b);
  return convolution_ntt(a, b);
}

template<typename mint>
enable_if_t<!is_same<mint, modint998>::value, vc<mint>> convolution(vc<mint>& a, vc<mint>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 60) return convolution_naive(a, b);
  return convolution_garner(a, b);
}
#line 2 "polynomial/convolution_mod_2_64.hpp"
vector<ull> convolution_mod_2_64(const vector<ull>& a, const vector<ull>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 60) return convolution_naive(a, b);
  constexpr int P0 = 998244353;
  constexpr int P1 = 754974721;
  constexpr int P2 = 167772161;
  constexpr int P3 = 469762049;
  constexpr int P4 = 880803841;
  using M0 = modint<P0>;
  using M1 = modint<P1>;
  using M2 = modint<P2>;
  using M3 = modint<P3>;
  using M4 = modint<P4>;
  vc<M0> a0(n), b0(m);
  vc<M1> a1(n), b1(m);
  vc<M2> a2(n), b2(m);
  vc<M3> a3(n), b3(m);
  vc<M4> a4(n), b4(m);
  FOR(i, n) a0[i] = a[i] % P0;
  FOR(i, m) b0[i] = b[i] % P0;
  FOR(i, n) a1[i] = a[i] % P1;
  FOR(i, m) b1[i] = b[i] % P1;
  FOR(i, n) a2[i] = a[i] % P2;
  FOR(i, m) b2[i] = b[i] % P2;
  FOR(i, n) a3[i] = a[i] % P3;
  FOR(i, m) b3[i] = b[i] % P3;
  FOR(i, n) a4[i] = a[i] % P4;
  FOR(i, m) b4[i] = b[i] % P4;
  a0 = convolution_ntt<M0>(a0, b0);
  a1 = convolution_ntt<M1>(a1, b1);
  a2 = convolution_ntt<M2>(a2, b2);
  a3 = convolution_ntt<M3>(a3, b3);
  a4 = convolution_ntt<M4>(a4, b4);
  static const M1 inv10 = M1(1) / M1(P0);
  static const M2 inv21 = M2(1) / M2(P1), inv20 = inv21 / M2(P0);
  static const M3 inv32 = M3(1) / M3(P2), inv31 = inv32 / M3(P1),
                  inv30 = inv31 / M3(P0);
  static const M4 inv43 = M4(1) / M4(P3), inv42 = inv43 / M4(P2),
                  inv41 = inv42 / M4(P1), inv40 = inv41 / M4(P0);
  vc<ull> c(len(a0));
  FOR(i, len(c)) {
    ll x0 = a0[i].val;
    ll x1 = (M1(a1[i] - x0) * inv10).val;
    ll x2 = (M2(a2[i] - x0) * inv20 - M2(x1) * inv21).val;
    ll x3 = (M3(a3[i] - x0) * inv30 - M3(x1) * inv31 - M3(x2) * inv32).val;
    ll x4 = (M4(a4[i] - x0) * inv40 - M4(x1) * inv41 - M4(x2) * inv42
             - M4(x3) * inv43)
                .val;
    c[i] = x0 + P0 * (x1 + P1 * (x2 + P2 * (x3 + P3 * ull(x4))));
  }
  return c;
}
#line 5 "test/library_checker/convolution/contolution_mod_2_64.test.cpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(mint, A, N);
  VEC(mint, B, M);
  auto ANS = convolution(A, B);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
