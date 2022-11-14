#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

int minimum(int a, int b, int c){
    return min(min(a, b), c);
}
int maximum(int a, int b, int c){
    return max(a, max(b, c));
}
int middle(int a, int b, int c){
    return a + b + c - maximum(a, b, c) - minimum(a, b, c);
}


void solve(){

    int N;
    cin >> N;
    int A[N + 1];
    range(i, 0, N + 1)cin >> A[i];

    int sm = A[0];

    int pow = 1;
    vector<int> ones;
    while(pow <= N){
        int zero;
        int diff = (A[pow] - sm) / pow;
        if (diff == 3) zero = 3;
        if (diff == 1) zero = 2;
        if (diff == -1) zero = 1;
        if (diff == -3) zero = 0;
        ones.push_back(3 - zero);
        pow*=2;
    }


    int a = 0, b = 0, c = 0;
    for(int i = (int)ones.size() - 1; i >= 0; i--){
        int x = minimum(a, b, c);
        int y = middle(a, b, c);
        int z = maximum(a, b, c);

        pow /= 2;

        int cnt = ones[i];
        if (cnt == 0) continue;
        if (cnt == 1){
            if (a == x) a += pow;
            else if (b == x) b += pow;
            else if (c == x) c += pow;
        }
        if (cnt == 2){
            if (a == z) b += pow, c += pow;
            else if (b == z) a += pow, c += pow;
            else if (c == z) a += pow, b += pow;
        }
        if (cnt == 3){
            a += pow, b += pow, c += pow;
        }
    }

    cout << a << ' ' << b << ' ' << c << '\n';





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
