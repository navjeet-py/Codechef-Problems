#include <iostream>
#include <cmath>
using namespace std;
void printArray(int array[], int n){
    for (int i = 0; i < n ; i ++){
        cout << array[i] << ' ' ;
    }
    cout << endl;
}

int main() {
    int N, K, a;
    cin >> N >> K;
    int mainArr[N], forward[N], backward[N];

    for(int i = 0; i < N; i++){
        cin >> a;
        mainArr[i] = a;
        backward[i] = 0;
        forward[i] = 0;
    }
    backward[0] = mainArr[0];
    backward[1] = mainArr[1] + mainArr[0];

    for (int i = 2; i < N; i++){
        backward[i] = max(backward[i-1], backward[i-2]) + mainArr[i];
    }
    if (K < N){
        forward[K] = mainArr[K];
    }
    for (int i = K + 1; i < N; i++){
        forward[i] = max(forward[i-1], forward[i-2]) + mainArr[i];
    }
    int ans = forward[K-1] + backward[K-1] - mainArr[K-1];
    for (int i = K-1; i < N; i++){
        ans = max(ans, forward[i] + backward[i] - mainArr[i]);
    }
    cout << ans << endl;

}
