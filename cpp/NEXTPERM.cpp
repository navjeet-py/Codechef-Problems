#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long rem(long long base, long long power, long long mod){
	if (power == 0) return 1;
	else if (power == 1) return base % mod;
	else{
        if (power % 2 == 0){
            long long int k = rem(base, power / 2, mod);
            return (k * k) % mod;
        }else{
            long long int k = rem(base, power / 2, mod);
            return (k * k * base) % mod;
        }
	}
}




int main() {
    int N, K;
    cin >> N >>K;
    while (K--){
        int A[N];
        for(int i = 0; i < N; i++) cin >> A[i];
        next_permutation(A, A + N);
        for(int i = 0; i < N; i++) cout << A[i] << ' ';
        cout << endl;
    }
	return 0;
}

