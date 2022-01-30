#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  string N;
  cin >> N;
  int M;
  cin >> M;
  vector<int> C(M);
  for (int i = 0; i < M; i++){
    cin >> C[i];
  }
  int S = 0;
  for (int i = 0; i < M; i++){
    S |= 1 << C[i];
  }
  int L = N.size();
  vector<vector<vector<long long>>> cnt(L + 1, vector<vector<long long>>(2, vector<long long>(1 << 10, 0)));
  vector<vector<vector<long long>>> sum(L + 1, vector<vector<long long>>(2, vector<long long>(1 << 10, 0)));
  for (int i = 1; i < N[0] - '0'; i++){
    cnt[1][1][1 << i] = 1;
    sum[1][1][1 << i] = i;
  }

  cnt[1][0][1 << (N[0] - '0')] = 1;
  sum[1][0][1 << (N[0] - '0')] = N[0] - '0';
  for (int i = 1; i < L; i++){
    for (int j = 1; j <= 9; j++){
      cnt[i + 1][1][1 << j] = 1;
      sum[i + 1][1][1 << j] = j;
    }
  }
  for (int i = 1; i < L; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < (1 << 10); k++){
        for (int l = 0; l < 10; l++){
          if (!(j == 0 && l > N[i] - '0')){
            int j2 = j;
            if (l < N[i] - '0'){
              j2 = 1;
            }
            int k2 = k | (1 << l);
            cnt[i + 1][j2][k2] += cnt[i][j][k];
            cnt[i + 1][j2][k2] %= MOD;
            sum[i + 1][j2][k2] += sum[i][j][k] * 10 + cnt[i][j][k] * l;
            sum[i + 1][j2][k2] %= MOD;
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < (1 << 10); i++){
    if ((i & S) == S){
      ans += sum[L][0][i] + sum[L][1][i];
    }
  }
  ans %= MOD;
  cout << ans << endl;
}
