#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -99999999496346565
#define MAX_INT 99999999496346565
#define index(c) (((int) c) - 97)
#define int long long
#define in(a) int a; cin >> a;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}


void solve() {

    int N;
    cin >> N;
    pair<int, int> A[N];
    range(i, 0, N){
        int a, b, c;
        cin >> a >> b >> c;
        b += c;
        A[i] = make_pair(b, a);
    }
    sort(A, A + N);
    int time = 0;
    int mx = 0;
    for(int i = N - 1; i >= 0; i--){
        time += A[i].second;
        mx = max(mx, time + A[i].first);
    }
    cout << mx << endl;




}

int32_t main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);


    int T = 1;


//    cin >> T;


    while (T--) {
        solve();

    }

    return 0;
}
