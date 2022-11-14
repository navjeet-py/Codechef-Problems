#include <iostream>
#include "cmath"
#include<bits/stdc++.h>

using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)

void print_array(int arr[], int N) {
    range(i, 0, N) cout << arr[i] << ' ';
    cout << endl;
}


int main() {

    int T, N, M, K, r, c;
    cin >> T;
    while(T--){
        cin >> N >> M >> K;
        int ans = 0;
        set<pair<int, int>> plants;
        int a[] = {-1, 0, 1};
        range(i, 0, K) {
            cin >> r >> c;
            ans += 4;
            plants.insert(make_pair(r, c));
            for(auto x : a){
                for(auto y : a){
                    if (x == 0 ^ y == 0){
                        if (plants.find(make_pair(r+x, c+y)) != plants.end()){
                            ans -= 2;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}