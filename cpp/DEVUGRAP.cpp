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

    ll T, N, K, price, rem;
    cin >> T;
    while(T--){
        cin >> N >> K;
        ll answer = 0;
        range(i, 0, N){
            cin >> price;
            rem = price % K;
            if (rem == price){
                answer += (K - rem);
            }else{
                answer += min(rem, K - rem);
            }
        }
        cout << answer << endl;
    }


    return 0;
}