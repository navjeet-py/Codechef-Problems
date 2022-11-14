#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1e9 + 7

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}





void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> adj[N];
    int a, b;
    range(i, 0, M){
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    int S, T;
    cin >> S >> T;
    S--; T--;
    int layers[N];
    range(i, 0, N) layers[i] = -1;
    layers[S] = 0;
    queue<int> q;
    q.push(S);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int nb: adj[cur]){
            if (layers[nb] == -1){
                q.push(nb);
                layers[nb] = layers[cur] + 1;
            }
        }
    }
    if (layers[T] == -1) {
        cout << 0 << endl;
    }else{
        cout << layers[T] << endl;
    }



}


int main() {

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
