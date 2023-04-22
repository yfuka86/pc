#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=200005;
const ll INF=1LL<<60;

ll dp[2][7][7][7];
ll rui[MAX];

int main(){

    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q;cin>>Q;
    while(Q--){
        int K;cin>>K;
        string S;cin>>S;
        int N=si(S);
        for(int i=0;i<=N;i++){
            rui[i]=0;
        }

        for(int s=0;s<2;s++) for(int j=0;j<=K;j++) for(int k=0;k<=K;k++) for(int l=0;l<=K;l++) dp[s][j][k][l]=INF;

        for(int i=1;i<=N;i++){
            rui[i]=rui[i-1];
            if(S[i-1]=='(') rui[i]++;
            if(S[i-1]==')') rui[i]--;
        }

        dp[0][0][0][0]=0;

        for(int i=0;i<=N;i++){
            int s=i&1,t=s^1;
            for(int al=0;al<=K;al++){
                for(int a=K;a>=0;a--){
                    for(int b=K;b>=0;b--){
                        if(dp[s][al][a][b]==INF) continue;
                        ll d=rui[i]-a+b;
                        if(i<N){
                            chmin(dp[t][al+1][a+(S[i]=='(')][b+(S[i]==')')],dp[s][al][a][b]);
                            if(S[i]=='('){
                                chmin(dp[t][al][a][b],dp[s][al][a][b]+d);
                            }
                            if(S[i]==')'){
                                if(d>=1) chmin(dp[t][al][a][b],dp[s][al][a][b]);
                            }
                        }

                        if(a){
                            chmin(dp[s][al][a-1][b],dp[s][al][a][b]+d);
                        }
                        if(b&&d>=1){
                            chmin(dp[s][al][a][b-1],dp[s][al][a][b]);
                        }
                    }
                }
            }
            if(i==N) break;
            for(int al=0;al<=K;al++){
                for(int a=K;a>=0;a--){
                    for(int b=K;b>=0;b--){
                        dp[s][al][a][b]=INF;
                    }
                }
            }
        }

        ll ans=INF;

        for(int al=0;al<=K;al++){
            chmin(ans,dp[N&1][al][0][0]);
        }

        cout<<ans<<"\n";
    }
}
