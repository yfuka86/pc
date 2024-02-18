#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N,K;
vector<int>G[1<<17];
int A[20],B[20];
bool OK[1<<20];
vector<int>V;
int L[1<<17],R[1<<17];

void dfs(int u,int p)
{
	L[u]=V.size();
	V.push_back(u);
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u);
		int now=0;
		for(int i=0;i<K;i++)
		{
			bool a=L[v]<=L[A[i]]&&L[A[i]]<R[v];
			bool b=L[v]<=L[B[i]]&&L[B[i]]<R[v];
			if(a!=b)now|=1<<i;
		}
		OK[now]=true;
	}
	R[u]=V.size();
}
int dp[1<<20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	vector<int>X;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;cin>>u>>v;u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cin>>K;
		for(int i=0;i<K;i++)
		{
			cin>>A[i]>>B[i];
			A[i]--,B[i]--;
		}
		for(int i=0;i<1<<K;i++)
		{
			OK[i]=false;
			dp[i]=1e9;
		}
		V.clear();
		for(int i=0;i<N;i++)L[i]=-1;
		dfs(0,-1);
		X.clear();
		for(int i=0;i<1<<K;i++)if(OK[i])X.push_back(i);
		dp[0]=0;
		for(int i=0;i+1<1<<K;i++)if(dp[i]<(int)1e9)
		{
			for(int j:X)dp[i|j]=min(dp[i|j],dp[i]+1);
		}
		cout<<dp[(1<<K)-1]<<"\n";
	}
}
