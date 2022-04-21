#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;

vector<int> s[2];
vector<ull> u[2];

const int N = 500;
int n;
int val[2][N];
int d[N][N];

void flip() {
  rep(i,n)rep(j,i) {
    swap(d[i][j], d[j][i]);
  }
}
bool solve() {
  rep(i,n)rep(j,n) d[i][j] = -1;
  rep(k,2) {
    rep(i,n) {
      int x = val[k][i];
      if (s[k][i] != x) {
        rep(j,n) {
          if (d[i][j] == !x) return false;
          d[i][j] = x;
        }
      }
    }
    flip();
  }
  rep(_,2) {
    rep(k,2) {
      rep(i,n) {
        int x = val[k][i];
        if (s[k][i] == x) {
          vector<int> p;
          bool ok = false;
          rep(j,n) {
            if (d[i][j] == -1) p.push_back(j);
            if (d[i][j] == x) ok = true;
          }
          if (ok) continue;
          if (p.size() == 0) return false;
          if (p.size() == 1) {
            d[i][p[0]] = x;
          }
        }
      }
      flip();
    }
  }

  vector<int> is, js;
  rep(i,n) {
    bool filled = true;
    rep(j,n) if (d[i][j] == -1) filled = false;
    if (!filled) is.push_back(i);
  }
  rep(j,n) {
    bool filled = true;
    rep(i,n) if (d[i][j] == -1) filled = false;
    if (!filled) js.push_back(j);
  }
  rep(i,is.size())rep(j,js.size()) {
    d[is[i]][js[j]] = (i+j)%2;
  }
  return true;
}

ull ans[N][N];

int main() {
  cin >> n;
  rep(i,2) {
    s[i] = vector<int>(n);
    rep(j,n) cin >> s[i][j];
  }
  rep(i,2) {
    u[i] = vector<ull>(n);
    rep(j,n) cin >> u[i][j];
  }

  rep(b,64) {
    rep(i,2)rep(j,n) val[i][j] = u[i][j]>>b&1;
    if (!solve()) {
      cout << "-1" << endl;
      return 0;
    }
    rep(i,n)rep(j,n) ans[i][j] |= ull(d[i][j])<<b;
  }
  rep(i,n) {
    rep(j,n) {
      cout<<ans[i][j]<<(j==n-1?'\n':' ');
    }
  }
  return 0;
}
