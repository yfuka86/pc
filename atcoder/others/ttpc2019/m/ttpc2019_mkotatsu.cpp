#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int N;
long ans[1<<17];
vector<int>G[1<<17];
long T[1<<17];
int L[1<<17],R[1<<17];
vector<int>A;
//1-indexed
template<typename T>
struct BIT{
	int n;
	vector<T>bit;
	BIT(int n_=0):n(n_),bit(n_+1){}
	T sum(int i)
	{
		T ans=0;
		for(;i>0;i-=i&-i)ans+=bit[i];
		return ans;
	}
	void add(int i,T a)
	{
		if(i==0)return;
		for(;i<=n;i+=i&-i)bit[i]+=a;
	}
	int lower_bound(T k)//k<=sum(ret)
	{
		if(k<=0)return 0;
		int ret=0,i=1;
		while((i<<1)<=n)i<<=1;
		for(;i;i>>=1)
			if(ret+i<=n&&bit[ret+i]<k)k-=bit[ret+=i];
		return ret+1;
	}
};
map<pair<int,int>,int>M;
int query(int u,int v)
{
	return M[make_pair(u,v)];
}
vector<int>Q[1<<17];
void dfs(int u,int p)
{
	Q[u].push_back(u);
	L[u]=A.size();
	A.push_back(u);
	for(int v:G[u])
	{
		if(v!=p)
		{
			Q[v].push_back(u);
			dfs(v,u);
		}
	}
	R[u]=A.size();
}
void dfs1(int u,int p)
{
	for(int v:G[u])
	{
		if(v==p)continue;
		dfs1(v,u);
		T[u]+=T[v];
	}
	T[u]+=query(u,u);
}
void dfs2(int u,int p,long P)
{
	ans[u]=P+u;
	for(int v:G[u])if(v!=p)ans[u]+=T[v];
	for(int v:G[u])
	{
		if(v==p)continue;
		dfs2(v,u,ans[u]-T[v]-query(v,u));
	}
}
int main()
{
	cin>>N;
	for(int i=1;i<N;i++)
	{
		int a,b;cin>>a>>b;a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0,-1);
	BIT<int>bit(N);
	vector<pair<int,int> >X;
	for(int i=0;i<N;i++)
	{
		X.push_back(make_pair(L[i],-i));
		X.push_back(make_pair(R[i],i));
	}
	sort(X.begin(),X.end());
	int id=0;
	for(int i=0;i<=N;i++)
	{
		while(id<X.size()&&X[id].first<=i)
		{
			int a=X[id].second;
			if(a<0)a=-a;
			for(int q:Q[a])
			{
				M[make_pair(a,q)]+=bit.sum(q)*(X[id].second<0?-1:1);
			}
			id++;
		}
		if(i<N)bit.add(A[i]+1,1);
	}
	dfs1(0,-1);
	dfs2(0,-1,0);
	for(int i=0;i<N;i++)cout<<ans[i]<<endl;

  return 0;
}
