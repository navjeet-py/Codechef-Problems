#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int array[], int n) {
    for (int kkk = 0; kkk < n; kkk++) cout << array[kkk] << ' ';
    cout << endl;
}
void solve(){
    ll R, C;
    cin >> R >> C;
    cout << R * C << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--){
        solve();
    }


    return 0;
}
