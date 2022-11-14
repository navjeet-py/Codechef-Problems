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
    int mx = max(A, max(B, C));
    if (mx == A) cout << "ALICE\n";
    else if (mx == B) cout << "BOB\n";
    else cout << "CHARLIE\n";




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
