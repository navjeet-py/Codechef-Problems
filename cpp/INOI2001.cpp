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

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

map<int, int> mn, mx, size;

void dfs(vector<int> adj[], int cur, bool visited[], int cc){
    visited[cur] = true;

    for(int nb: adj[cur]){
        if (visited[nb]) continue;

        mn[cc] = min(mn[cc], nb);
        mx[cc] = max(mx[cc], nb);
        size[cc] += 1;
        dfs(adj, nb, visited, cc);
    }
}



void solve() {
    mn.clear(), mx.clear(), size.clear();

    int N, M;
    cin >> N >> M;
    vector<int> adj[N];
    int a, b;
    range(i, 0, M){
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    int cc = 0;
    bool visited[N];
    range(i, 0, N) visited[i] = false;
    range(i, 0, N){
        if (visited[i]) continue;
        visited[i] = true;
        cc++;
        mx[cc] = mn[cc] = i;
        size[cc] = 1;
        dfs(adj, i, visited, cc);
    }


    int even = 0, odd = 0;
    range(i, 0, N) visited[i] = false;

    for (auto it: size){
        int root = (it.second % 2 == 0) ? mn[it.first] : mx[it.first];
        int sm = 1;
        queue<int> q;
        q.push(root);
        visited[root] = true;
        int level = 2;
        while (!q.empty()){
            int s = q.size();
            range(i, 0, s){
                int cur = q.front();
                q.pop();
                for(int nb: adj[cur]){
                    if (!visited[nb]){
                        visited[nb] = true;
                        sm += level;
                        q.push(nb);
                    }
                }
            }
            level++;
//            cout << level << ' ' << sm << endl;
        }

        if (it.second % 2 == 0) even += sm;
        else odd += sm;
//        cout << it.first << ' ' << even << ' ' << odd << endl;
    }
    cout << even << ' ' << odd << endl;
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