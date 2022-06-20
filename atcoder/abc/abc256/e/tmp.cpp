  rep(i, n) {
    auto [c, x, y] = p[i];
    if (uf.same(x, y)) ans += c;
    else uf.unite(x, y);
 