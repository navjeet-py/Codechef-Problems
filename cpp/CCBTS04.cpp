#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
//#define vi vector<int>
#define mod 1000000007
#define mod2 100000000
#define MIN_INT -99999999496346565
#define MAX_INT 99999999496346565
#define index(c) (((int) c) - 97)
#define int long long
#define ask(j) cout << "? " << j << '\n'; cin >> A[j];
#define ans(i) cout <<"! " << i << endl; cout.flush(); return;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}



void solve() {

    int N;
    cin >> N;
    int heights[N], iq[N];
    range(i, 0, N){
        cin >> heights[i];
    }
    range(i, 0, N) cin >> iq[i];

    int dp[N];
    dp[0] = 1;
    range(i, 1, N){
        dp[i] = 1;
        range(j, 0, i){
            if (heights[j] < heights[i] && iq[j] > iq[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int mx = 1;
    range(i, 1, N) mx = max(mx, dp[i]);
    cout << mx << endl;

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
