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

    int N;
    cin >> N;
    int A[N];
    range(i, 0, N) cin >> A[i];
    sort(A, A + N);

    map<int, int> mp;
    range(i, 0, N) mp[A[i]] = i + 1;

    int dp[N][N];
    range(i, 0, N){
        range(j, 0, N){
            if(i == j) dp[i][j] = 1;
            else if (i > j) dp[i][j] = 0;
            else dp[i][j] = 2;
        }
    }

    for(int i = N - 1; i >= 0; i--){
        range(j, i + 1, N){
            int p = A[j] - A[i] + A[j];
            if (mp[p] == 0) continue;
            int k = mp[p] - 1;
            dp[i][j] = dp[j][k] + 1;
        }
    }

    int mx = 0;
    range(i, 0, N) range(j, 0, N) mx = max(dp[i][j], mx);
    cout << mx << endl;


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
