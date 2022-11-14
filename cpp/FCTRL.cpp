#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int T, N;
    cin >> T;
    while (T--){
        cin >> N;
        int ans = 0;
        long long int pow = 5;
        while(pow <= N){
            ans += (N / pow);
            pow *= 5;
        }
        cout << ans << endl;
    }
    return 0;
}