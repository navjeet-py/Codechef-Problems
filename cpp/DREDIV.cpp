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
set<int> powers_of_2;

bool isPower(int P){
    if (powers_of_2.find(P) == powers_of_2.end()) return false;
    return true;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

void solve() {




    int N, K;
    cin >> N >> K;

    vector<int> A;
    bool allPowers = true;
    int notDiv = 0;
    range(i, 0, N){
        int a;
        cin >> a;
        a = K / gcd(a, K);
        if (a == 1) continue;
        else {
            notDiv++;
            if (!isPower(a)) allPowers = false;
        }
    }
    if (isPower(K)) cout << "YES" << endl;
    else if (notDiv == 0) cout << "YES" << endl;
    else if (allPowers) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int32_t main() {
    int pp = 1;
    range(i, 0, 40){
        powers_of_2.insert(pp);
        pp *= 2;
    }

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
