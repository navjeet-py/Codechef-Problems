#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define range(i, a, b) for(long long i = a; i < b; i++)
typedef long long ll;

void print_array(int A[], int N){
    range(i, 0, N) cout << A[i] << ' ';
    cout << endl;
}

int main(){
    long long T, N;
    cin >> T;
    while(T--){
        cin >> N;
        long long array[N];
        range(i, 0, N) cin >> array[i];
        map<long long int, long long int> gcds;
        gcds[array[0]] = 1;
        long long cnt = 0;
        if (array[0] == 1) cnt++;
        range(i, 1, N){
            map<long long int, long long int> temp;
            for(auto p: gcds){
                long long g = __gcd(p.first, array[i]);
                if (g == 1){
                    cnt += p.second;
                }
                temp[g] = temp[g] + p.second;
            }
            gcds[array[i]] = gcds[array[i]] + 1;
            for(auto p: temp){
                gcds[p.first] = gcds[p.first] + p.second;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}