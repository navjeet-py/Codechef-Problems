#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
//#define vi vector<int>
#define mod 1000000007
#define mod2 100000000
#define MIN_INT -99999999496346565
#define MAX_INT 99999999496346565
#define index(c) (((int) c) - 97)
#define int long long
#define ask(j) cout << "? " << j << '\n'; cin >> A[j];
#define ans(i) cout <<"! " << i << endl; cout.flush(); return;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}






void solve(){

    int M, H;
    cin >> M >> H;
    int bmi = M / (H * H);
    if (bmi <= 18){
        cout << "1\n";
        return;
    }
    if (bmi <= 24){
        cout << "2\n";
        return;
    }
    if (bmi <= 29){
        cout << "3\n";
        return;
    }
    else {
        cout << "4\n";
        return;
    }








}


int32_t main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);

    int T = 1;

    cin >> T;


    while (T--) {
        solve();

    }

}
