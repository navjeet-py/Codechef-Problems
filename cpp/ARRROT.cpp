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


    int N;
    cin >> N;
    int a, sm = 0;
    range(i, 0, N){
        cin >> a;
        sm += a;
    }
    int Q;
    cin >> Q;
    while(sm < 0) sm += mod;
    range(i, 0, Q){
        cin >> a;
        sm *= 2;
        sm %= mod;
        cout << sm << '\n';
    }

}


int32_t main() {
//    cout << (1 << 3);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

//    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
