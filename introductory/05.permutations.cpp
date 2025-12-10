#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n ;
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return;
    }
    if(n < 4){
        cout << "NO SOLUTION" << endl;
        return;
    }
    if(n == 4) {
        cout << "2 4 1 3" << endl;
        return;
    }
    for(int i = 1; i <= n; i += 2){
        cout << i << " " ;
    }
    for(int i = 2; i <= n; i += 2){
        cout << i << " " ;
    }

}
int main(){
    solve();
    return 0;
}