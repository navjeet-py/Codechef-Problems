#include <iostream>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;
#define range(i, a, b) for(long long int  i = a; i < b; i++)

long long int C2(long long int p){
    if (p <= 1) return 0;
    return (p*(p - 1)) / 2;
}

int main() {

    long long int T, N, K, a;
    cin >> T;
    while (T--){
        cin >> N >> K;
        map<long long int, long long int> mp;
        range(i, 0, N) {
            cin >> a;
            if (mp.find(a) == mp.end()) mp[a] = 1;
            else mp[a]++;
        }
        multiset<int> cnts;
        long long int mx = 0;
        for(auto it:mp){
            cnts.insert(it.second);
            mx += (it.second - 1);
        }
        long long int answer = C2(N);
        if (K >= mx){
            cout << answer << endl;
        }else{
            range(i, 0, K){
                auto it = cnts.end();
                it--;
                long long int val = *it;
                cnts.erase(it);
                cnts.insert(val - 1);
            }
            for(auto p : cnts){
                answer -= C2(p);
            }
            cout << answer << endl;


        }
    }

    return 0;

}