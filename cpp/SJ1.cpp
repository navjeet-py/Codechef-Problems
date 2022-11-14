#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
//#define mod 1000000007
#define MIN_INT -21374836486346565
#define MAX_INT 21374836486346565
#define index(c) (((int) c) - 97)
#define int long long
#define in(a) int a; cin >> a;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int V[100000], M[100000], g[100000];

void dfs(vector<int> adj[], int cur, int par){
    if (cur != 0) g[cur] = gcd(g[par], V[cur]);

    for (int nb: adj[cur]){
        if (nb == par) continue;

        dfs(adj, nb, cur);
    }
}


void solve() {

    int N;
    cin >> N;
    if (N == 1){
        int v, m;
        cin >> v >> m;
        cout << m - gcd(v, m) << endl;
        return;
    }
    vector<int> adj[N];
    range(i, 0, N - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    range(i, 0, N) cin >> V[i];
    range(i, 0, N) cin >> M[i];
    g[0] = V[0];
    dfs(adj, 0, 0);
    range(node, 1, N){
        if (adj[node].size() != 1) continue;

        int p = gcd(g[node], M[node]);
        cout << M[node] - p << ' ';

    }
    cout << '\n';








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
