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

    int N, K, P, A, B;
    cin >> N >> K >> P;
    array<int, 2> pos[N];
    range(i, 0, N){
        cin >> pos[i][0];
        pos[i][1] = i;
    }
    sort(pos, pos + N);
    int dp[N];
    range(i, 0, N) dp[i] = -1;
    dp[pos[0][1]] = 0;
    range(i, 1, N){
        if (pos[i][0] - pos[i-1][0] <= K){
            dp[pos[i][1]] = dp[pos[i-1][1]];
        }else{
            dp[pos[i][1]] = dp[pos[i-1][1]] + 1;
        }
    }
    range(i, 0, P){
        cin >> A >> B;
        if (dp[A - 1] == dp[B - 1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}