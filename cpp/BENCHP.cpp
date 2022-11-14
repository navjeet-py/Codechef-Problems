#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}


void solve() {


    int N, required, already;
    cin >> N >> required >> already;

    map<int, int> cnt;
    range(i, 0, N){
        int a;
        cin >> a;
        cnt[a]++;
    }

    for(auto it: cnt){
        already += ((it.second / 2) * 2 * it.first);
    }
    if (already >= required) cout << "YES\n";
    else cout << "NO\n";


}


int32_t main() {
//    cout << (1 << 3);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
