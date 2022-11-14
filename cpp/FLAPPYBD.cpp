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

int *x, *h, *alpha;

void solve(){

    int N, H;
    cin >> N >> H;
    x = new int[N];
    h = new int[N];
    alpha = new int[N];
    range(i, 0, N) cin >> x[i];
    range(i, 0, N) cin >> h[i];

    range(i, 0, N) {
        alpha[i] = (h[i] + x[i] - H + 1) / 2;
        if (alpha[i] * 2 <= h[i] + x[i] - H) alpha[i]++;
    }
//    print_array(x, N);
//    print_array(h, N);
//    print_array(alpha, N);
    bool possible = true;
    range(i, 0, N) if (alpha[i] > x[i]) possible = false;

    if (!possible){
        cout << -1 << '\n';
        return;
    }

    int mx = 0;
    range(i, 0, N) mx = max(mx, alpha[i]);
    cout << mx << '\n';



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
