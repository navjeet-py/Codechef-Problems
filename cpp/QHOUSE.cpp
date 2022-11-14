#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define el cout << '\n'
#define mod 1000000007
#define print(x) cout << (x) << endl


// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

int find_side(){
    int l = 0, r = 1000;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        cout << "? " << mid << " 0\n";
        string res;
        cin >> res;
        if (res == "YES") {
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return ans;
}

int find_height(){
    int l = 0, r = 1000;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        cout << "? 0 " << mid << '\n';
        string res;
        cin >> res;
        if (res == "YES") {
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return ans;
}

int find_width(int d){

    int l = 0, r = 1000;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        cout << "? " << mid << " "<< d << "\n";
        string res;
        cin >> res;
        if (res == "YES") {
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return ans;


}

void solve() {
    int d = find_side();
    int h = find_height();
    int w = find_width(2 * d);
    int area = d * d * 4 + w * (h - 2 * d);
    cout << "! " << area << '\n';

}


int32_t main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    int T = 1;

//    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
