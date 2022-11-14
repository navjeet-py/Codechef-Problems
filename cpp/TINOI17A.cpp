#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define mod2 100000000
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


int ans = 0;
int R, C;

map<pair<int, int>, bool> visited;
set<pair<int, int> > cultivated;

void dfs(pair<int, int> p) {
//    cout << p.first << ' ' << p.second << " -> " << ans << endl;
    visited[p] = true;
    int x = p.first, y = p.second;
    ans += 4;

    if (x > 1) {
        pair<int, int> q = {x - 1, y};
        if (cultivated.find(q) != cultivated.end())
            if (visited[q]) ans -= 2;
    }
    if (x < R) {
        pair<int, int> q = {x + 1, y};
        if (cultivated.find(q) != cultivated.end())
            if (visited[q]) ans -= 2;
    }
    if (y > 1) {
        pair<int, int> q = {x, y - 1};
        if (cultivated.find(q) != cultivated.end())
            if (visited[q]) ans -= 2;
    }
    if (y < C) {
        pair<int, int> q = {x, y + 1};
        if (cultivated.find(q) != cultivated.end())
            if (visited[q]) ans -= 2;

    }


    if (x > 1) {
        pair<int, int> q = {x - 1, y};
        if (cultivated.find(q) != cultivated.end()) {
            if (!visited[q]) dfs(q);
        }
    }
    if (x < R) {
        pair<int, int> q = {x + 1, y};
        if (cultivated.find(q) != cultivated.end()) {
            if (!visited[q]) dfs(q);
        }
    }
    if (y > 1) {
        pair<int, int> q = {x, y - 1};
        if (cultivated.find(q) != cultivated.end()) {
            if (!visited[q]) dfs(q);
        }
    }
    if (y < C) {
        pair<int, int> q = {x, y + 1};
        if (cultivated.find(q) != cultivated.end()) {
            if (!visited[q]) dfs(q);
        }
    }

}


void solve() {
    int N;
    cin >> R >> C >> N;

    range(i, 0, N) {
        int x, y;
        cin >> x >> y;
        pair<int, int> p = {x, y};
        cultivated.insert(p);
        visited[p] = false;
    }
    int mx = 0;
    for (pair<int, int> p: cultivated) {
        if (!visited[p]) {
            ans = 0;
            dfs(p);
            mx = max(mx, ans);
        }
    }
    
    cout << mx << endl;

}

int32_t main() {


//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);


    int T = 1;

//    cin >> T;

    while (T--) {
        solve();

    }

}
