#include <iostream>
#include <cmath>
#include "unordered_map"
#include <vector>


using namespace std;
#define range(i, a, b) for(int i = a; i < b; i++)


int main() {

    bool isPrime[1000001];
    for (bool &i : isPrime) i = true;
    isPrime[0] = false;
    isPrime[1] = false;
    range(i, 2, 1010) {
        for (int j = i * i; j < 1000001; j += i) {
            isPrime[j] = false;
        }
    }
    vector<int> primes;
    range(i, 2, 1000001) {
        if (isPrime[i]) primes.push_back(i);
    }
    int P = primes.size();

    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        int arr[N];
        range(i, 0, N) cin >> arr[i];
        unordered_map<int, int> mp;
        for (int K:arr) {
            int idx = 0;
            while (K > 1) {
                int p = primes[idx];
                if (K % p == 0) {
                    if (mp.find(p) == mp.end()) {
                        mp[p] = 1;
                    } else {
                        mp[p]++;
                    }
                    K /= p;
                } else {
                    idx++;
                }
            }
        }
        int ans = 1;
        for (auto k:mp) {
            ans *= (k.second + 1);
        }
        cout << ans << endl;
    }

    return 0;

}