#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 500005;
int a[MAXN];

int main() {
    int n;
    cin >> n;

    // 靴下の色の出現回数をカウントする
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int ans = 0;

    // 同じ色の靴下をペアにする
    for (auto p : mp) {
        ans += p.second / 2;
    }

    cout << ans << endl;

    return 0;
}
