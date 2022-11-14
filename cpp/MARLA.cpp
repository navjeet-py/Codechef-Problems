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

void dfs(vector<int> adj[], int cur, int connected[], int cc){
    connected[cur] = cc;
    for(int nb: adj[cur]){
        if (connected[nb] == -1){
            dfs(adj, nb, connected, cc);
        }
    }
}



void solve(){

    int N, M;
    cin >> N >> M;
    int grid[N][M];
    vector<int> adj[N * M];
    int a, b;
    range(i, 0, N)
        range(j, 0, M){
            cin >> grid[i][j];
            if (i > 0 && grid[i - 1][j] == grid[i][j]){
                a = M * i + j, b = M * (i - 1) + j;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            if (j > 0 && grid[i][j - 1] == grid[i][j]){
                a = M * i + j, b = M * i + j - 1;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
    }


    int connected[N * M];
    range(i, 0, N * M) connected[i] = -1;
    int cc = 0;
    range(i, 0, N * M){
        if (connected[i] == -1)
            dfs(adj, i, connected, ++cc);
    }

    map<int, pair<int, int>> mp;

    range(i, 0, N * M){
        if (mp.find(connected[i]) == mp.end()){
            a = i / M;
            b = i % M;
            mp[connected[i]] = make_pair(1, grid[a][b]);
        }else{
            mp[connected[i]].first++;
        }
    }

    int mx = 0;
    for(auto it: mp){
        mx = max(mx, it.second.first);
    }
    int least = 99999999999;
    for (auto it: mp){
        if (it.second.first == mx){
            least = min(least, it.second.second);
        }
    }

    cout << least << ' ' << mx ;






}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
//    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}