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

void dfs(set<int> adj[], int cur, bool visited[]){
    visited[cur] = true;
    for(auto nb: adj[cur]){
        if (!visited[nb]) {
            dfs(adj, nb, visited);
        }
    }
}


void solve(){

    string S, T;
    cin >> S >> T;
    int M;
    cin >> M;
    set<int> adj[26];
    char a, b, r;
    range(i, 0, M){
        cin >> a;
        cin >> r; cin >> r; cin >> b;
        adj[index(a)].insert(index(b));
    }

    if (S.length() != T.length()) {
        cout << "NO" << endl;
        return;
    }

    bool canReach[26][26];
    range(i, 0, 26) range(j, 0, 26) canReach[i][j] = false;
    range(from, 0, 26){
        bool visited[26];
        range(i, 0, 26) visited[i] = false;
        dfs(adj, from, visited);
        range(j, 0, 26) {
            canReach[from][j] = visited[j];
        }
    }
    range(i, 0, S.length()){
        if (!canReach[index(S[i])][index(T[i])]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;








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