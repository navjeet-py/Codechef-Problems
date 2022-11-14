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

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}




void solve() {

    int N;
    cin >> N;
    int indexes[N];
    range(i, 0, N){
        string S;
        cin >> S;
        range(j, 0, N){
            if (S[j] == '1'){
                indexes[i] = j;
                break;
            }
        }
    }

    int total = 0;
    range(i, 0, N){
        int mx = indexes[i], mn = indexes[i];
        int sm = 1;
        range(j, i + 1, N){
            mx = max(mx, indexes[j]);
            mn = min(mn, indexes[j]);
            if (mx - mn == j - i) sm++;
        }
        total += sm;
    }
    cout << total << endl;



}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("mooyomooyo.in", "r", stdin);
//    freopen("mooyomooyo.out", "w", stdout);

    int T = 1;

    cin >> T;


    while (T--) {
        solve();

    }

    return 0;
}
