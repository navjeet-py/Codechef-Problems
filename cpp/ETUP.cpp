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

int C2(int k){
    if (k <= 1) return 0;
    return (k * (k - 1)) / 2;
}


int C3(int k){
    if (k <= 2) return 0;
    return (k * (k - 1) * (k - 2)) / 6;
}


void solve(){
    int N, Q;
    cin >> N >> Q;
    int A[N];
    range(i, 0, N) cin >> A[i];
    int counts[N + 1];
    counts[0] = 0;
    range(i, 1, N + 1){
        counts[i] = counts[i - 1] + (A[i - 1] % 2 == 0);
    }
    range(q, 0, Q){
        int l, r;
        cin >> l >> r;
        int odd = r - l + 1;
        int evens = counts[r] - counts[l - 1];
        odd -= evens;
        int ans = C2(odd) * evens + C3(evens);
        cout << ans << '\n';
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
