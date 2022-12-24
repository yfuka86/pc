template <size_t MAXB = 30, typename T = ull>
struct BinaryTrie {
public:
  vector<vector<int>> nxt;
  BinaryTrie() { nxt.push_back({-1, -1}); }
  size_t size() const { return nxt.size(); }

  int add(T x) {
    int cur = 0;
    for(int b = MAXB - 1; b >= 0; --b) {
      int nx = (x & 1 << b) ? 1 : 0;
      if (nxt[cur][nx] == -1) {
        nxt[cur][nx] = nxt.size();
        nxt.push_back({-1, -1});
      }
      cur = nxt[cur][nx];
    }
    return cur;
  }

  inline const vector<int> &operator[](const int &k) { return nxt[k]; }
};
