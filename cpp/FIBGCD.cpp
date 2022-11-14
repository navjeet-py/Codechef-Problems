#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -21374836486346565
#define MAX_INT 21374836486346565
#define index(c) (((int) c) - 97)
#define int long long
#define in(a) int a; cin >> a;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int fib[1000001];

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    cout << fib[g - 1] << endl;



}

int32_t main() {


    fib[0] = fib[1] = 1;
    range(i, 2, 1000001) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
// 1 1 2 3 5

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);


    int T = 1;

    cin >> T;


    while (T--) {
        solve();

    }

    return 0;
}
