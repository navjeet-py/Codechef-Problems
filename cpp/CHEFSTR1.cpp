#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int T,N, got, current;
    long long int result;
    cin >> T;
    while (T--){
        cin >> N;

        result = 0;
        cin >> current;
        for (int i = 0; i < N -1; i++){

            cin >> got;
            result += abs(got - current);
            result--;
            current = got;
        }
        cout << result << endl;
    }
}
