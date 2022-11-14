#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int main() {

    int T;
    string S;
    cin >> T;
    while (T--) {
        cin >> S;
        char a = S[0];
        char b = S[1];
        bool poss = true;
        if (a == b) poss = false;
        if (poss){
            for (int i = 0; i < S.length(); i += 2) {
                if (S[i] != a) {
                    poss = false;
                    break;
                }
            }
        }
        
        if (poss){
            for (int i = 1; i < S.length(); i += 2) {
                if (S[i] != b) {
                    poss = false;
                    break;
                }
            }
        }
        if (poss) cout << "YES" << endl;
        else cout << "NO" << endl;


    }


    return 0;
}