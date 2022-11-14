#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    

    int T, N;
    cin >> T;
    for(int test_case = 0; test_case < T; test_case++){
        cin >> N;
        int speedRightNow = 2147483647;
        int cnt = 0;
        int a;
        for (int i = 0; i < N; i++){
            cin >> a;
            if (a <= speedRightNow){
                cnt++;
                speedRightNow = a;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}