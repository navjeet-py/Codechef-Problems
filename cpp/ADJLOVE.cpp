#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N){
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}





void solve(){

    int N;
    cin >> N;
    int odd = 0, even = 0;
    int A[N];
    range(i, 0, N){
        cin >> A[i];
        if (A[i] % 2 == 0) {


            even++;
        }
        else odd++;

    }

    if (odd <= 1) {
        cout << -1 << '\n';
        return;
    }
    if (even == 0 && N % 2 == 1){
        cout << -1 << '\n';
        return;
    }

    if (even == 0 && N % 2 == 0){
        print_array(A, N);
        return;
    }
    int X[N - 3];


    int idx = 0;
    int x = -1, y = -1, z = -1;
    for (int a: A){
        if (a % 2 == 0){
            if (z == -1) z = a;
            else X[idx++] = a;
        }else{
            if (x == -1) x = a;
            else if (y == -1) y = a;
            else X[idx++] = a;
        }
    }

//    print_array(X, N - 3);

    if (N == 3){
        cout << x << ' ' << y << ' ' << z << '\n';
        return;
    }
    int already = 0;
    for (int i = 0; i < N - 4; i++){
        already += (X[i] * X[i + 1]);
        already %= 2;
    }

    bool lastEven = true;
    if (N >= 4 && X[N-4] % 2 == 1) lastEven = false;

    for (int a: X) cout << a << ' ';

    if (already == 0) {
        cout << z << ' ' << x << ' ' << y << '\n';
        return;
    }

    if (lastEven){
        cout << x << ' ' << z << ' ' << y << '\n';
        return;
    }

    cout << x << ' ' << y << ' ' << z << '\n';

}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    cin >> T;

    while(T--){
        solve();
    }


    return 0;
}