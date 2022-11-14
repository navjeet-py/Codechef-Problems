#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N){
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}


vector<int> *adj;


void solve(){


    int N, M, Q;
    cin >> N >> M >> Q;

    adj = new vector<int> [N];
    range(i, 0, M){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int time = 0;
    vector<pair<int, int>> query_3; // node, time
    int freezing_time[N];
    range(i, 0, N) freezing_time[i] = -1;

    queue<int> q;
    range(alpha, 0, Q){
        int type, x;
        cin >> type >> x;
        x--;
        if (type == 3){
            if (freezing_time[x] != -1){
                cout << "YES\n";
            }else cout << "NO\n";
            continue;
        }
        if (type == 1){
            if (freezing_time[x] == -1 || freezing_time[x] > time)  {
                freezing_time[x] = time;
                q.push(x);
            }
            continue;
        }

        int forward = x + 1;
        while(!q.empty()){
            forward--;
            time++;
            int s = q.size();
            while(s--){
                int node = q.front();
                q.pop();
                for(int nb: adj[node]){
                    if (freezing_time[nb] == -1 || freezing_time[nb] > freezing_time[node] + 1){
                        freezing_time[nb] = freezing_time[node] + 1;
                        q.push(nb);
                    }
                }
            }
            if (forward == 0){
                break;
            }
        }
    }

//    for (auto q: query_3){
//        int node = q.first;
//        int t = q.second;
//        if (freezing_time[node] == -1) cout << "NO\n";
//        else if (freezing_time[node] <= t) cout << "YES\n";
//        else cout << "NO\n";
//    }
}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

//    cin >> T;

    while(T--){
        solve();
    }


    return 0;
}