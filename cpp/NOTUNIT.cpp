#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N){
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}



void solve(){


    int a, b;
    cin >> a >> b;
    if (a % 2 == 0){
        if (b < a + 2){
            cout << -1 << '\n';
            return;
        }
        cout << a << ' ' << a + 2 << '\n';
        return;
    }
    if (b < a + 3) {
        cout << -1 << '\n';
        return;
    }
    if (a % 3 == 0) cout << a  << " " << a + 3 << '\n';
    else cout << a + 1 <<  ' ' << a + 3 << '\n';




}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    cin >> T;

    while(T--){
        solve();
    }


    return 0;
}