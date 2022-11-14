#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1e9 + 7
#define MIN_INT -2147483648

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

void dfs(vector<int> adj[], int cur, int par, array<int, 2> dp[], const int weights[]){
    dp[cur][0] = 0;
    dp[cur][1] = weights[cur];

    for (int nb: adj[cur]){
        if (nb == par) continue;
        dfs(adj, nb, cur, dp, weights);
        dp[cur][0] += max(dp[nb][0], dp[nb][1]);
        dp[cur][1] += dp[nb][0];
    }
}


void solve() {

    int N, a, b;
    cin >> N;
    int weights[N];
    range(i, 0, N) cin >> weights[i];
    vector<int> adj[N];
    range(i, 0, N - 1){
        cin >> a >> b;
        adj[a - 1].pb(b - 1);
        adj[b - 1].pb(a - 1);
    }

    array<int, 2> dp[N];
    dfs(adj, 0, 0, dp, weights);

    cout << max(dp[0][0], dp[0][1]) << endl;



}


int main() {



    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
