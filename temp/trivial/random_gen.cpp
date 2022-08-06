#include <iostream>
#include <vector>
using namespace std;

void random_generate(int N, vector<int> &A, vector<int> &B) {
    // ここでランダム生成をする。例えば次のような感じ。
    // for (int i = 0; i < N; i++) A[i] = rand() % 10 + 1;
    // for (int i = 0; i < N; i++) B[i] = rand() % 10 + 1;
}

int solve(int N, vector<int> A, vector<int> B) {
    // ここに自分のプログラムを書き、自分の答えを返す。
}

int solve_Jury(int N, vector<int> A, vector<int> B) {
    // ここに「遅いが正しいプログラム」を書き、正しい（と想定される）答えを返す
}

int main() {
    for (int t = 1; t <= 1000; t++) {
        int N = 8; // 入力データのサイズ（適当に決めて良い）
        vector<int> A(N), B(N); // プログラムで使用する変数
        random_generate(N, A, B);
        int J1 = solve(N, A, B);
        int J2 = solve_Jury(N, A, B);
        if (J1 != J2) {
            cout << "Wrong Answer on Test #" << t << endl;
            cout << "Jury = " << J2 << ", Output = " << J1 << endl;
            // テストケースを出力
            return 0;
        }
    }
    cout << "Yay!" << endl;
    return 0;
}
