#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define el cout << '\n'
#define mod 1000000007
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}


void solve() {

    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int before[N + 1];
    before[0] = 0;
    range(i, 0, N) {
        if (S[i] == '0') before[i + 1] = 0;
        else before[i + 1] = before[i] + 1;
    }

    int from[N + 1];
    from[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == '0') from[i] = 0;
        else from[i] = from[i + 1] + 1;
    }

    int mx = 0;
    for(int i = 0; i < N; i++){
        if (i + K > N) break;
        int score = before[i] + K + from[i + K];
        mx = max(mx, score);
    }
    cout << mx << '\n';


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
