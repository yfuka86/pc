for(auto [st, sum] :scoresum) {
    auto [st2, sum2] = *(N & 1 ? scoresum2 : scoresum).lower_bound(D - st);
    chmax(ans, sum + sum2);
  