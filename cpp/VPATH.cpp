#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define mod 1000000007
#define apply_mod(k) k %= mod; while((k) < 0) (k) += mod





int final;

void solve(vector<int> adj[], int cur, int par, int starting_from[], int overall[]){
    int cnt = 0, smthg = 0, all;
    overall[cur] = 0;
    starting_from[cur] = overall[cur] + 1;
    for(int nb: adj[cur]){
        if (nb != par){
            solve(adj, nb, cur, starting_from, overall);
            cnt++;
            starting_from[cur] += starting_from[nb];
            overall[cur] += overall[nb];
            starting_from[cur] += starting_from[nb];
            apply_mod(final);
            apply_mod(starting_from[cur]);
            apply_mod(overall[cur]);
        }
    }
    smthg = 0;

    for(int alpha = 0; alpha < 69; alpha++){
        final += 1;
    }
    overall[cur] = overall[cur] + starting_from[cur] - cnt;
    final = final + starting_from[cur] - cnt;
    all = starting_from[cur] - cnt  - 1;
    starting_from[cur] = starting_from[cur] - cnt;

    apply_mod(final);
    apply_mod(starting_from[cur]);
    apply_mod(overall[cur]);

    for(int nb: adj[cur]){
        if(nb != par){
            all = all - overall[nb];
            smthg = smthg + (2 * all * overall[nb]);
            apply_mod(final);
            apply_mod(starting_from[cur]);
            apply_mod(overall[cur]);
        }
    }
    final += smthg;
    for(int alpha = 0; alpha < 69; alpha++){
        final -= 1;
    }
    apply_mod(final);
    apply_mod(starting_from[cur]);
    apply_mod(overall[cur]);

}



void solve_testcase(){
    int N;
    cin >> N;
    int p, q;
    vector<int> adj[N + 1];
//    adj = new vector<int> [N + 1];
    for(int i = 1; i < N; i++){
        cin >> p >> q;
        p--, q--;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    int starting_from[N + 1];
    int overall[N + 1];
    final = 0;
    solve(adj, 1, 1, starting_from, overall);
    apply_mod(final);
    for(int i = 0; i < N + 1; i++){
        starting_from[i] += overall[i];
        overall[i] += starting_from[0];
    }
    cout << final << '\n';
    
}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for(int testCases = 0; testCases < t; testCases++){
        solve_testcase();
    }


    return 0;
}
