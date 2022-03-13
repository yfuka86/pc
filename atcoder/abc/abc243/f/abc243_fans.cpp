#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

mint dp[51][51][51];
int w[51];
mint p[51];
mint fact[51];
int main(){
	int n,m,k;
	cin >> n >> m >> k;

	for(int i=0;i<n;i++)cin >> w[i];
	mint wsum=0;
	for(int i=0;i<n;i++)wsum+=w[i];
	for(int i=0;i<n;i++)p[i]=w[i]/wsum;

	fact[0]=1;
	for(int i=1;i<=50;i++)fact[i]=fact[i-1]*i;

	dp[0][0][0]=1;
	for(int x=0;x<n;x++)for(int y=0;y<=m;y++)for(int z=0;z<=k;z++){
		for(int c=0;c<=k-z;c++){
			dp[x+1][y+(c!=0)][z+c]+=dp[x][y][z]/fact[c]*p[x].pow(c);
		}
	}
	cout << (dp[n][m][k]*fact[k]).val() << endl;
}
