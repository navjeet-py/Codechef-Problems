#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}


int main() {
    int mod = 1000000009;
    static int dp[1000001];
    dp[0] = 0, dp[1] = 0, dp[2] = 1, dp[3] = 1;
    range(i, 4, 1000001) {
        dp[i] = (dp[i - 2] + dp[i - 3]) % mod;
    }

    int T, X;
    cin >> T;
    while(T--){
        cin >> X;
        cout << dp[X] << endl;
    }

    return 0;
}