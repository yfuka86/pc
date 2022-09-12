f ((i + j & 1) ^ (g[i][j] == 'W')) {
      mf.add_edge(id(i, j), t, inf);
    } else {
      mf.add_edge(s, id(i, j), inf);
    }