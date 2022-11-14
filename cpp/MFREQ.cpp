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
    int N, M;
    cin >> N >> M;
    int A[N];
    range(i , 0 , N) cin >> A[i];

    int forward[N], backward[N];
    forward[0] = 1;
    range(i, 1, N) {
        if (A[i] == A[i - 1]) forward[i] = forward[i - 1] + 1;
        else forward[i] = 1;
    }

    backward[N - 1] = 1;
    for(int i = N - 2; i >= 0; i--){
        if (A[i] == A[i + 1]) backward[i] = backward[i + 1] + 1;
        else backward[i] = 1;
    }

//    print_array(forward, N);
//    print_array(backward, N);

    range(i, 0, M){
        int l, r, k;
        cin >> l >> r >> k;

        l--, r--;
        int mid = (l + r) / 2;
        int req = A[mid];
        int size = min(mid - l + 1, forward[mid]) + min(backward[mid], r - mid + 1) - 1;
//        cout << size << '\n';
        if (size >= k) {
            cout << req << '\n';
        }else{
            cout << -1 << '\n';
        }

    }





}


int32_t main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    int T = 1;

//    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
