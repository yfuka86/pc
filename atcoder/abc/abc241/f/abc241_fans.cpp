#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int main(){
  int H, W, N;
  cin >> H >> W >> N;
  int sx, sy;
  cin >> sx >> sy;
  sx--;
  sy--;
  int gx, gy;
  cin >> gx >> gy;
  gx--;
  gy--;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++){
    cin >> X[i] >> Y[i];
    X[i]--;
    Y[i]--;
  }
  set<pair<int, int>> st;
  for (int i = 0; i < N; i++){
    st.insert(make_pair(X[i], Y[i]));
  }
  vector<pair<int, int>> P;
  P.push_back(make_pair(sx, sy));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < 4; j++){
      if (0 <= X[i] + dx[j] && X[i] + dx[j] < H && 0 <= Y[i] + dy[j] && Y[i] + dy[j] < W){
        if (st.count(make_pair(X[i] + dx[j], Y[i] + dy[j])) == 0){
          P.push_back(make_pair(X[i] + dx[j], Y[i] + dy[j]));
        }
      }
    }
  }
  sort(P.begin(), P.end());
  P.erase(unique(P.begin(), P.end()), P.end());
  int s = lower_bound(P.begin(), P.end(), make_pair(sx, sy)) - P.begin();
  auto itr = lower_bound(P.begin(), P.end(), make_pair(gx, gy));
  if (itr == P.end()){
    cout << -1 << endl;
  } else if (*itr != make_pair(gx, gy)){
    cout << -1 << endl;
  } else {
    int g = itr - P.begin();
    int V = P.size();
    map<int, set<int>> mpX, mpY;
    for (int i = 0; i < N; i++){
      mpX[Y[i]].insert(X[i]);
      mpY[X[i]].insert(Y[i]);
    }
    vector<int> x(V), y(V);
    for (int i = 0; i < V; i++){
      x[i] = P[i].first;
      y[i] = P[i].second;
    }
    vector<vector<int>> E(V);
    for (int i = 0; i < V; i++){
      if (mpX.count(y[i]) == 1){
        auto itr1 = mpX[y[i]].lower_bound(x[i]);
        if (itr1 != mpX[y[i]].end()){
          int w = lower_bound(P.begin(), P.end(), make_pair(*itr1 - 1, y[i])) - P.begin();
          E[i].push_back(w);
        }
        if (itr1 != mpX[y[i]].begin()){
          int w = lower_bound(P.begin(), P.end(), make_pair(*prev(itr1) + 1, y[i])) - P.begin();
          E[i].push_back(w);
        }
      }
      if (mpY.count(x[i]) == 1){
        auto itr2 = mpY[x[i]].lower_bound(y[i]);
        if (itr2 != mpY[x[i]].end()){
          int w = lower_bound(P.begin(), P.end(), make_pair(x[i], *itr2 - 1)) - P.begin();
          E[i].push_back(w);
        }
        if (itr2 != mpY[x[i]].begin()){
          int w = lower_bound(P.begin(), P.end(), make_pair(x[i], *prev(itr2) + 1)) - P.begin();
          E[i].push_back(w);
        }
      }
    }
    vector<int> d(V, -1);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      for (int w : E[v]){
        if (d[w] == -1){
          d[w] = d[v] + 1;
          Q.push(w);
        }
      }
    }
    cout << d[g] << endl;
  }
}
