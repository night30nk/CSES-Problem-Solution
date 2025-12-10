#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long powerMod(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y % 2 == 1) { 
            res = (res * x) % MOD;
        }
        y = y / 2;
        x = (x * x) % MOD;
    }
    return res;
}

void solve() {
    long long n;
    cin >> n;
    cout << powerMod(2, n) << endl;
}

int main() {
    // int t;
    // cin >> t;
    // while (--t >= 0) {
        solve();
    // }
    return 0;
}
