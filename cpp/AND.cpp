#include <iostream>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;
#define range(i, a, b) for(long long int  i = a; i < b; i++)


int main() {

    long long int  N;
    cin >> N;
    long long int  arr[N];
    range(i, 0, N) cin >> arr[i];
    long long int  mx = 0;
    range(i, 0, N) mx = max(mx, arr[i]);
    long long int  p = 1;
    long long int  answer = 0;
    while(p <= mx){
        long long int  ones = 0;
        for(long long int  k : arr){
            if (k & p) ones++;
        }
        answer += (((ones*(ones - 1)) / 2 ) * p);
        p = p << 1;
//        cout << answer << endl;
    }
    cout << answer << endl;



    return 0;

}