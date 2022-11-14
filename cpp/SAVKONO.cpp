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

    int T, N, Z, a;
    cin >> T;
    while(T--){
        cin >> N >> Z;
        multiset<int> powers;
        range(i, 0, N) {
            cin >> a;
            powers.insert(a);
        }
        int cnt = 0;
        while (Z > 0){
            auto it = powers.end();
            it--;
            int value = *it;
            if (value > 0){
                powers.erase(it);
                Z -= value;
                value /= 2;
                powers.insert(value);
                cnt++;
            }else {
                break;
            }

        }
        if (Z <= 0) cout << cnt << endl;
        else cout << "Evacuate" << endl;
    }

    return 0;
}