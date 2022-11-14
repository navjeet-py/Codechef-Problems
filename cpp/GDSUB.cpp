#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define range(i, a, b) for(long long int i = a; i < b; i++)
typedef long long ll;

void print_array(long long int A[], long long int N){
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}
long long int mod = 1000000007;

int main(){

    long long int N, K, a, cnt;
    cin >> N >> K;
    map<int, int> mp;
    cnt = 0;
    range(i, 0, N){
        cin >> a;
        if (mp.find(a) == mp.end()) {
            mp[a] = 1;
            cnt++;
        }
        else mp[a]++;
    }
    long long int arr[cnt + 1];
    long long int idx = 1;
    for(auto p: mp){
        arr[idx] = p.first;
        idx ++;
    }
    K = min(K, cnt);
    long long int dp[K + 1][cnt + 1];
    range(i, 0, K + 1){
        dp[i][0] = 0;
    }

    range(j, 0, cnt + 1){
        dp[0][j] = 1;
    }
    range(i, 1, K + 1){
        range(j, 1, cnt + 1){
            dp[i][j] = (dp[i][j-1] + ((dp[i-1][j-1] * mp[arr[j]]) % mod)) % mod;
        }
    }
    long long int sm = 0;
    range(i,  0,K + 1){
        sm = (sm + dp[i][cnt]) % mod;
    }
    cout << sm << endl;


    return 0;
}