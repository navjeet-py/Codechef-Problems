#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int main() {
    int N, Q, L, R, C;
    cin >> N;
    int rows[N], diff_columns[N];
    range(i, 0, N) diff_columns[i] = 0;
    array<int, 2> data[N];

    range(i, 0, N) {
        cin >> L >> R;
        L--;
        R--;
        rows[i] = R - L + 1;
        data[i][0] = L;
        data[i][1] = R;
        if (L >= 0) diff_columns[L]++;
        if (R < N - 1) diff_columns[R + 1]--;
    }
    int columns[N];
    columns[0] = diff_columns[0];
    range(i, 1, N) columns[i] = columns[i - 1] + diff_columns[i];
    ll total = 0;
    range(i, 0, N) total += (ll) rows[i];
    cin >> Q;
    range(q, 0, Q) {
        cin >> R >> C;
        R--;
        C--;
        ll sm = total - (ll) (columns[C] + rows[R]);
        if (data[R][1] >= C && data[R][0] <= C) sm++;
        if (sm % 2 == 0) cout << 'E' << endl;
        else cout << 'O' << endl;
    }


    return 0;
}