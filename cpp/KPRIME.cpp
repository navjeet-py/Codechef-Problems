#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define range(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N){
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

void sieve(int cnt[], int N){
    range(i, 1, N) cnt[i] = 0;
    range(i, 2, N){
        if (cnt[i] == 0){
            for(int j = i; j < N; j += i){
                cnt[j]++;
            }
        }
    }
}

int main(){
    int cnt[100001];
    int N = 100001;
    sieve(cnt, N);

    static int prefix[5][100001];
    range(i, 0, 5) prefix[i][0] = 0;
    range(i, 1, N){
        range(j, 0, 5) {
            prefix[j][i] = prefix[j][i - 1];
        }
        if (0 < cnt[i] && cnt[i] <= 5){
            prefix[cnt[i] - 1][i]++;
        }
    }

//    range(i, 0, 5){
//        range(j, 0, 100){
//            cout << prefix[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
    int T, A, B, K;
    cin >> T;
    while(T--){
        cin >> A >> B >> K;
        cout << prefix[K - 1][B] - prefix[K - 1][A - 1] << endl;
    }


    return 0;
}