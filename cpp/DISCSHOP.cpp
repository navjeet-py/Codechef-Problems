#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

int get_number(vector<int> v, int idx){
    int number = 0;
    int ten = 1;
    for(int i = 0; i < v.size(); i++){
        if (i == idx) continue;
        number += (ten * v[i]);
        ten *= 10;
    }
    return number;
}



void solve() {



    int N;
    cin >> N;
    vector<int> v;
    while(N > 0){
        v.push_back(N % 10);
        N /= 10;
    }
    int mn = get_number(v, 0);
    for(int i = 1; i < v.size(); i++){
        mn = min(mn, get_number(v, i));
    }
    cout << mn << '\n';




}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
