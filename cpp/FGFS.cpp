#include <iostream>
#include <cmath>
#include <bits/stdc++.h>


using namespace std;
#define range(i, a, b) for(int  i = a; i < b; i++)


int main() {
    int T, N, K, s, p, f;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        map<int, vector<pair<int, int>>> compartments;

        range(i, 0, N) {
            cin >> s >> f >> p;
            compartments[p].push_back(make_pair(f,s));
        }
        int answer = 0;
        for(auto it:compartments){
            auto vi = it.second;
            sort(vi.begin(), vi.end());
            int k = 0;
            int filled_till = 0;
            for(auto m : vi){
                if (m.second >= filled_till){
                    k++;
                    filled_till = m.first;
                }
            }
            answer += k;
        }
        cout << answer << endl;


    }
    return 0;

}