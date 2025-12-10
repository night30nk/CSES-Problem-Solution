#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int fives(int i){
    int count = 0;
    // till the time, it's not dividing with 5, that means it has no more factors of 5
    while(i % 5 == 0){
        count++;
        i /= 5;
    }
    return count;
}

void solve() {
    int n;
    cin >> n;
    
    int ans = 0;
    for(int i = 5; i <= n; i += 5){
        // just check for all no. that how many 5 is appearing in their codes. 
        ans += fives(i);
    }
    cout << ans << endl;
}

int main() {
    // int t;
    // cin >> t;
    // while (--t >= 0) {
        solve();
    // }
    return 0;
}
