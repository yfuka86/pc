#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int x = 0,y = 0,t = 1;
        int s1 = 0,s2 = 0;
        while(n) {
            int now = n%10;
            if(s1 > s2) {
                x += t*(now/2);
                y += t*((now+1)/2);
                s1 += (now/2);
                s2 += ((now+1)/2);
            }
            else {
                y += t*(now/2);
                x += t*((now+1)/2);
                s2 += (now/2);
                s1 += ((now+1)/2);
            }
            t *= 10;
            n /= 10;
        }
        cout << x << " " << y << "\n";
    }
}
