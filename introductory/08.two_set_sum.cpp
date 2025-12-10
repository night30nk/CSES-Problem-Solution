#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;

    if (sum % 2 == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    
    long long halfSum = sum / 2;
    unordered_set<long long> pair1;

    long long element = n;
    while (element > 0 && element < halfSum) {
        pair1.insert(element);
        halfSum -= element;
        element--;
    }
    if (halfSum != 0) pair1.insert(halfSum);

    cout << pair1.size() << "\n";
    for (long long num : pair1) {
        cout << num << " ";
    }
    cout << "\n";

    vector<long long> pair2;
    for (long long i = 1; i < n; i++) {
        if (pair1.find(i) == pair1.end()) {
            pair2.push_back(i);
        }
    }

    cout << pair2.size() << "\n";
    for (long long num : pair2) {
        cout << num << " ";
    }
}

int main() {
    // int t;
    // cin >> t;
    // while (--t >= 0) {
        solve();
    // }
    return 0;
}
