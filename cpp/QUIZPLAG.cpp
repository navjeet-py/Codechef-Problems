#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long

#define mod 1000000007
#define print(x) cout << (x) << endl
#define maximum 1000000000000000000

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}



void solve() {

    int N, M, K;
    cin >> N >> M >> K;
    int attempt[N];
    range(i, 0, N) attempt[i] = 0;
    vector<int> bad;
    range(i, 0, K){
        int a;
        cin >> a;
        if (a > N) continue;
        a--;
        attempt[a]++;
        if (attempt[a] == 2) bad.push_back(a + 1);
    }

    sort(bad.begin(), bad.end());
    cout << bad.size() << ' ';
    for(int pp: bad) cout << pp << ' ';
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
