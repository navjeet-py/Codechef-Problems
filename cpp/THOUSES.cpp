#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

#define ll long long
#define pb push_back
#define all(a) ((a).begin(), (a).end())
#define modulo 1000000007

static vector<ll > *adj;
static ll *dp;



void dfs_dp(ll current, ll parent) {
    vector<ll > subtrees;
    dp[current] = 1;

    for (ll neighbor: adj[current]) {
        if (neighbor == parent) continue;
        dfs_dp(neighbor, current);
        subtrees.pb(dp[neighbor]);
    }

    if (subtrees.empty()) return;

    sort all(subtrees);
    ll l = (ll ) subtrees.size();
    for(ll i = 0; i < l; i++){
        dp[current] += ((l - i) * subtrees[i]);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    for (ll testCase = 0; testCase < T; testCase++) {
        ll N, X;
        cin >> N >> X;
//        cout << "YO" << endl;
        adj = new vector<ll > [N];
//        cout << "YO" << endl;

        dp = new ll [N];
        for (ll _ = 0; _ < N - 1; _++) {
            ll p, q;
            cin >> p >> q;
            p--, q--;
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
//        cout << "YO" << testCase << endl;
        dfs_dp(0, 0);

        cout << (((dp[0] % modulo) * X) % modulo) << '\n';


    }

    return 0;
}
