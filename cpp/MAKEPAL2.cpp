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
    string S;
    cin >> S;
    int one = 0, zero = 0;
    range(i, 0, N) {
        if (S[i] == '1') one++;
        else zero++;
    }
    char c = '1';

    if (one < zero) c = '0';
    range(i, 0, N - N / 2) cout << c;
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
