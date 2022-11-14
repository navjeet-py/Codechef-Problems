#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl


void solve() {

    int A, B, C;
    cin >> A >> B >> C;

    string pass = "FAIL";
    if (A > 9 && B > 9 && C > 9 && A + B + C > 99) pass = "PASS";
    cout << pass << '\n';


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
