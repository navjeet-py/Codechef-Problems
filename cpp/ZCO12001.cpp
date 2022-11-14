#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define mod2 100000000
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
    int cnt = 0, mx = 0, mxIdx;
    int lastOne = 0;
    int ans1 = 0, ans2 = 0;
    range(i, 0, N){
        int a;
        cin >> a;
        if (a == 1) cnt++;
        else cnt--;

        if(cnt > mx) mx = cnt, mxIdx = i + 1;

        if(cnt == 0){
            if (i - lastOne + 1 > ans1){
                ans1 = i - lastOne + 1;
                ans2 = lastOne + 1;
            }
            lastOne = i + 1;
        }
    }

    cout << mx << ' ' << mxIdx << ' ' << ans1 << ' ' << ans2 << endl;


}

int32_t main() {


//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);


    int T = 1;

//    cin >> T;

    while (T--) {
        solve();

    }

}
