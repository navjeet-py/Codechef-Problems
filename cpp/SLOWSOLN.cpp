#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl


void solve() {


    int T, N, sm;
    cin >> T >> N >> sm;
    int ans = 0;
    if (N * T <= sm){
        ans = N * N * T;
        cout <<ans << '\n';
        return;
    }

    int it = sm / N;
    int rest = sm % N;
    ans  = it * N * N + rest * rest;
    cout << ans << '\n';


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
