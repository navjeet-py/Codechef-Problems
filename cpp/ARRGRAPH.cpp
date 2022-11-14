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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

void dfs(vector<int>adj[], int cur, bool visited[]){
    visited[cur] = true;
    for(int nb: adj[cur]){
        if (!visited[nb])
            dfs(adj, nb, visited);
    }
}

int A[50];

void solve() {

    int N;
    cin >> N;
    range(i, 0, N) cin >> A[i];
    vector<int> adj[N];
    range(i, 0, N) {
        range(j, i, N) {
            if (gcd(A[i], A[j]) == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    bool visited[N];
    range(i, 0, N) visited[i] = false;
    dfs(adj, 0, visited);
    range(i, 0, N){
        if(!visited[i]){
            cout << 1 << endl;
            bool is47 = false;
            range(pp, 0, N) if (A[pp] == 47) is47 = true;
            if (!is47){
                A[0] = 47;
            }else{
                A[0] = 43;
            }
            print_array(A, N);
            return;
        }
    }
    cout << 0 << endl;
    print_array(A, N);


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