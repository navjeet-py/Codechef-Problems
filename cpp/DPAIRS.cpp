#include <iostream>
#include "cmath"
#include<bits/stdc++.h>

using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)

void print_array(int arr[], int N) {
    range(i, 0, N) cout << arr[i] << ' ';
    cout << endl;
}


int main() {

    int N, M, a;
    cin >> N >> M;
    array<int, 2> A[N], B[M];
    range(i, 0, N) {
        cin >> a;
        A[i][0] = a;
        A[i][1] = i;
    }
    range(i, 0, M) {
        cin >> a;
        B[i][0] = a;
        B[i][1] = i;
    }
    sort(A, A + N);
    sort(B, B + M);
    range(i, 0, M){
        cout << A[0][1] << ' ' << B[i][1] << endl;
    }range(i, 1, N){
        cout << A[i][1] << ' ' << B[M - 1][1] << endl;
    }

    


    return 0;
}