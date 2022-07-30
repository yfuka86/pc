#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;
struct lazy_segment_tree{
  int N;
  vector<int> ST; //range_min
  vector<pair<int, int>> lazy;
  lazy_segment_tree(int n){
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<int>(N * 2 - 1, INF);
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = 0;
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
    lazy = vector<pair<int, int>>(N * 2 - 1, make_pair(1, 0));
  }
  void eval(int i, int l){
    if (i < N - 1){
      if (lazy[i].first == 0){
        lazy[i * 2 + 1] = lazy[i];
        lazy[i * 2 + 2] = lazy[i];
      } else {
        lazy[i * 2 + 1].second += lazy[i].second;
        lazy[i * 2 + 2].second += lazy[i].second;
      }
    }
    if (lazy[i].first == 0){
      ST[i] = l + lazy[i].second;
    } else {
      ST[i] += lazy[i].second;
    }
    lazy[i] = make_pair(1, 0);
  }
  void range_update(int L, int R, int x, int i, int l, int r){
    eval(i, l);
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      lazy[i] = make_pair(0, x);
      eval(i, l);
    } else {
      int m = (l + r) / 2;
      range_update(L, R, x, i * 2 + 1, l, m);
      range_update(L, R, x, i * 2 + 2, m, r);
      ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void range_update(int L, int R, int x){
    range_update(L, R, x, 0, 0, N);
  }
  void range_add(int L, int R, int x, int i, int l, int r){
    eval(i, l);
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      lazy[i] = make_pair(1, x);
      eval(i, l);
    } else {
      int m = (l + r) / 2;
      range_add(L, R, x, i * 2 + 1, l, m);
      range_add(L, R, x, i * 2 + 2, m, r);
      ST[i] = min(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void range_add(int L, int R, int x){
    range_add(L, R, x, 0, 0, N);
  }
  int range_min(int L, int R, int i, int l, int r){
    eval(i, l);
    if (r <= L || R <= l){
      return INF;
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
    }
  }
  int range_min(int L, int R){
    return range_min(L, R, 0, 0, N);
  }
};
int main(){
  int H, W;
  cin >> H >> W;
  vector<int> A(H), B(H);
  for (int i = 0; i < H; i++){
    cin >> A[i] >> B[i];
    A[i]--;
  }
  lazy_segment_tree ST(W);
  for (int i = 0; i < H; i++){
    ST.range_add(0, W, 1);
    if (A[i] == 0){
      ST.range_update(0, B[i], INF);
    } else {
      int x = ST.range_min(A[i] - 1, A[i]);
      ST.range_update(A[i], B[i], x - (A[i] - 1));
    }
    for (int i = 0; i < W; i++) {
      cout << ST.range_min(i, i + 1) << " ";
    }cout << "\n";
    int ans = ST.range_min(0, W);
    if (ans >= INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
