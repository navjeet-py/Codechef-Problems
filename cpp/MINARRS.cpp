#include <iostream>
using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)

long long int mx_array(long long int A[], int N) {
    long long int mx = 0;
    range(i, 0, N) mx = max(mx, A[i]);
    return mx;
}

int main(){

    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        long long int A[N];
        range(i, 0, N) cin >> A[i];
        long long int i = 1;
        long long int mx = mx_array(A, N);
        long long int ans = 0;
        while (i <= mx){
            long long int cnt = 0;
            for (long long int p:A){
                if ((p & i) != 0){
                    cnt++;
                }
            }
            ans += (i * min(cnt, N - cnt));
            i = i << 1;
        }
        cout << ans << endl;

    }

    return 0;
}