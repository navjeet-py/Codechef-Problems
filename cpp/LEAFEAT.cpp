#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
#define mod 1e9 + 7
#define MIN_INT -2147483648
#define int long long
#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return ((a * b)/gcd(a, b));
}


void solve() {
    int N;
    int K;
    cin >> N >> K;

    N--;
    set<int> st;
    int a;
    range(i, 0, K) {
        cin >> a;
        st.insert(a);
    }
    K = st.size();
    int lengths[K];
    int i = 0;
    for (int kk: st) {
        lengths[i] = kk;
        i++;
    }
    int r;
    r = 1 << K;
    int ans = 0;
    range(p, 1, r) {
        i = r / 2;
        int idx = K - 1;
        int cnt = 0;
        int total = 1;
        while (i > 0) {
//            cout << i << ' ' << total << endl;
            if (i & p) {
                total = lcm(total, lengths[idx]);
                cnt++;
            }
            idx--;
            i = i / 2;
            if (total > N) break;
        }
//        cout << p << ' ' << total << endl;
        if (cnt % 2 == 0) {
            ans -= (N / total);
        } else {
            ans += (N / total);
        }
//        cout << "################################" << endl;
    }
    cout << N - ans << endl;


}


int32_t main() {


    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
