#include <iostream>
using namespace std;

int i, j, k;

int main() {
    int T, N;
    int s, p, v;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++){
        cin >> N;
        int mx = 0;
        for (i = 0; i < N; i++){
            cin >> s >> p >> v;
            s++;
            if ((p / s) * v > mx){
                mx = (p / s) * v;
            }
        }
        cout << mx << endl;
    }
    return 0;
}
