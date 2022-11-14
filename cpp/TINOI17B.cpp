#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define mod2 100000000
#define MIN_INT -99999999496346565
#define MAX_INT 99999999496346565
#define index(c) (((int) c) - 97)
#define int long long
#define in(a) int a; cin >> a;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int digit_cube(int P) {
    int sm = 0;
    while (P > 0) sm += P % 10, P /= 10;
    return sm * sm * sm;
}


void solve() {

    int N, S;
    cin >> N >> S;
    int E[N];
    range(i, 0, N) cin >> E[i];

    int train[N + 1];
    train[0] = S;
    range(i, 1, N + 1) train[i] = train[i - 1] + digit_cube(train[i - 1]);

    int dp[N + 1][N + 1];
    // dp[i][j] = maximum XV after i days in which he fought j days and trained (i - j) days

    // INITIALIZE VALUES
    range(i, 0, N + 1){
        range(j, 0, N + 1){
            if (j == 0) dp[i][j] = 0;
            else dp[i][j] = MIN_INT;
        }
    }
    // FILL THE TABLE

    range(i, 1, N + 1){
        range(j, 1, i + 1){
            // If training
            dp[i][j] = dp[i - 1][j];

            // If fought
            int increase = E[i - 1] * train[i - j] + dp[i - 1][j - 1];

            dp[i][j] = max(dp[i][j], increase);
        }
    }

    int mx = 0;
    range(i, 0, N + 1) mx = max(mx, dp[N][i]);
    cout << mx << endl;



}

int32_t main() {


   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);


    int T = 1;

//    cin >> T;

    while (T--) {
        solve();

    }

}
