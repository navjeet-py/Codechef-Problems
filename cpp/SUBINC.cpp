#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N){
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

ll increasing_subarrays(int A[], int N){
    int dp[N];
    dp[0] = 1;
    range(i, 1, N){
        if (A[i] >= A[i-1]){
            dp[i] = dp[i-1] + 1;
        }else{
            dp[i] = 1;
        }
    }
    ll sm = 0;
    range(i, 0, N) sm += (ll)dp[i];
    return sm;
}



int main(){
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        int A[N];
        range(i, 0, N) cin >> A[i];
        cout << increasing_subarrays(A, N) << endl;
    }



    return 0;
}