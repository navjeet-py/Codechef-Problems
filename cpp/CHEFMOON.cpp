#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define MIN_INT -21374836486346565
#define MAX_INT 21374836486346565
#define index(c) (((int) c) - 97)
#define int long long
#define in(a) int a; cin >> a;

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}



void solve() {

    int N, M, K;
    cin >> N >> M >> K;
    int distance[N][N];
    range(i, 0, N)
        range(j, 0, N) {
            if (i == j) distance[i][j] = 0;
            else distance[i][j] = MAX_INT;
    }
    range(i, 0, M){
        int a, b, d;
        cin >> a >> b >> d;
        a--; b--;
        distance[a][b] = min(distance[a][b], d);
        distance[b][a] = min(distance[b][a], d);
    }

    range(k, 0, N){
        range(i, 0, N){
            range(j, 0, N){
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

//    range(i, 0, N){
//        range(j, i, N){
//            cout << i+1 << ' ' << j+1 << " ==> " << distance[i][j] << endl;
//        }
//    }

    int Q;
    cin >> Q;
    range(i, 0, Q){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (distance[a][b] <= K){
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }


}

int32_t main() {



    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("planting.in", "r", stdin);
//    freopen("planting.out", "w", stdout);


    int T = 1;

//    cin >> T;


    while (T--) {
        solve();

    }

    return 0;
}
