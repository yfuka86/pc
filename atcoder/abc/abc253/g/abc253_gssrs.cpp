#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  long long L, R;
  cin >> N >> L >> R;
  L--;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    A[i] = i + 1;
  }
  long long S = 0;
  int t;
  for (int i = 0; i < N - 1; i++){
    long long T = S + (N - 1 - i);
    if (S <= L && R <= T){
      for (int j = i + 1 + L - S; j < i + 1 + R - S; j++){
        swap(A[i], A[j]);
      }
    } else if (S <= L && L < T && R > T){
      for (int j = i + 1 + L - S; j < N; j++){
        swap(A[i], A[j]);
      }
      t = i + 1;
    } else if (S > L && S < R && R <= T){
      if (t < i){
        reverse(A.end() - (i - t), A.end());
        rotate(A.begin() + t, A.end() - (i - t), A.end());
      }
      for (int j = i + 1; j < i + 1 + R - S; j++){
        swap(A[i], A[j]);
      }
    }
    S = T;
  }
  for (int i = 0; i < N; i++){
    cout << A[i];
    if (i < N - 1){
      cout << ' ';
    }
  }
  cout << endl;
}
