#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
//#define mod 1000000007
#define MIN_INT -21374836486346565
#define index(c) (((int) c) - 65)
#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}



void solve() {



    int N;
    cin >> N;
    string S;
    cin >> S;
    int onesTill[N + 1];
    char c;
    onesTill[0] = 0;

    range(i, 1, N + 1){
        c = S[i - 1];
        onesTill[i] = onesTill[i-1];
        if (c == '1') onesTill[i]++;
    }

    int zeroesFrom[N + 1];
    zeroesFrom[N] = 0;
    for(int i = N - 1; i >= 0; i--){
        zeroesFrom[i] = zeroesFrom[i + 1];
        if (S[i] == '0') zeroesFrom[i]++;
    }

    int mn = 99999999;
    range(i, 0, N + 1) mn = min(mn, zeroesFrom[i] + onesTill[i]);
    cout << mn << endl;



}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("mooyomooyo.in", "r", stdin);
//    freopen("mooyomooyo.out", "w", stdout);

    int T = 1;

    cin >> T;


    while (T--) {
        solve();

    }

    return 0;
}
