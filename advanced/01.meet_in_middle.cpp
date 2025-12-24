#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<long long>& mp, long long target) {
    int left = 0, right = mp.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (mp[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int upperBound(vector<long long>& mp, long long target) {
    int left = 0, right = mp.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (mp[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

void calculateSubset(int left, int right, vector<long long>& mp, vector<int>& a) {
    int num = 1 << (right - left + 1);

    for (int mask = 0; mask < num; mask++) {
        long long currSum = 0;

        for (int i = left; i <= right; i++) {
            int bitPos = i - left;
            if ((mask >> bitPos) & 1) {
                currSum += a[i];
            }
        }
        mp[mask] = currSum;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mid = n / 2;

    vector<long long> mp1(1 << mid);
    vector<long long> mp2(1 << (n - mid));

    calculateSubset(0, mid - 1, mp1, a);
    calculateSubset(mid, n - 1, mp2, a);

    sort(mp1.begin(), mp1.end());

    long long ans = 0;

    for (int i = 0; i < mp2.size(); i++) {
        long long target = x - mp2[i];
        int l = lowerBound(mp1, target);
        int r = upperBound(mp1, target);
        ans += (r - l);
    }

    cout << ans << '\n';
    return 0;
}
