#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    long x, y;
    cin >> x >> y ; // row, coloumn

    long ans = 0;

    if(x > y){
        if(x % 2 == 0){
            // a perfect square in a row.
            ans = x*x - (y - 1);
        }
        else{
            // not a perfect square in a row. 
            ans = ((x - 1)*(x - 1) + 1) + (y - 1);
        }
    }
    // y > x
    else{
        if(y % 2 == 1){
            // a perfect square in a col.
            ans = y*y - (x - 1);
        }
        else{
            // not a perfect quare in a col.
            ans = ((y - 1) * (y - 1) + 1) + (x - 1);
        }
    }
    cout << ans << endl;
}
int main(){
    int t ;
    cin >> t;

    while(--t >= 0){
        solve();
    }
    return 0;
}