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

bool isPowerOfTwo(int x) {
    return x && (!(x & (x - 1)));
}


void solve() {


    int L, H;
    cin >> L >> H;
    string S;
    cin >> S;

    vector<int> zeroes;

    range(i, 0, L) {
        if (S[i] == '0') {
            if (zeroes.empty()) zeroes.push_back(1);
            else {
                if (S[i - 1] == '0') zeroes[zeroes.size() - 1]++;
                else zeroes.push_back(1);
            }
        }
    }

    int N = (int) zeroes.size();
    if (N == 0) {
        cout << "NO\n";
        return;
    }
    int dp[N];
    range(i, 0, N) dp[i] = 0;
    dp[N - 1] = zeroes[N - 1];
    int mx = dp[N - 1];
    for(int i = N - 2; i >= 0; i--){
        dp[i] = max(dp[i + 1], zeroes[i] + dp[i + 1] / 2);
        mx = max(mx, dp[i]);
    }
    if (mx >= H) cout << "YES\n";
    else cout << "NO\n";



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
