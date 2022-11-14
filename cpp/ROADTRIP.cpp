#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
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

void dfs(vector<int> adj[], int cur, int connected[], int cc){
    for(int nb: adj[cur]){
        if (connected[nb] == -1) {
            connected[nb] = cc;
            dfs(adj, nb, connected, cc);
        }
    }
}


void solve() {

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> adj[N];
    range(i, 0, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int museums[N];
    range(i, 0, N) cin >> museums[i];

    int connected[N];
    range(i, 0, N) connected[i] = -1;
    int cc = 0;
    range(i, 0, N){
        if (connected[i] == -1){
            connected[i] = cc;
            dfs(adj, i, connected, cc++);
        }
    }
    int mp[cc];
    range(i, 0, cc) mp[i] = 0;
    range(i, 0, N){
        mp[connected[i]] += museums[i];
    }
    sort(mp, mp + cc);

    if (K > cc){
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    int i = 0, j = cc - 1;
    int cnt = 0;
    while (K--){
        if ((cnt++) % 2 == 0){
            ans += mp[j--];
        }else{
            ans += mp[i++];
        }
    }
    cout << ans << endl;





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

    return 0;
}
