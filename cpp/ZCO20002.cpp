#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 100000007
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

int A[100], B[100];
int dp[101][101][2][201];

int answer(int i, int j, int lastFrom, int k) {

    if (dp[i][j][lastFrom][k] != -1) return dp[i][j][lastFrom][k];

//    cout << i << ' ' << j << ' ' << lastFrom << ' ' << k << endl;
    if(i + j < k || k < 0) return 0;
    if (i == 0 && j == 0) return 1;
    if (i == 0 && lastFrom == 0) return 0;
    if (j == 0 && lastFrom == 1) return 0;
    if (j == 1 && i == 0) {
        if (k == 0) return 0;
        else return 1;
    }
    if (j == 0 && i == 1){
        if(k == 0) return 0;
        else return 1;
    }



    int ans = 0;
    int last;
    if (lastFrom == 0) last = A[i - 1], i--;
    else last = B[j - 1], j--;


    // if 2nd last from B
    if (j > 0) {
        int p = 0;
        if (B[j - 1] == last) {
            p = answer(i, j, 1, k);
        } else {
            p = answer(i, j, 1, k - 1);
        }
        ans += p;
    }

    // if 2nd last from A

    if (i > 0) {
        int p = 0;
        if (A[i - 1] == last) {
            p = answer(i, j, 0, k);
        } else {
            p = answer(i, j, 0, k - 1);
        }
        ans += p;
    }
    if (lastFrom == 0) i++;
    else j++;
    ans %= mod;
    return dp[i][j][lastFrom][k] = ans;
}


void solve() {

    int N, M, K;
    cin >> N >> M >> K;

    range(i, 0, N) cin >> A[i];
    range(i, 0, M) cin >> B[i];
    range(i, 0, N + 1) {
        range(j, 0, M + 1) {
            range(l, 0, 2) {
                range(k, 0, K + 1) {
                    dp[i][j][l][k] = -1;
                }
            }
        }
    }
    int a = answer(N, M, 0, K);
    int b = answer(N, M, 1, K);
    int ans = a + b;
    ans %= mod;
    while (ans < 0) ans += mod;
    cout << ans << endl;



}

int32_t main() {


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
