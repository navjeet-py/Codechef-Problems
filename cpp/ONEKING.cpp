#include <iostream>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;
#define range(i, a, b) for(int  i = a; i < b; i++)


int main() {

    int T, N, l, r;
    cin >> T;
    while (T--) {
        cin >> N;
        array<int, 2> kingdoms[N];
        range(i, 0, N) {
            cin >> l >> r;
            kingdoms[i][0] = r;
            kingdoms[i][1] = l;
        }
        sort(kingdoms, kingdoms + N);
        int last = kingdoms[0][0];
        int bombs = 1;
        range(i, 1, N) {
            if (kingdoms[i][1] > last) {
                bombs++;
                last = kingdoms[i][0];
            }
        }
        cout << bombs << endl;
    }

    return 0;

}
