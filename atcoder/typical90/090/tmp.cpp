
//  fps F = {1, 1};
//   for(int m = k - 1; m > 0; m--) {
//     int c = k / m;
//     fps G = fps({1}) - (F << 1);
//     F *= G.inv(c);
//     F.resize(c + 1);
//   }
//   fps G = fps({1}) - (F << 1);
//   mint ans = p