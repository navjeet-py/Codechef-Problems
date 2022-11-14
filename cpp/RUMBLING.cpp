#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

void solve() {


    int N, X, Y;
    string S;

    cin >> N;
    cin >> S;
    cin >> X >> Y;

    int costs[N + 1];
    costs[0] = 0;

    for(int i = 0; i < N; i++){
        int c = 0;
        if (S[i] == 'E') c = min(2 * X, 2 * Y);
        if (S[i] == 'N') c = min(3 * X, Y);
        if (S[i] == 'S') c = min(X, 3 * Y);

        costs[0] += c;
    }

    for(int i = 1; i < N + 1; i++){
        int initial = 0, final = 0;
        if (S[i - 1] == 'E') initial = min(2 * X, 2 * Y);
        if (S[i - 1] == 'N') initial = min(3 * X, Y);
        if (S[i - 1] == 'S') initial = min(X, 3 * Y);

        if (S[i - 1] == 'W') final = min(2 * X, 2 * Y);
        if (S[i - 1] == 'S') final = min(3 * X, Y);
        if (S[i - 1] == 'N') final = min(X, 3 * Y);

        costs[i] = costs[i - 1] + final - initial;
    }


//    print_array(costs, N + 1);
    int mn = costs[0];
    for(int a: costs) mn = min(mn, a);
    cout << mn << '\n';


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
