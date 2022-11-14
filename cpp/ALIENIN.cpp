#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int T, N;
    long long int D;
    cin >> T;
    while(T--){
        cin >> N >> D;
        cout<<setprecision(6)<<fixed;
        long long int array[N];
        for (int i = 0; i < N; i++){
            cin >> array[i];
        }
        sort(array, array + N);
        long double start = 0, end = 2000000001, mid = 0;
        while (start < end){
            mid = (start + end) / 2;
            long double last = array[0];
            bool poss = true;
            for (int i = 1; i < N; i++){
                if (array[i] + D >= last + mid){
                    last = max((long double) array[i], last + mid);

                }else{
                    poss = false;
                    break;
                }
            }
//            cout << mid << ' ' << poss << endl;
            if (poss){
                start = mid + 1e-7;
            }
            else{
                end = mid - 1e-7;
            }
//            cout << start << ' ' << end << endl;
        }
        cout << mid << endl;

    }
}