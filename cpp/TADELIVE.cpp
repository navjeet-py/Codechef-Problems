#include <iostream>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;
#define range(i, a, b) for(int i = a; i < b; i++)


int main() {

    int N, X, Y;
    cin >> N >> X >> Y;
    int A[N] , B[N];
    range(i, 0, N) {
        cin >> A[i];
    }
    range(i, 0, N) {
        cin >> B[i];
    }
    array<int, 3> diff[N];
    range(i, 0, N){
        diff[i][0] = abs(A[i] - B[i]);
        diff[i][1] = (A[i] > B[i]) ? 0 : 1;
        diff[i][2] = i;
    }
    sort(diff, diff+N);
    int answer = 0;
    for(int i = N - 1; i >= 0; i--){
        if (diff[i][1] == 0){
            if (X > 0){
                X--;
                answer += (A[diff[i][2]]);
            }else{
                Y--;
                answer += (B[diff[i][2]]);
            }
        }else{
            if (Y > 0){
                Y--;
                answer += (B[diff[i][2]]);
            }else{
                X--;
                answer += (A[diff[i][2]]);
            }
        }
    }
    cout << answer << endl;



    return 0;

}