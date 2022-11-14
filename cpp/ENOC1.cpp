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
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}
int temp, maxN;
static int LCAtable[100001][18];
static int level[100001];
static int X[100001];
static int A[100001];

void dfs(vector<int> adj[], int cur, int par) {
    LCAtable[cur][0] = par;

    for (int nb: adj[cur]) {
        if (nb != par) {
            level[nb] = level[cur] + 1;
            X[nb] = X[cur] ^ A[nb];
            dfs(adj, nb, cur);
        }
    }
}

void prepareLCA(vector<int> adj[], int N) {
    level[0] = 0;
    dfs(adj, 0, -1);
    range(j, 1, maxN + 1) {
        range(i, 0, N) {
            if (LCAtable[i][j - 1] != -1) {
                LCAtable[i][j] = LCAtable[LCAtable[i][j - 1]][j - 1];
            }
        }
    }
}

int LCA(int a, int b){

    if (level[a] > level[b]) temp = a, a = b, b = temp;
    int d = level[b] - level[a];
    while (d > 0){
        int i = (int) log2(d);
        b = LCAtable[b][i];
        d -= (1 << i);
    }
    if (a == b) return a;
    for(int i = maxN; i >= 0; i--){
        if (LCAtable[a][i] != -1 && LCAtable[a][i] != LCAtable[b][i]){
            a = LCAtable[a][i], b = LCAtable[b][i];
        }
    }
    return LCAtable[a][0];
}

int distance(int a, int b){
    int l = LCA(a, b);
    return -level[l] * 2 + level[a] + level[b];
}

void solve() {

    int N, Q;
    cin >> N >> Q;
    range(i, 0, N) cin >> A[i];
    vector<int> adj[N];
    int a, b;
    range(i, 0, N - 1) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maxN = (int) log2(N) + 1;
    range(i, 0, N) {
        range(j, 0, maxN + 1) {
            LCAtable[i][j] = -1;
        }
    }
    X[0] = A[0];
    prepareLCA(adj, N);
    range(q, 0, Q){
        cin >> a >> b;
        a--; b--;
        cout << ((X[a] ^ X[b]) ^ A[LCA(a, b)]) << endl;
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