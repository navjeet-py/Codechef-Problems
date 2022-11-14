#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    int N;
    while(T--){
        cin >> N;
        if (N==1){
            cout << 1 << endl;
        }else{
           for (int i = 0; i < N; i++){
               if ( i % 2 != 0){
                   for (int j = 1; j <= N; j++){
                       cout << N * i + j << " ";
                   }
               }else{
                   for (int j = 1; j <= N; j++){
                       cout << N * (i+1) - j + 1 << " ";
                   }
               }
               cout << endl;
           }
        }
    }
}
