#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N; 
    cin >> N;
    long long int prices[N];
    for(int i = 0; i < N; i++){
        cin >> prices[i];
    }
    sort(prices, prices + N);
    long long int mx = 0;
    for(int i = 0; i < N; i++){
        mx = max(mx, prices[i] * (N - i));
    }
    cout << mx << endl;
    return 0;
}