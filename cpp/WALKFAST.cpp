#include <iostream>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;
#define range(i, a, b) for(long long int  i = a; i < b; i++)


int main() {
    int T, N, A, B, C, D, P, Q, Y;
    cin >> T;
    while(T--){
        cin >> N >> A >> B >> C >> D >> P >> Q >> Y;
        int X[N];
        range(i, 0, N) cin >> X[i];
        int direct = abs(X[B - 1] - X[A - 1]) * P;
        int byTrain = 0;
        int time_to_reach_C = abs(X[C - 1] - X[A - 1]) * P;
        if (time_to_reach_C > Y) cout << direct << endl;
        else{
            byTrain = Y + abs(X[D - 1] - X[B - 1]) * P + Q * abs(X[C - 1] - X[D - 1]);
            cout << min(direct, byTrain) << endl;
        }

    }
    return 0;

}