#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl


void solve() {

    int N, X;
    cin >> N >> X;
    int R = N - X;
    if (R <= 0) cout << 0 << '\n';
    else{
        int cnt = R / 4;
        if (R % 4 != 0) cnt++;
        cout << cnt << '\n';
    }


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
