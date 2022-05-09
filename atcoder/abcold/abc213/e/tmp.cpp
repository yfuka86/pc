que.empty()) {
    auto [co, c] = que.top(); que.pop();
    auto [x, y] = c;
    if (co != cost[x][y]) continue;
    rep(d, 4) {
      ll di = x + dx[d], dj = y + dy[d];
      if (0 <= di && di < H && 0 <= dj && dj < W) {
        if (grid[di][dj]) {
          rep2(d1, -1, 2) rep2(d2, -1, 2) {
            ll ddx = di + d1, ddy = dj + d2;
            if (0 <= ddx && ddx < H && 0 <= ddy && ddy < W) {
              if (chmin(cost[ddx][ddy], co + 1)) que.push({co + 1, mp(ddx, ddy)});
            }
          }
        } else {
          if (chmin(cost[di][dj], co)) que.push({co, mp(di, dj)});
        }
      }
    }
  }