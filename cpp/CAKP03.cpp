#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
//#define mod 1000000007
#define MIN_INT -21374836486346565
#define MAX_INT 21374836486346565
#define index(c) (((int) c) - 65)
#define int long long
#define in(a) int a; cin >> a;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}


void solve() {

    string S, T;
    cin >> T >> S;

    int in_search_of = 0;
    int idx = 0;
    while (idx < S.length() && in_search_of < T.length()){
        if (T[in_search_of] == S[idx]){
            in_search_of++; idx++;
        }
        else{
            idx++;
        }
    }

    if (in_search_of == T.length()) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }

}

int32_t main() {

//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("mooyomooyo.in", "r", stdin);
//    freopen("mooyomooyo.out", "w", stdout);

    int T = 1;

    cin >> T;



    while (T--) {
        solve();

    }

    return 0;
}
