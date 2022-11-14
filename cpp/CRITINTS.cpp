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

void dfs(vector<int> adj[], int root, int deleted, bool visited[]){
    visited[root] = true;
    for (int nb: adj[root]){
        if (nb == deleted || visited[nb]) continue;

        dfs(adj, nb, deleted, visited);
    }
}





void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> adj[N];
    int a, b;
    range(i, 0, M){
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    vi p;
    range(deleted_node, 0, N){
        int root;
        if (deleted_node == 1) root = 0;
        else root = 1;

        bool visited[N];
        range(i, 0, N) visited[i] = false;
        dfs(adj, root, deleted_node, visited);
        int cnt = 0;
        range(i, 0, N){
            if (visited[i]) cnt++;
        }
        if (cnt != N - 1) p.push_back(deleted_node);
    }
    cout << p.size() << endl;
    range(i, 0, p.size()){
        cout << p[i] + 1 << endl;
    }

}


int main() {

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
