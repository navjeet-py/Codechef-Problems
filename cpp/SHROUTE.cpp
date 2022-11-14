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

int *A;
int *B;


void solve() {

    int N, M;
    cin >> N >> M;
    A = new int[N];
    B = new int[M];
    range(i, 0, N) cin >> A[i];
    range(i, 0, M) cin >> B[i];
    int before[N], after[N];
    int last = -1;
    range(i, 0, N){
        if (A[i] == 1) last = i;
        before[i] = last;
    }
    last = -1;
    for(int i = N - 1; i >= 0; i--){
        if (A[i] == 2) last = i;
        after[i] = last;
    }

    range(j, 0, M){
        int i = B[j] - 1;
        if (i == 0) {
            cout << 0 << ' ';
            continue;
        }
        int val = 9999999999999999;
        if (after[i] != -1) val = min(val, after[i] - i);
        if (before[i] != -1) val = min(val, i - before[i]);
        if (val == 9999999999999999) cout << -1 << ' ';
        else cout << val << ' ';
    }
    cout << '\n';
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
