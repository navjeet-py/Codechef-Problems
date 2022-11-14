#include <iostream>

using namespace std;
#define range(i, a, b) for(i = a; i < b; i++)

int i, j, k, testcase;

void print_array(int array[], int n) {
    range(i, 0, n) cout << array[i] << ' ';
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    int array[N];
    range(i, 0, N) cin >> array[i];

    int forward[N + 1];
    forward[0] = 0;
    forward[1] = 0;
    forward[2] = array[1] - array[0];
    int mn = min(array[0], array[1]);
    range(i, 2, N) {
        forward[i + 1] = max(forward[i], array[i] - mn);
        mn = min(mn, array[i]);
    }
    int backward[N + 1];
    backward[0] = 0;
    backward[1] = 0;
    backward[2] = array[N - 1] - array[N - 2];
    int mx = max(array[N - 1], array[N - 2]);
    for (i = 3; i < N + 1; i++) {
        backward[i] = max(backward[i - 1], mx - array[N - i]);
        mx = max(mx, array[N - i]);
    }
    int backward_new[N + 1];
    range(i, 0, N + 1) backward_new[i] = backward[N - i];

    int final_mx = -9999999;
    range(i, 2, N - 1) {
        final_mx = max(final_mx, forward[i] + backward_new[i]);
    }
    cout << final_mx << endl;
    return 0;
}
