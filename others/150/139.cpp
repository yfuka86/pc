#pragma GCC optimize("Ofast")
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
#include <numeric>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep_r(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rep2(i,sta,n) for(int i=sta;i<(int)(n);i++)
#define rep2_r(i,sta,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
const int INF = numeric_limits<int>::max();
const ll LINF = LLONG_MAX;
const double DINF = numeric_limits<double>::infinity();
const ll mod = 1000000007;

struct RMQ{
  static const int MAX_N = 1 << 17;
  int n,dat[2*MAX_N-1];
  RMQ(){}
  RMQ(int n_){init(n_);}
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++) dat[i]=INT_MAX;
  }
  void update(int k,int a){
    k+=n-1;
    dat[k]=a;
    while(k>0){
      k=(k-1)/2;
      dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
  }
  int query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return INT_MAX;
    if(a<=l&&r<=b) return dat[k];
    else{
      int vl=query(a,b,k*2+1,l,(l+r)/2);
      int vr=query(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }
  int query(int a,int b){
    return query(a,b,0,0,n);
  }
};

int main()
{
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  RMQ rmq(n);

  rep(i, q) {
    int type, s, t; cin >> type >> s >> t;
    if (type == 0) {
      rmq.update(s, t);
    } else {
      cout << rmq.query(s, t + 1) << "\n";
    }
  }
}

