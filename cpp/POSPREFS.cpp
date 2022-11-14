#include <iostream>

using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)

void print_array(int arr[], int N) {
    range(i, 0, N) cout << arr[i] << ' ';
    cout << endl;
}

int main() {

    int T, N, K;
    cin >> T;
    while(T--){
        cin >> N >> K;
        int cnt = min(K, N - K);
        int arr[N];
        range(i, 0, N) {
            if (cnt > 0 && i % 2 == 0){
                arr[i] = -(i + 1);
                cnt--;
            }else{
                arr[i] = i + 1;
            }
        }
        
        if (min(K, N - K) == K){
            range(i, 0, N) arr[i] = arr[i] * (-1);
        }
        print_array(arr, N);
    }

    return 0;
}