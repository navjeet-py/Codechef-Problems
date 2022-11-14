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
    int A[N];
    int sm = 0;
    range(i, 0, N){
        cin >> A[i];
        sm += A[i];
    }

    if (sm % 3 != 0) {
        cout << 0 << endl;
        return;
    }
    int req = sm / 3;

    vector<int> start;
    sm = A[0];
    if (A[0] == req) start.push_back(0);
    range(i, 1, N){
        sm += A[i];
        if (sm == req) start.push_back(i);
    }

    vector<int> end;
    sm = A[N - 1];
    if (sm == req) end.push_back(N - 1);
    for(int i = N - 2; i >= 0; i--){
        sm += A[i];
        if (sm  == req) end.push_back(i);
    }
    sort(end.begin(), end.end());
//    for(int p: start) cout << p << ' ';
//    cout << '\n';
//    for(int p: end) cout << p << ' ';
//    cout << '\n';
    int size = end.size();
    int ans = 0;
    for(int p: start){
        auto it = lower_bound(end.begin(), end.end(), p + 1) - end.begin();
        if (end[it] == p + 1) {
            it++;
        }
        ans += (size - it);
    }
    cout << ans << endl;



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
