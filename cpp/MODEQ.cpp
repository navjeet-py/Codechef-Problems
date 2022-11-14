#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

void print_array(int A[], int N) {
    range(idx, 0, N) cout << A[idx] << ' ';
    cout << '\n';
}

static int *modulo;

int N, M;
int answer;

void solve() {
    cin >> N >> M;
    modulo = new int[N + 1];
    range(i, 0, N + 1) modulo[i] = 1;
    answer = 0;
    range(i, 2, N + 1) {
        answer += modulo[M % i];
        int j = M % i;
        while (j < N + 1) {
            modulo[j]++;
            j += i;
        }
    }
    cout << answer << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
