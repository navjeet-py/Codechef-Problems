#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -2147483648
#define index(c) (((int) c) - 97)
#define int long long

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int find_distance(int a, int b){
    int cnt = 0;
    while (a != b){
        if (a > b) a /= 2;
        else b /= 2;
        cnt++;
    }
    return cnt;
}
bool color(int a){
    int p = (int) log2(a);
    return (p % 2 == 0);
}




void solve(){

    int Q;
    cin >> Q;
    string q;
    int M, N;
    bool inverted = false;
    range(i, 0, Q){
        cin >> q;
        if (q == "Qi") inverted = !inverted;
        else{
            cin >> M >> N;
            int nodes = find_distance(M, N) + 1;
            if (nodes % 2 == 0){
                cout << nodes / 2 << ' ';
            }else{
                // true -> black
                bool leader = color(M);
                if (inverted) leader = !leader;
                if (q == "Qb"){
                    if (leader) cout << nodes / 2 + 1 << ' ';
                    else cout << nodes / 2 << ' ';
                }else{
                    if (leader) cout << nodes / 2 << ' ';
                    else cout << nodes / 2 + 1 << ' ';
                }
            }
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