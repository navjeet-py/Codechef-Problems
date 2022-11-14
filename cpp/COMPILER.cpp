#include <iostream>

typedef long long ll;
#define range(i, a, b) for(i = a; i < b; i++)
using namespace std;

int i, j, k;

int main() {
    int T, N;
    string S;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        cin >> S;
        N = S.length();
        int open = 0, close = 0;
        int ans = 0;
        range(i, 0, N) {

            if (S[i] == '>') {
                close++;
            } else {
                open++;
            }
            if (open < close) {
                break;
            }else if (open == close){
                ans = i + 1;
            }
//            cout << open << ' ' << close << endl;
        }
        cout << ans << endl;

    }
    return 0;
}
