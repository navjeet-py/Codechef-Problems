#include <iostream>
using namespace std;
#include <unordered_map>
#include <algorithm>



int main() {
    int T;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string N;
    cin >> T;
    while(T--){
        cin >> N;

        unordered_map<int, int >first;
        unordered_map<int, int >second;
        for (int i = 0; i < 26; i++){
            first[i] = 0;
            second[i] = 0;
        }
        for(int i = 0; i < N.length()/2; i++){
            first[alpha.find(N[i])] += 1;
        }
        for(int i = (N.length() + 1)/2; i < N.length(); i++){
            second[alpha.find(N[i])] += 1;
        }
        string possible = "YES";
        for (auto & itr : first){
            if (second[itr.first] != itr.second){
                possible = "NO";
            }
        }
        cout << possible << endl;

    }

}
