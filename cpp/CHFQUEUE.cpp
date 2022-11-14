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

    int N, K;
    cin >> N >> K;
    int A[N];
    range(i, 0, N)cin >> A[i];

    int ans = 1;

    multiset<pair<int, int>> mp;
    range(i, 0, N) {
//        cout << i << ' ';
        int s = A[i];
        auto it = mp.upper_bound(make_pair(s+1, -1));

        while (it != mp.end()) {
//            cout << it->first;
            auto tmp = it;
            int idx = it->second;
            ans *= (i - idx + 1);
            ans %= mod;
            it++;
            mp.erase(tmp);
        }

        mp.insert(make_pair(s, i));
//        cout << '\n';
    }
    cout << ans << '\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

//    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
