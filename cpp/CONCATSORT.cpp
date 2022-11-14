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

int *A;
int *B;
int N;

bool is_possible(int k){
    int i = 0, j = 0;
    while(i < k && j < N){
        if (A[j] == B[i]){
            i++;
            if (i == k){
                return true;
            }
        }
        j++;
    }
    return false;
}




void solve() {



    cin >> N;
    A = new int[N];
    B = new int[N];
    range(i, 0, N){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B, B + N);
//    for(int k = 1; k <= N; k++){
//        cout << is_possible(k) << '\n';
//    }

    int ans = 0;
    int l = 1, r = N;
    while(l <= r){
        int mid = (l + r) / 2;

        if (is_possible(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    if (ans == N){
        cout << "YES\n";
        return;
    }

    int i = ans, j = 0;
    while(i < N && j < N){
        if (B[i] == A[j]){
            i++;
            if (i == N) {
                cout << "YES\n";
                return;
            }
        }
        j++;
    }
    cout << "NO\n";




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
