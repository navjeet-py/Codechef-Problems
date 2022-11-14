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

int D;

bool grid[300][300];

int dp[300][300][2][300];

int answer(int r, int c, int last_was_top, int left) {

    if (r == 0 && c == 0) return dp[r][c][last_was_top][left] = 1;

    if (dp[r][c][last_was_top][left] != -1) return dp[r][c][last_was_top][left];

    int ans = 0;

    if (r > 0 && grid[r - 1][c]) {
        if (!last_was_top) {
            ans += answer(r - 1, c, 1, D - 1);
        } else if (left > 0) {
            ans += answer(r - 1, c, 1, left - 1);
        }
    }

    if (c > 0 && grid[r][c - 1]) {
        if (last_was_top) {
            ans += answer(r, c - 1, 0, D - 1);
        } else if (left > 0) {
            ans += answer(r, c - 1, 0, left - 1);
        }
    }
    ans %= 20011;

    return dp[r][c][last_was_top][left] = ans;

}


void solve() {

    range(i, 0, 300){
        range(j, 0, 300){
            range(k, 0, 2){
                range(l, 0, 300){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }


    int R, C;
    cin >> R >> C >> D;
    range(i, 0, R) {
        range(j, 0, C) {
            cin >> grid[i][j];
        }
    }




    int ans = 0;
    if (R == 1 && C == 1){
        cout << 1 << endl;
        return;
    }


    if (R > 1 && grid[R - 2][C - 1]) {
        ans += answer(R - 2, C - 1, 1, D - 1);
    }
    if (C > 1 && grid[R - 1][C - 2]) {
        ans += answer(R - 1, C - 2, 0, D - 1);
    }
    ans %= 20011;
    while (ans < 0) ans += 20011;
    cout << ans << endl;
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
