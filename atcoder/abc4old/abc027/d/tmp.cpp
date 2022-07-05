
  //   if (__builtin_popcount(s) != move / 2) continue;
  //   ll m = 0, pos = 0, tmp = 0;
  //   rep(i, S.size()) {
  //     if (S[i] == 'M') {
  //       if (s & 1 << m) pos++; else pos--;
  //       m++;
  //     } else {
  //       if (S[i] == '+') tmp += pos else tmp -= pos;
  //     }
  //   }
  //   chmax(ans, tmp);
  // }