#include <iostream>
using namespace std;

int main() {
    int T, N; 
    cin >> T;
    while(T > 0){
        cin >> N;
        int array[10];
        int cnt = 0;
        while (N > 0){
            array[cnt] = N % 10;
            N /= 10;
            cnt++;
        }
        bool put_zero = false;
        for(int i = 0; i < cnt; i++){
            if (array[i] != 0){
                put_zero = true;
                cout << array[i];
            }
            else{
                if (put_zero){
                    cout << array[i];
                }
            }
            
        }
        cout << endl;
        T--;
    }
	return 0;
}
