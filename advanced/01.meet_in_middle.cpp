#include <bits/stdc++.h>
using namespace std;
 
void calculateSubset(int left, int right, long long sum, unordered_map<long long, long long> &mp, const vector<int> &a) {
    if (left > right) {
        mp[sum]++;
        return;
    }
 
    // include a[left]
    calculateSubset(left + 1, right, sum + a[left], mp, a);
 
    // exclude a[left]
    calculateSubset(left + 1, right, sum, mp, a);
}
 
void solve() {
    int n;
    long long x;
    cin >> n >> x;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
 
    unordered_map<long long, long long> mp1, mp2;
 
    calculateSubset(0, n / 2, 0, mp1, a);
    calculateSubset(n / 2 + 1, n - 1, 0, mp2, a);
 
    long long ans = 0;
 
    for (auto &entry : mp1) {
        long long sum = entry.first;
        long long freq = entry.second;
 
        long long rem = x - sum;
        if (mp2.count(rem)) {
            ans += freq * mp2[rem];
        }
    }
 
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    while (t--) {
        solve();
    }
 
    return 0;
}