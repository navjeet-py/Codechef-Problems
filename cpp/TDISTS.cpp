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

    int x, y;
    cin >> x >> y;
    int N = (int) sqrt(x + y);
    if (N * N != x + y || y % 2 == 1){
        cout << "NO\n";
        return;
    }
    int product = y / 2;
    int val = x - N;
    if (val < 0){
        cout << "NO\n";
        return;
    }
    int odd = 0, even = 0;
    range(a, 1, (int) sqrt(product) + 3){
        if (product % a == 0){
            int b = product / a;
            if (a * a + b * b - a - b == val){
                odd = min(a, N - a);
                even = N - odd;
            }
        }
    }
    if (odd < 1 || even < 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << N << '\n';
    range(i, 2, even + 2){
        cout << 1 << ' ' << i << '\n';
    }
    range(i, even + 2, N + 1){
        cout << 2 << ' ' << i << '\n';
    }





}


int32_t main() {
//    cout << (1 << 3);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
