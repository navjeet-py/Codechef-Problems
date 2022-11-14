#include <iostream>
#include <cmath>
#include "unordered_map"
#include <vector>


using namespace std;
#define range(i, a, b) for(int i = a; i < b; i++)


int main() {

    int T, N, a;
    cin >> T;
    while (T--) {
        cin >> N;
        int sm = 0, zeroes = 0;
        range(i, 0, N) {
            cin >> a;
            sm += a;
            if (a == 0) zeroes++;
        }
        N = N - zeroes;
        if (sm < 100) {
            cout << "NO" << endl;
        } else if (abs(sm - 100) <= N - 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }
    return 0;

}