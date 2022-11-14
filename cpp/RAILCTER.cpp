#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1e9 + 7
#define MIN_INT -2147483648

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}





void solve() {
    int N, K;
    cin >> N >> K;
    int A[N];
    range(i, 0, N) cin >> A[i];

    int dp[N];
    dp[0] = A[0];
    range(i, 1, N){
        dp[i] = max(dp[i - 1] + A[i], A[i]);
    }
    int sum_K[N];
    int sm = 0;
    range(i, 0, K) sm += A[i];
    sum_K[K - 1] = sm;
    range(i, K, N) sum_K[i] = sum_K[i - 1] + A[i] - A[i - K];
//    print_array(dp, N);
//    print_array(sum_K, N);
    int ans = sm;
    range(i, K, N){
        ans = max(ans, max(sum_K[i], sum_K[i] + dp[i - K]));
//        cout << sum_K[i] << ' ' << dp[i - K] << endl;
    }
    cout << ans << endl;

}


int main() {

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
