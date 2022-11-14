#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -2137483648
#define index(c) (((int) c) - 97)
//#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

void solve(){

    int N;
    cin >> N;
    int A[N];
    set<pair<int, int>> B;
    range(i, 0, N){
        cin >> A[i];
    }
    int a;
    range(i, 0, N){
        cin >> a;
        B.insert(make_pair(a, i));
    }
    int partner[N];
    int cnt = 0;
    range(i, 0, N) partner[i] = -1;
    range(i, 0, N){
        int p = A[i];
        auto it = B.lower_bound(make_pair(p, -1));
        if(it == B.begin()) continue;
        it--;
        partner[i] = (*it).second;
        B.erase(it);
        cnt++;
    }

    cout << cnt << endl;
    bool used[N];
    range(i, 0, N) used[i] = false;
    range(i, 0, N) if (partner[i] >= 0) used[partner[i]] = true;
    vector<int> left;
    range(i, 0, N) if (!used[i]) left.push_back(i);
    int it = 0;
    range(i, 0, N){
        if (partner[i] >= 0) cout << partner[i] + 1 << endl;
        else {
            cout << left[it] + 1 << endl;
            it++;
        }
    }



}

int32_t main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int T = 1;
//    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}