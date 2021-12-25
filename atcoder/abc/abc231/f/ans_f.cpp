#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

void comp(vector<int>&a){
  set<int>s(a.begin(),a.end());
  map<int,int>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
}

auto op=[](long long a,long long b){return a+b;};
auto e=[](){return 0LL;};

int main(){
  int n;
  cin >> n;
  vector<int>a(n),b(n);
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n;i++)cin >> b[i];
  comp(a);
  comp(b);

  vector<pair<int,int>>c(n);
  for(int i=0;i<n;i++)c[i]=make_pair(-a[i],b[i]);
  sort(c.begin(),c.end());

  segtree<long long, op, e>seg(n);

  long long ans=0;
  for(int i=0;i<n;i++){
    int cnt=1;
    while(i+1<n&&c[i]==c[i+1])cnt++,i++;
    int b=c[i].second;
    ans+=cnt*(cnt+seg.prod(0,b+1));
    seg.set(b,seg.get(b)+cnt);
  }

  cout << ans;
}
