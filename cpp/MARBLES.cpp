#include <iostream>
#include <bits/stdc++.h>
#include <vector>

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
long long int C(int n, int k){
    long long int result = 1;
    int p = max(k, n-k);
    int j = 1;
    for (int i = n; i > p; i--){
        result*=i;
        result /= j;
        j++;
    }
    return result;
}
int main()
{
    int t, p, q;
    cin >> t;
    while(t--){
        cin >> p >> q;
        cout << C(p-1, q-1) << endl;
    }
    return 0;
}