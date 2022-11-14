#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
//#define mod 1000000007
#define MIN_INT -21374836486346565
#define index(c) (((int) c) - 65)
#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

static int subtree[1000000], dp[1000000];
int distance_from_root = 0;

void subtree_dfs(vector<int> adj[], int cur, int par, int dis){
    distance_from_root += dis;
    int number = 0;
    for(int nb: adj[cur]){
        if (nb == par) continue;

        subtree_dfs(adj, nb, cur, dis + 1);

        number += subtree[nb];
    }

    subtree[cur] = number + 1;
}

void final(vector<int> adj[], int cur, int par, int N){
    if (cur != 0) dp[cur] = N - 2 * subtree[cur] + dp[par];

    for(int nb: adj[cur]){
        if (nb == par) continue;

        final(adj, nb, cur, N);
    }
}






void solve() {


    int N;
    cin >> N;
    vector<int> adj[N];
    int a, b;
    range(i, 0 ,N - 1){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    subtree_dfs(adj, 0, 0, 0);
    dp[0] = distance_from_root;
    final(adj, 0, 0, N);
    print_array(dp, N);





}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("mooyomooyo.in", "r", stdin);
//    freopen("mooyomooyo.out", "w", stdout);

    int T = 1;

//    cin >> T;


    while (T--) {
        solve();

    }

    return 0;
}
