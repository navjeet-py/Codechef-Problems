#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -2147483648
#define index(c) (((int) c) - 97)
//#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

void solve(){

    int N, M;
    bool even = false;

    cin >> N >> M;
    

    if (N % 2 == 0 || M % 2 == 0) even = true;
    if (even){
        int one = 0, two = 0;
        char c;
        range(i, 0, N){
            range(j, 0, M){
                cin >> c;
                if ((i + j) % 2 == 0){
                    if (c == '.') one++;
                    if (c == '*') two++;
                }else{
                    if (c == '.') two++;
                    if (c == '*') one++;
                }
            }
        }
        cout << min(one, two) << endl;
    }
    else{
        char c;
        int cnt = 0;
        range(i, 0, N){
            range(j, 0, M){
               cin >> c;
               if ((i + j) % 2 == 0){
                   if (c == '.') cnt++;
               } else {
                   if (c == '*') cnt++;
               }
            }
        }
        cout << cnt << endl;
    }

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