#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define print(x) cout << x << endl
#define pb push_back
#define vi vector<int>
//#define mod 1000000007
#define MIN_INT -21374836486346565
#define index(c) (((int) c) - 65)
#define int long long

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8

#define range(i, a, b) for(int i = a; i < b; i++)


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

bool isPower(int P){
    int i = 1;
    range(p, 0, 40){
        if (P == i) return true;
        i *= 2;
    }
    return false;
}


void solve() {

    int N;
    cin >> N;
    int first ;
    cin >> first;
    set<pair<int, int>> st;
    int a;
    range(i, 2, N + 1){
        cin >> a;
        st.insert(make_pair(a, i));
    }

    vector<tuple<int, int, int>> printing;
    range(i, 0, N - 1){
        auto it = st.begin();
        int idx = (*it).second;
        int val = (*it).first;

        if (val <= first){
            first += val;
            printing.emplace_back(idx, 1, val);
            st.erase(it);
        }
        else if (i < N - 2){
            auto nxt = st.begin();
            nxt++;
            int nxtIdx = (*nxt).second;
            int nxtVal = (*nxt).first;
            printing.emplace_back(idx, nxtIdx, val - first);
            printing.emplace_back(idx, 1, first);
            st.erase(nxt);
            st.erase(it);
            st.insert(make_pair(nxtVal + val - first, nxtIdx));
            first += first;
        }
        else{
            cout << -1 << endl;
            return;
        }
        it++;
    }

    cout << printing.size() << endl;
    for(auto pp: printing){
        cout << (get<0>(pp)) << ' ' << get<1>(pp) << ' ' << get<2>(pp) << endl;
    }





}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("mooyomooyo.in", "r", stdin);
//    freopen("mooyomooyo.out", "w", stdout);

    int T = 1;

    cin >> T;


    while (T--) {
        solve();

    }

    return 0;
}
