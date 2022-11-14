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


    int N;
    cin >> N;
    int A[N];
    range(i, 0, N) cin >> A[i];
    int pre_sum[N];
    pre_sum[0] = A[0];
    range(i, 1, N) pre_sum[i] = pre_sum[i - 1] + A[i];
    // forward
    int ans = 0;
    map<int, int> mp;
    range(cut_after, 0, N - 1){
        mp[A[cut_after]]++;
        int left_sm = pre_sum[cut_after];
        int right_sm = pre_sum[N - 1] - left_sm;
        int req = left_sm - right_sm;
        ans += mp[req];

    }

    // backward
    mp.clear();
    for(int cut_after = N - 1; cut_after >= 1; cut_after--){
        mp[A[cut_after]]++;
        int left_sm = pre_sum[cut_after - 1];
        int right_sm = pre_sum[N - 1] - left_sm;
        int req = right_sm - left_sm;
        ans += mp[req];
    }

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
