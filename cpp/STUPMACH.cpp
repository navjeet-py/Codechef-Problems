#include <iostream>

typedef long long ll;
#define range(i, a, b) for(i = a; i < b; i++)
using namespace std;

int i, j, k;

int main() {
    int T, N;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        cin >> N;
        int S[N];
        range(i, 0, N){
            cin >> S[i];
        }
        int mx = 1e18;
        ll total = 0;
        range(i, 0, N){
            if (S[i] > mx){
                total += (ll)mx;
            }else{
                mx = S[i];
                total += (ll)S[i];
            }
        }
        cout << total << endl;

    }
    return 0;
}
