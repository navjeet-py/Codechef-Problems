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
    cin >> N >> K;
    int V[N], B[N];
    range(i, 0, N) cin >> V[i];
    range(i, 0, N) cin >> B[i];

    int dp[N][N];
    range(i, 0, N) range(j, 0, N) dp[i][j] = 0;
    range(length, 2, N + 1){
        range(start, 0, N - length + 1){
            int end = start + length - 1;
            if (B[end] - B[start] == K){
                dp[start][end] = max(dp[start + 1][end - 1] + V[start] + V[end], dp[start][end]);
            }

            range(k, start, end){
                dp[start][end] = max(dp[start][end], dp[start][k] + dp[k + 1][end]);
            }
        }
    }

//    range(i, 0, N) print_array(dp[i], N);
    

    cout << dp[0][N - 1] << endl;



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

    return 0;
}
