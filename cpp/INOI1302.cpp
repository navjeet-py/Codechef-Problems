#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -99999999496346565
#define MAX_INT 99999999496346565
#define index(c) (((int) c) - 97)
#define int long long
#define in(a) int a; cin >> a;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

void dfs(vector<int> adj[], int cur, bool visited[]) {
    visited[cur] = true;
    for (int nb: adj[cur]) {
        if (!visited[nb]) {
            dfs(adj, nb, visited);
        }
    }
}


void solve() {

    int N, K;
    cin >> N >> K;
    set<int> ids[N];
    range(i, 0, N) {
        int cnt;
        cin >> cnt;
        range(p, 0, cnt) {
            int a;
            cin >> a;
            ids[i].insert(a);
        }
    }
    vector<int> adj[N];
    range(i, 0, N) {
        range(j, i + 1, N) {
            int cnt = 0;
            for (int p: ids[i]) if (ids[j].find(p) != ids[j].end()) cnt++;
            if (cnt >= K) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    bool visited[N];
    for (bool &a: visited) a = false;
    dfs(adj, 0, visited);
    int cnt = 0;
    for(bool a: visited) cnt += a;
    cout << cnt << endl;

}

int32_t main() {


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);


    int T = 1;


//    cin >> T;


    while (T--) {
        solve();

    }

    return 0;
}
