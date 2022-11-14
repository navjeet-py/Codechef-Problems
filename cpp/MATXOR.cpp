#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
//#define vi vector<int>
#define mod 1000000007
#define MIN_INT -99999999496346565
#define MAX_INT 99999999496346565
//#define index(c) (((int) c) - 97)
#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int solve(int m, int n, int K, int to_add){
    if (m == 0 || n == 0) return 0;
    int p = min(m, n);
    int ans = 0;
    range(i, 1, p + 1){
        ans = ans ^ (2 * i + K + to_add);
    }

    return (ans ^ solve(p, max(m, n) - p, K, to_add + p));

}

void solve() {

    int N, M, K;
    cin >> N >> M >> K;
    cout << solve(M, N, K, 0) << endl;

}


int32_t main() {

//
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);

    int T = 1;

    cin >> T;


    while (T--) {
        solve();

    }

}
