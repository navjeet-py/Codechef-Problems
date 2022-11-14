#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl


void solve() {


    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a + b  + c + d) % 2 == 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
