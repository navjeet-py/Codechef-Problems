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


void solve() {

    int N, K;
    cin >> N >> K;
    int A[N];
    range(i, 0, N) cin >> A[i];
    int cnt = 0;
    range(i, 0, N) cnt += A[i];
    if (cnt == 0){
        cout << 0 << '\n';
        return;
    }


    int mn = MAX_INT;
    int cur = 0;
    range(i, 0, K){
        cur += A[i];
    }
    mn = min(mn, cur);
    range(i, K, N){
        cur += A[i];
        cur -= A[i - K];
        mn = min(mn, cur);
    }

    int ans = ((mn * (mn + 1)) / 2) + (cnt - mn);
//    cout << mn << ' ' << cnt << endl;
    cout << ans << endl;
    




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
