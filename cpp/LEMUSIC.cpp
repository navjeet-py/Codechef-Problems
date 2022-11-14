#include <iostream>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;
#define range(i, a, b) for(long long int  i = a; i < b; i++)


int main() {
    long long int T, N, b, l;
    cin >> T;
    while (T--) {
        cin >> N;
        map<int, vector<int>> mp;
        range(i, 0, N){
            cin >> b >> l;
            mp[b].push_back(l);
        }
        vector<int> different;
        vector<int> left;
        for(auto it: mp){
            auto vi = it.second;
            sort(vi.begin(), vi.end());
            different.push_back(vi[0]);
            range(i, 1, vi.size()){
                left.push_back(vi[i]);
            }
        }
        sort(different.begin(), different.end());
        long long int answer = 0;
        long long int i = 1;
        for(long long int p : different){
            answer += (p * i);
            i++;
        }
        i--;
        for(long long int p:left){
            answer += (p * i);
        }
        cout << answer << endl;

    }
    return 0;

}