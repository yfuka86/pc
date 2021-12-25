// https://atcoder.jp/contests/abc023/tasks/abc023_d
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <bitset>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,x,n) for(int i=x; i<(int)(n); ++i)
#define all(v) v.begin(), v.end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;

template <class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1;} return 0; }

template <class T>
bool chmax(T &a, const T &b) { if (b > a) { a = b; return 1;} return 0; }


template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }

int N;
vector<ll> h;
vector<ll> s;

bool able(ll top) {
  vector<ll> limits(N);
  rep(i, N) {
    // これが抜けててずっと悩んでた
    if (h[i] > top) return false;
    limits[i] = (top - h[i]) / s[i];
  }
  sort(all(limits));
  rep(i, N) if (limits[i] < i) return false;
  return true;
}

int main()
{
  cin >> N;
  ll bs_min = LINF;
  ll bs_max = 0;

  h.resize(N);
  s.resize(N);
  rep(i, N) {
    cin >> h[i] >> s[i];
  }

  while (bs_min != bs_max) {
    ll temp = (bs_min + bs_max) / 2;
    if (able(temp)) {
      bs_max = temp;
    } else {
      bs_min = temp + 1;
    }
  }

  cout << bs_min << endl;
}

