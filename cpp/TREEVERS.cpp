#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
//#define mod 1000000007
#define MIN_INT -21374836486346565
#define index(c) (((int) c) - 65)
#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

bool compare(pair<int, int> p, pair<int, int> q){
    return p.second * q.first < p.first * q.second;
}


int A[100000];

array<int, 2> counts[100000];
int inversion = 0;
void dfs(vector<int> adj[], int cur, int par){
    int ones = 0, zeroes = 0;
    int s = adj[cur].size() - 1;
    if (cur == 0) s++;
    pair<int, int> pp[s];
    int idx = 0;
    for(int nb: adj[cur]){
        if (nb == par) continue;

        dfs(adj, nb, cur);

        zeroes += counts[nb][0];
        ones += counts[nb][1];
        pp[idx++] = make_pair(counts[nb][0], counts[nb][1]);
    }

    if (A[cur] == 0) counts[cur][0] = zeroes + 1, counts[cur][1] = ones;
    else counts[cur][0] = zeroes, counts[cur][1] = ones + 1;

    sort(pp, pp + s, compare);
    if (A[cur] == 1) inversion += zeroes;
    range(i, 0, s){
        zeroes -= pp[i].first;
        inversion += (pp[i].second * zeroes);
    }


//    cout << cur + 1 << ' ' << inversion << endl;

}






void solve() {
//    pair<int, int> pp[2] = {{1, 0}, {0, 1}};
//    sort(pp, pp + 2, compare)


    int N;
    cin >> N;
    range(i, 0, N) cin >> A[i];
    vector<int> adj[N];
    int a, b;

    range(i, 0, N - 1) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    inversion = 0;
    dfs(adj, 0, 0);
    cout << inversion << endl;
//    range(i, 0, N){
//        cout << counts[i][0] << ' ' << counts[i][1] << endl;
//    }




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
