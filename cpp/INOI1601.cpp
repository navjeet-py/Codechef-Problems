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
void printVector(vector<vector <int>> v1){
    for (vector<int> i : v1){
        for (int p : i){
            cout << p << ' ';
        }
        cout << endl;
    }
}

int main() {
    int N, input;
    cin >> N;
    int salary[N], bap[N];
    vector<int> betas[N];
    int head = 0;
    for (int i = 0; i < N; i++){
        cin >> input;
        salary[i] = input;
    }
    for (int i = 0; i < N; i++){
        cin >> input;
        bap[i] = input - 1;
        if (input == -1){
            head = i;
        }
        else{
            betas[input-1].push_back(i);
        }
    }
    int ln;
    vector<vector<int>> levelWise;
    vector<int> ini;
    ini.push_back(head);
    levelWise.push_back(ini);
    int count = 1;
    while (count != N){
        ln = levelWise.size();
        ini = levelWise[ln-1];
        vector<int> alpha;
        for (int i : ini){
            vector<int> betasCurrent = betas[i];
            for (int j : betasCurrent){
               alpha.push_back(j);
               count++;
            }
        }
        levelWise.push_back(alpha);
    }

    int final[N];
    for (int i = 0; i < N; i++){
        final[i] = 1000000000;
    }

    ln = levelWise.size();
    for (int i = ln - 1; i >= 0; i--){
        vector<int> levelCurrent = levelWise[i];
        for (int p : levelCurrent){
            vector<int> childCurrent = betas[p];
            int mn = 1000000000;
            for (int k: childCurrent){
                mn = min(mn, salary[k]);
                mn = min(mn, final[k]);
            }
            final[p] = mn;
        }
    }
    int ans = -100000000;
    for (int i = 0; i < N; i++){
        ans = max(ans, salary[i] - final[i]);
    }
    cout << ans <<endl;
}
