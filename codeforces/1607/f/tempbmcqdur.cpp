   ll i = que.front(); que.pop();
      if (!cycle[i] && next(i) != -1) {
        chmax(dp[i], dp[next(i)] + 1);
      }
      for (ll p: prev[i]) if (!cycle[p]) que.push(p);
    }