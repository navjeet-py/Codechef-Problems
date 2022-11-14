#include <iostream>
#include <bits/stdc++.h>
#include <random>
using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}


int main() {

    int T, N, M;
    cin >> T;
    while(T--){
        cin >> N >> M;
        int A[N];
        range(i, 0, N) cin >> A[i];
        int freq[M + 1];
        range(i, 1, M + 1) freq[i] = 0;
        range(i, 0, N)
            if (A[i] <= M){
                freq[A[i]]++;
            }
        bool isPoss = true;
        range(i, 1, M) {
            if (freq[i] == 0){
                isPoss = false;
                break;
            }
        }
        if (!isPoss) cout << -1 << endl;
        else cout << N - freq[M] << endl;

    }

    return 0;
}