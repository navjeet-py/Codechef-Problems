#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
//#define mod 1000000007
#define MIN_INT -2137483648
#define index(c) (((int) c) - 97)
#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

static int pow2[150001];

void precalculate(int mod) {
    pow2[0] = 1;
    range(i, 1, 150001) {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }
}

void solve(int N, int mod) {

    precalculate(mod);
    vector<int> factors;
    range(i, 2, N + 1) {
        if (N % i == 0)factors.push_back(i);
    }


    map<int, int> mp;
    mp[1] = 2;
    for (int factor: factors) {
        int ans = pow2[factor];
        for(auto it: mp){
            if (factor % it.first == 0){
                ans -= it.second;
                ans %= mod;
            }
        }
        ans %= mod;
        while (ans < 0) ans += mod;
        mp[factor] = ans;
    }
//    for(auto it:mp) cout << it.first << ' ' << it.second << endl;
    cout << mp[N] << endl;
}

int32_t main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int T = 1;
//    cin >> T;

    while (T--) {
        int mod = 0;
        int N = 0;
        cin >> N >> mod;
        solve(N, mod);
    }

    return 0;
}