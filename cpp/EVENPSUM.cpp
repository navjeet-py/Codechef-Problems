#include <iostream>

using namespace std;
int main() {

    long long int T, A, B;
    cin >> T;
    while (T--) {
        cin >> A >> B;
        cout << ((A + 1) / 2) * ((B + 1) / 2) + (A / 2) * (B / 2) << endl;
    }


    return 0;
}