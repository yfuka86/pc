// Union-Find which we can undo
struct UnionFind {
  vector<int> par;
  stack<pair<int,int>> history;
  UnionFind() {}
  UnionFind(int n) : par(n, -1) { }
  void init(int n) { par.assign(n, -1); }
  int root(int x) { if (par[x] < 0) return x; else return root(par[x]); }
  int size(int x) { return -par[root(x)]; }
  bool issame(int x, int y) { return root(x) == root(y); }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    history.emplace(x, par[x]);
    history.emplace(y, par[y]);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y); // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  // 1-step undo
  void undo() {
    for (int iter = 0; iter < 2; ++iter) {
      par[history.top().first] = history.top().second;
      history.pop();
    }
  }
  // erase history
  void snapshot() { while (!history.empty()) history.pop(); }
  // all rollback
  void rollback() { while (!history.empty()) undo(); }
};
