#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
#define range(i, a, b) for(i = a; i < b; i++)
int i, j;
int mod = 1000000007;

void print_int_array(long long int array[], int n) {
    for (int pqr = 0; pqr < n; pqr++) cout << array[pqr] << ' ';
    cout << endl;
}

void print_bool_array(bool array[], int n) {
    for (int pqr = 0; pqr < n; pqr++) cout << array[pqr] << ' ';
    cout << endl;
}

int main() {

    int T, N, X;
    cin >> T;
    while(T--){
        cin >> X >> N;
        int numbers[N];
        range(i, 0, N) cin >> numbers[i];
        int final = 0;
        range(i, 0, N){
            int cnt = 0;
            int pro = 1;
            j = i;
            while(pro < X && j < N){
                pro *= numbers[j];
                if (pro < X){
                    cnt++;
                    j++;
                }else{
                    j = N + 2;
                }
            }
            final += cnt;
        }
        cout << final << endl;
    }





    return 0;
}