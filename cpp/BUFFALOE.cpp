#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -2137483648
#define index(c) (((int) c) - 97)
//#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

void solve(){

    int N, K;
    cin >> N >> K;
    int A[N];
    range(i, 0, N){
        cin >> A[i];
    }
    K /= 2;
    K = min(K, N / 2);
    int dp[K + 1][N + 1];
    range(i, 0, K + 1) range(j, 0, N + 1) dp[i][j] = MIN_INT;
    range(i, 0, N + 1){
        dp[0][i] = 0;
    }
    range(i, 1, K + 1){
        range(j, 2 * i, N + 1){
            int mx = dp[i][j - 1];
            range(p, 0, j - 1){
                mx = max(mx, dp[i - 1][p] + A[j - 1] - A[p]);
            }
            dp[i][j] = mx;
        }
    }
    int ans = 0;
    range(i, 0, K + 1){
        range(j, 0, N + 1){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;

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