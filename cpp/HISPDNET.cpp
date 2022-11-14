#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -2147483648
#define index(c) (((int) c) - 97)
//#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}


int parent[2001];

int find(int n) {
    if (parent[n] == n)
        return n;

    return parent[n] = find(parent[n]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) parent[b] = a;
    else parent[a] = b;
}




void solve() {
    int N;
    cin >> N;
    int M = ((N - 1) * (N - 2))/2;
    array<int, 3> edges[M];
    int a, b, cost;
    int idx = 0;
    range(i, 0, N){
        range(j, 0, N){
            cin >> cost;
            if (i > 0 && j > 0 && i < j){
                edges[idx][1] = i - 1, edges[idx][2] = j - 1, edges[idx][0] = cost;
                idx ++;
            }
        }
    }

    sort(edges, edges + M);
//    for (auto it:edges){
//        cout << it[0] << ' ' << it[1] << ' ' << it[2] << endl;
//    }
    range(i, 0, N) parent[i] = i;
    int cnt = 0;
    idx = 0;
    int total_cost = 0;
    while (cnt < N - 2){
        a = edges[idx][1], b = edges[idx][2], cost = edges[idx][0];
        a = find(a), b = find(b);
        if (a == b) idx++;
        else{
            parent[a] = b;
            idx++;
            cnt++;
            total_cost += cost;
        }
    }
    cout << total_cost << endl;







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