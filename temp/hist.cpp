
struct R {
  int h; mint w;
  R(int h, mint w): h(h), w(w) {};
};

struct D {
  stack<R> st;
  mint tot;
  D() {}
  void add(int h, mint w) {
    while (!st.empty() && st.top().h <= h) {
      auto [nh, nw] = st.top();
      tot -= nw * nh;
      w += nw;
      st.pop();
    }
    tot += w * h;
    st.emplace(h, w);
  }
};
