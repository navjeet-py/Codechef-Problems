#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N){
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int main(){

    int T;
    cin >> T;
    char next, last;
    string S;
    while (T--){
        cin >> S;
        set<pair<char, char>> st;
        range(i, 0, S.length() - 1){
            st.insert(make_pair(S[i], S[i+1]));
        }
        int cnt = 0;
        for(auto p: st){
            cnt += 1;
        }
        cout << cnt << endl;
    }


    return 0;
}