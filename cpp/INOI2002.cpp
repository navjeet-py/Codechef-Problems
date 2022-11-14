#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -21374836486346565
#define MAX_INT 21374836486346565
#define index(c) (((int) c) - 97)
#define int long long
#define in(a) int a; cin >> a;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}


void solve() {

    int N, K;
    cin >> K >> N;
    if (K == 1) {
        if (N % 3 == 0) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    if (K == 2) {
        int dp[max(N + 1, (int) 4)];
        dp[0] = dp[1] = 0, dp[2] = dp[3] = 1;
        range(i, 4, N + 1) {
            dp[i] = (dp[i - 3] + dp[i - 2]) % mod;
        }
        cout << dp[N] << endl;
        return;
    }

    int A[max((int) 5, N + 1)];
    int B[max((int) 5, N + 1)];
    int C[max((int) 5, N + 1)];

    // BASE CASES
    A[0] = 0, A[1] = A[2] = 1, A[3] = 2, A[4] = 3;
    B[0] = B[1] = B[2] = B[3] = 0, B[4] = 1;
    C[0] = C[1] = 0, C[2] = 1, C[3] = 1, C[4] = 1;

    // DP

    range(i, 5, N + 1) {
        A[i] = (A[i - 1] + A[i - 3] + 2 * B[i - 2]) % mod;

        B[i] = (B[i - 3] + C[i - 2]) % mod;

        C[i] = (A[i - 2] + C[i - 3]) % mod;
    }

//    print_array(A, 7);
    cout << A[N] << endl;


}

int32_t main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);


    int T = 1;

    cin >> T;


    while (T--) {
        solve();

    }

    return 0;
}
