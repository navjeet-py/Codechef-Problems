#include<iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define rep(i,a,b) for(int i = a; i < b; i++);
int solve(int coords[], int N){
    sort(coords, coords + N);
    if (N % 2 == 1){
        return 1;
    }else{
        return (coords[N / 2] - coords[N / 2 - 1] + 1);
    }
}


int main() {
    int T, N, x, y;
    int X[1001], Y[1001];
    cin >> T;
    while(T--){
        cin >> N;
        for (int i = 0; i < N; i++){
            cin >> x >> y;
            X[i] = x;
            Y[i] = y;
        }
        cout <<(ll)solve(X, N) * solve(Y, N) << '\n';
    }
}