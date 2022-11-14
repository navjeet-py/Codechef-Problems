#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define el cout << '\n'
#define mod 1000000007
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

int nC2(int n){
    if (n < 2) return 0;
    else return (n * (n - 1)) / 2;
}

void solve() {

    int N;
    cin >> N;
    int A[N];
    range(i, 0, N){
        cin >> A[i];
    }

    int cnt= 0 ;
    int ans = 0;
    for(int i = 0; i < N; i++){
        if (A[i] == 0){
            ans += nC2(cnt);
            ans += cnt;
            cnt = 0;
        }else{
            cnt++;
        }
    }
    ans += nC2(cnt);
    ans += cnt;
    cout << ans << '\n';


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
