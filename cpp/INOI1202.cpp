#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
void printArray(int array[], int n){
    for (int i = 0; i < n ; i ++){
        cout << array[i] << ' ' ;
    }
    cout << endl;
}
void printVector(vector <int> v1){
    for (int i : v1){
        cout << i << ' ';
    }
    cout << endl;
}
vector<int> calculateCurrentMax(const int array[], int K, int N){
    vector<int> secondArr;
    for (int i = K; i <= N; i++){
        secondArr.push_back(i);
    }
    for (int i = 1; i < K; i++){
        secondArr.push_back(i);
    }
    int mxIdx = 0;
    int mx = 0;
    for (int i = 0; i < N; i++){
        if (array[i] + secondArr[i] > mx){
            mx = array[i] + secondArr[i];
            mxIdx = i;
        }
    }
    static vector<int> returnArr;
    returnArr.clear();
    returnArr.push_back(mxIdx);
    returnArr.push_back(mx);
    return returnArr;
}

int main() {
    int N, input;
    cin >> N;
    int mainArr[N];
    int resultArr[N];
    int mx = 0;
    for (int i = 0; i < N; i++){
        cin >> input;
        mainArr[i] = input;
        mx = max(input + i + 1, mx);
    }
    resultArr[0] = mx;
    for (int i = 0; i < N - 1; i++){
        mx = max(mainArr[i] + N, mx - 1);
        resultArr[N-i-1] = mx;
    }
    printArray(resultArr, N);

}
