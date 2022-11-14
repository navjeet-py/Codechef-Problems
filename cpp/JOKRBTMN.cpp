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

    int N, M, L;
    cin >> N >> M >> L;
    map<int, int> id;

    range(i, 0, M){
        int l;
        cin >> l;
        range(p, 0, l){
            int a;
            cin >> a;
            id[a] = i;
        }
    }

    int A[L];
    range(i, 0, L) cin >> A[i];
    int cnt = 1;
//    cout << id[1] << ' ' << id[2] << '\n';
    range(i, 1, L){
        if (id[A[i]] != id[A[i - 1]]) cnt++;
    }
    cout << cnt << '\n';




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
