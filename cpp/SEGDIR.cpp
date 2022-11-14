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

bool intersect(pair<int, int> a, pair<int, int> b){
    if (b.first > a.second) return false;
    if (b.second < a.first) return false;
    return true;
}


bool possible(vector<pair<int, int>> v) {

    sort(v.begin(), v.end());
    int N = (int) v.size();
    int direction[N];
    range(i, 0, N) direction[i] = 0;
    direction[0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if (direction[i] == 0) direction[i] = 1;
            if(!intersect(v[i], v[j])) continue;
            if (direction[i] == 1) {
                if (direction[j] == 1) return false;
                else direction[j] = -1;
            }else if (direction[i] == -1){
                if (direction[j] == -1) return false;
                else direction[j] = 1;
            }
        }
    }
    return true;

}


void solve() {

    int N;
    cin >> N;

    map<int, vector<pair<int, int>>> mp;
    range(i, 0, N) {
        int l, r, v;
        cin >> l >> r >> v;
        if (mp.find(v) == mp.end()) {
            mp[v] = vector<pair<int, int>>();
        }
        mp[v].emplace_back(l, r);
    }

    for (const auto &it: mp) {
        if (possible(it.second)) {
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

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
