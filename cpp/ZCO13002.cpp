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


void solve() {

    int N, K;
    cin >> N >> K;
    int grid[N][N];
    range(i, 0, N)
        range(j, 0, N)
            cin >> grid[i][j];

    bool canPass[N][N];
    range(i, 0, N) range(j, 0, N) canPass[i][j] = false;

    range(pp, 0, K){
        int x, y, s;
        cin >> x >> y >> s;
        x--; y--;
        range(i, x - s, x + s + 1){
            int k = s - abs(i - x);
            range(j, y - k, y + k + 1){

                if (i >= 0 && i < N && j >= 0 && j < N)
                    canPass[i][j] = true;
            }
        }
    }

    int dp[N][N];
    range(i, 0, N) range(j, 0, N) dp[i][j] = MIN_INT;

    if(!canPass[0][0] || !canPass[N - 1][N - 1]) {
        cout << "NO" << endl;
        return;
    }
    dp[0][0] = grid[0][0];

    range(i, 0, N){
        range(j, 0, N){
            if (!canPass[i][j]) continue;

            if (i > 0 && dp[i - 1][j] != MIN_INT) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }
            if (j > 0 && dp[i][j - 1] != MIN_INT) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
    }

    if (dp[N - 1][N - 1] == MIN_INT){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << dp[N - 1][N - 1] << endl;




}

int32_t main() {


//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);


    int T = 1;

//    cin >> T;

    while (T--) {
        solve();

    }

}
