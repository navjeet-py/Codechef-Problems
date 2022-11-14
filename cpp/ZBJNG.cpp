#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;
ll mod = 1e9 + 7;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

void layerwise(vector<int> adj[], long double probability[], int distance[]){
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int node = q.front();
        q.pop();
        int Nedges = adj[node].size();
        if (node != 0) Nedges--;
        for(int p: adj[node]){
            if (distance[p] == -1){
                q.push(p);
                probability[p] = probability[node] / ((long double) Nedges);
                distance[p] = distance[node] + 1;
            }

        }
    }
}
void solve() {
    int N;
    cin >> N;
    int A[N], B[N];
    int a, b;
    range(i, 0, N){
        cin >> a >> b;
        A[i] = a + b;
        B[i] = a;
    }

    range(i, 0, N){
        range(j, 0, N){
            if (A[i] == B[j] && B[i] == A[j]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;

}

int main() {


    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
