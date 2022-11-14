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

    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        ll A[N];
        range(i, 0, N) {
            cin >> A[i];
            A[i] %= N;
        }
        map<ll, int> mp;
        mp[0] = -1;
        ll last = 0, next;
        int idx1, idx2;
        range(i, 0, N){
            next = (last + A[i]) % N;
            last = next;
            if (mp.find(next) == mp.end()) mp[next] = i;
            else{
                idx1 = mp[next];
                idx2 = i;
                break;
            }
//            for(auto p : mp) cout << p.first << "->" << p.second << " | ";
//            cout << endl;
        }

        cout << idx2 - idx1 << endl;
        range(i, idx1 + 1, idx2 + 1){
            cout << i + 1 << ' ';
        }
        cout << endl;
    }


    return 0;
}