
template <size_t X = 26, char margin = 'a', typename T = ll>
struct Trie {
public:
  vector<vector<int>> nxt; vector<bool> end; vector<int> cs, fail; vector<T> node_v;
  Trie() { init_node(-1); }
  size_t size() const { return nxt.size(); }

  int add_node(int v, int n, bool isend = false, T val = T()) {
    assert(fail.size() == 0);
    int ret = -1;
    if (nxt[v][n] == -1) ret = nxt[v][n] = init_node(n);
    else ret = nxt[v][n];
    if (isend) { end[ret] = 1; node_v[ret] += val; }
    return ret;
  }
  int add(vector<int> &s, T val = T()) { int n = s.size(), v = 0; for (int i = 0; i < n; ++i) v = add_node(v, s[i], i == n - 1, val); return v; }
  int add(string &s, T val = T()) { int n = s.size(), v = 0; for (int i = 0; i < n; ++i) v = add_node(v, s[i] - margin, i == n - 1, val); return v; }

  int walk(int v, int n) { return nxt[v][n]; }
  int search(vector<int> &s) { int n = s.size(), v = 0; for (int i = 0; i < n; ++i) { v = walk(v, s[i]); if (v == -1) return v; } return v; }
  int search(string &s) { int n = s.size(), v = 0; for (int i = 0; i < n; ++i) { v = walk(v, s[i] - margin); if (v == -1) return v; } return v; }

  void build_fail() {
    fail.assign(nxt.size(), 0);
    vector<int> bfs; bfs.emplace_back(0);
    queue<int> que; que.push(0);
    while (!que.empty()) {
      int v = que.front(); que.pop();
      node_v[v] = node_v[v] + node_v[fail[v]];
      for (int s = 0; s < X; ++s) {
        if (nxt[v][s] == -1) continue;
        int w = nxt[v][s];
        que.push(w);
        bfs.emplace_back(w);
        if (v == 0) continue;
        int f = fail[v];
        while (f && nxt[f][s] == -1) f = fail[f];
        fail[w] = (nxt[f][s] == -1 ? 0 : nxt[f][s]);
      }
    }
    for (auto v: bfs) {
      for (int s = 0; s < X; ++s) if (nxt[v][s] == -1) {
        int f = fail[v];
        nxt[v][s] = nxt[f][s];
        if (nxt[v][s] == -1) nxt[v][s] = 0;
      }
    }
  }
  inline const vector<int> &operator[](const int &k) { return nxt[k]; }

private:
  int init_node(int n) {
    nxt.emplace_back(vector<int>(X, -1));
    cs.emplace_back(n);
    end.emplace_back(0);
    node_v.emplace_back(T());
    return nxt.size() - 1;
  }
};
