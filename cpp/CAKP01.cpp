#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
//#define mod 1000000007
#define MIN_INT -21374836486346565
#define MAX_INT 21374836486346565
#define index(c) (((int) c) - 65)
#define int long long
#define in(a) int a; cin >> a;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int no_of_digits(int N) {
    int cnt = 0;
    while (N > 0) N /= 10, cnt++;
    return cnt;
}

bool divisible_by_7(int A[], int n){
    int N = 0;
    int by = 1;
    range(i, 0, n) {
        N += (by * A[i]);
        by *= 10;
    }
    if (N % 7 == 0) return true;
    return false;
}


void solve() {


    int N;
    cin >> N;
    int n = no_of_digits(N);
    int digits[n];
    int i = 0;
    while (N > 0) digits[i++] = N % 10, N /= 10;
    sort(digits, digits + n);
    int cnt = 0;
    if (divisible_by_7(digits, n)) cnt++;
    while (next_permutation(digits, digits + n)){
        if (divisible_by_7(digits, n)) {
            cnt++;
//            print_array(digits, n);
        }
    }

    cout << cnt << endl;



}

int32_t main() {

//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("mooyomooyo.in", "r", stdin);
//    freopen("mooyomooyo.out", "w", stdout);

    int T = 1;

    cin >> T;


    while (T--) {
        solve();

    }

    return 0;
}
