#include <iostream>
#include <string>

using namespace std;

int i, j, k;

int main() {
    int T, N;
    int leftA, leftB, scoreA, scoreB;
    string S;
    bool won;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        won = false;
        cin >> N;
        cin >> S;
        leftA = N;
        leftB = N;
        scoreA = 0;
        scoreB = 0;
        for (int i = 0; i < 2 * N; i++) {
            if (!won){
                if (i % 2 == 0) {
                    leftA--;
                    if (S[i] == '1') {
                        scoreA++;
                    }
                }else{
                    leftB--;
                    if (S[i] == '1'){
                        scoreB++;
                    }
                }
                if (leftB + scoreB < scoreA){
                    cout << i + 1 << endl;
                    won = true;
                    break;
                }else if(leftA + scoreA < scoreB){
                    cout << i + 1 << endl;
                    won = true;
                    break;
                }
            }


        }
        if (!won){
            cout << 2*N << endl;
        }
    }
    return 0;
}
