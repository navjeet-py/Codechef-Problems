#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N){
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int main(){

    int T, N, K, val;
    cin >> T;
    while(T--){
        cin >> N >> K;
        int A[N];
        range(i, 0, N) cin >> A[i];
        int mn = abs(A[1] + A[0] - K);
        int cnt = 0;
        range(i, 0, N){
            range(j, i + 1, N){
                val = abs(A[j] + A[i] - K);
                if (mn == val) cnt++;
                else if (mn > val) {
                    mn = val;
                    cnt = 1;
                }
            }
        }
        cout << mn << ' ' << cnt << endl;
    }

    return 0;
}