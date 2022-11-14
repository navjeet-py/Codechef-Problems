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

int C2(int k){
    if (k <= 1) return 0;
    return (k * (k - 1)) / 2;
}


int C3(int k){
    if (k <= 2) return 0;
    return (k * (k - 1) * (k - 2)) / 6;
}


void solve(){


    double X, Y;
    cin >> X >> Y;
    double sm = X + Y;
    double prob = 0;
    if (sm < 6) prob = (6 - sm) / 6;
    cout << fixed << setprecision(10) << prob << '\n';




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
