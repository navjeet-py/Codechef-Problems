#include <iostream>
#include "bits/stdc++.h"

using namespace std;

#define range(i, a, b) for(int (i) = a; (i) < (b); (i)++)
#define int long long
#define mod 1000000007
#define print(x) cout << (x) << endl

void construct_segment_tree_min(vector<int> &segtree,
                                vector<int> &a, int n) {
    for (int i = 0; i < n; i++)
        segtree[n + i] = a[i];

    for (int i = n - 1; i >= 1; i--)
        segtree[i] = min(segtree[2 * i],
                         segtree[2 * i + 1]);
}

int range_query_min(vector<int> &segtree, int left, int right, int n) {
    left += n;
    right += n;
    int mi = (int) 1e9;

    while (left < right) {

        if (left & 1) {
            mi = min(mi, segtree[left]);
            left++;
        }

        if (right & 1) {
            right--;

            mi = min(mi, segtree[right]);
        }

        left /= 2;
        right /= 2;
    }
    return mi;
}

void construct_segment_tree_max(vector<int> &segtree,
                                vector<int> &a, int n) {
    for (int i = 0; i < n; i++)
        segtree[n + i] = a[i];
    for (int i = n - 1; i >= 1; i--)
        segtree[i] = max(segtree[2 * i],
                         segtree[2 * i + 1]);
}

int range_query_max(vector<int> &segtree, int left, int
right,
                    int n) {
    left += n;
    right += n;
    int ma = INT_MIN;
    while (left < right) {
        if (left & 1) {
            ma = max(ma, segtree[left]);
            left++;
        }
        if (right & 1) {
            right--;
            ma = max(ma, segtree[right]);
        }
        left /= 2;
        right /= 2;
    }
    return ma;
}

// TREE OF 11 edges 11 1 2 1 3 1 4 2 5 3 6 6 9 3 7 7 10 7 11 4 8


void print_array(int A[], int N) {
    range(i, 0, N) cout << A[i] << ' ';
    cout << '\n';
}

int N;
vector<int> start;
vector<int> finish;
vector<int> segtree_max, segtree_min;

int start_max(int l, int r) {
//    int mx = start[l];
//    for (int i = l; i <= r; i++) {
//        mx = max(mx, start[i]);
//    }
//    return mx;
    return range_query_max(segtree_max, l, r + 1, N);

}

int finish_min(int l, int r) {
//    int mn = finish[l];
//    for (int i = l; i <= r; i++) {
//        mn = min(mn, finish[i]);
//    }
//    return mn;

    return range_query_min(segtree_min, l, r + 1, N);
}

bool check(int x) {

    for (int i = 0; i < N; i++) {
        int j = i + x - 1;
        if (j >= N) return false;
        if (finish[i] - start[i] + 1 >= x && finish[j] - start[j] + 1 >= x) {
            if (j > i && finish[i + 1] - start[i + 1] + 1 < x) continue;
            int common_start = start_max(i, j);
            int common_finish = finish_min(i, j);
            if (common_finish - common_start + 1 >= x) return true;
        }
    }
}

void solve() {

    cin >> N;
    start.resize(N);
    finish.resize(N);
    range(i, 0, N) {
        cin >> start[i] >> finish[i];
    }

    segtree_min.resize(2 * N);
    construct_segment_tree_min(segtree_min, finish, N);

    segtree_max.resize(2 * N);
    construct_segment_tree_max(segtree_max, start, N);


    int l = 1, r = N;
    int ans = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

//    cin >> T;

    while (T--) {
        solve();
    }


    return 0;
}
