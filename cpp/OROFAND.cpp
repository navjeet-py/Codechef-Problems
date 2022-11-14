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


void solve() {

    int N, Q;
    cin >> N >> Q;
    int A[N];
    int value = 0;

    set<int> contribution[33];


    range(i, 0, N) {
        cin >> A[i];
        int a = A[i];
        value |= (a);


        int p = 1;
        range(idx, 0, 33) {
            if (p & a) contribution[idx].insert(i);
            p = (p << 1);
        }
    }

    cout << value << '\n';

    range(something, 0, Q) {
        int i, val;
        cin >> i >> val;
        i--;
        int p = 1;
        range(j, 0, 33) {
            bool to_erase = false, to_insert = false;
            if (contribution[j].find(i) != contribution[j].end()) to_erase = true;
            if (p & val) to_insert = true;
            if (to_erase == to_insert) {
                p = (p << 1);
                continue;
            } else {

                if (to_erase) {
                    contribution[j].erase(i);
                    if (contribution[j].empty()) value -= p;
                } else {
                    if (contribution[j].empty()) value += p;
                    contribution[j].insert(i);
                }
            }
            p = (p << 1);
//            cout << p << endl;
        }

        cout << value << '\n';
    }


}


int32_t main() {
//    cout << (1 << 3);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
