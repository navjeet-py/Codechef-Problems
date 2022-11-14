#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
//#define vi vector<int>
#define mod 1000000007
#define mod2 100000000
#define MIN_INT -99999999496346565
#define MAX_INT 99999999496346565
#define index(c) (((int) c) - 97)
#define int long long
#define ask(j) cout << "? " << j << '\n'; cin >> A[j];
#define ans(i) cout <<"! " << i << endl; cout.flush(); return;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}
int temp, maxN;
static int LCAtable[100001][18];
static int level[100001];
static int sm[100001];


void dfs(vector<pair<int, int>> adj[], int cur, int par) {
    LCAtable[cur][0] = par;

    for (pair<int, int> nb: adj[cur]) {
        if (nb.first != par) {
            level[nb.first] = level[cur] + 1;
            sm[nb.first] = sm[cur] + nb.second;
            dfs(adj, nb.first, cur);
        }
    }
}

void prepareLCA(vector<pair<int, int>> adj[], int N, int root) {
    level[0] = 0;
    sm[root] = 0;
    dfs(adj, root, -1);
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

    int N, Q, R;
    cin >> N >> Q >> R;
    vector<pair<int, int>> adj[N];
    int a, b, w;
    range(i, 0, N - 1) {
        cin >> a >> b >> w;
        a--; b--;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    maxN = (int) log2(N) + 1;
    range(i, 0, N) {
        range(j, 0, maxN + 1) {
            LCAtable[i][j] = -1;
        }
    }
    prepareLCA(adj, N, R);
    range(q, 0, Q){
        cin >> a >> b;
        a--; b--;
        int l = LCA(a, b);
        cout << sm[a] + sm[b] - 2 * sm[l] << '\n';
    }


}


int32_t main() {

   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);

    int T = 1;

    cin >> T;


    while (T--) {
        solve();

    }

}
