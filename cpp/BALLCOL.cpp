#include <iostream>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;
#define range(i, a, b) for(long long int  i = a; i < b; i++)


int main() {

    int N, M;
    long long int  x, u;
    cin >> N >> M;
    long long int X[N];
    multiset<long long int> Y;
    range(i, 0, N){
        cin >> x >> u;
        X[i] = x * u;
    }
    range(i, 0, M){
        cin >> x >> u;
        Y.insert(x * u);
    }
    int cnt = 0;
    for(long long int p : X){
        if (Y.find(p) != Y.end()){
            cnt++;
            Y.erase(Y.find(p));
        }
    }
    cout << cnt << endl;
    return 0;

}